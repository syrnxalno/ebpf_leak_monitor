CLANG ?= clang
CC ?= gcc
CFLAGS = -g -Wall

all: agent.bpf.o loader

agent.bpf.o: agent.bpf.c vmlinux.h
	$(CLANG) -target bpf -g -O2 -c $< -o $@

loader: loader.c
	$(CC) $(CFLAGS) -o $@ $^ -lbpf -lelf -lz

clean:
	rm -f agent.bpf.o loader
