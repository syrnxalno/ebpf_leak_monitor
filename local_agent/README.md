Requried packages:

a] clang and LLVM to compile C to eBPF
b] libelf-dev for phrasing ELF fies [.o files]
c] libbpf-dev offical libbpf library
d] linux-headers-$(uname -r) for kernel headers

Directory structure:

my-ebpf-project/
├── Makefile
├── vmlinux.h       # auto-generated header (kernel symbols)
├── agent.bpf.c   # eBPF C program
├── my_prog.bpf.o   # compiled eBPF object file (auto-generated)
├── loader.c        # user-space C program (loads eBPF)
├── README. md

Setup commands [Ubuntu/Debian]:

sudo apt update
sudo apt install clang llvm libelf-dev gcc make pkg-config libbpf-dev linux-headers-$(uname -r)
