package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

func textHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Only POST method is allowed", http.StatusMethodNotAllowed)
		return
	}
	body, err := io.ReadAll(r.Body)
	if err != nil {
		http.Error(w, "Failed to read body", http.StatusInternalServerError)
		return
	}
	log.Printf("Data received: %s", string(body))
	fmt.Fprintf(w, "Received: %s", string(body))
}

func main() {
	http.HandleFunc("/send", textHandler)
	fmt.Println("Server started at :8080")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
