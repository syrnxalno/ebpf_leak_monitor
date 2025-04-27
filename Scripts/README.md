## Test eBPF scripts to checkout bcc functionality
### Environment :
This setup was tested in a lightweight **Multipass VM** with an Ubuntu 22.04 LTS image

### Components (temporary until further updates) :
1. `trace_sys_execve.c`: simple eBPF test program that traces `execve()` calls.
2. `trace_execve.py`: loader to load and attaches the eBPF program

### Setup : 
1. ```sudo apt install -y bpfcc-tools linux-headers-$(uname -r) python3-bpfcc``` - required dependencies for bcc 
2. ```chmod +x trace_execve.py``` - permit the python loader to run
3. ```sudo ./trace_execve.py``` - run it
   
### Expected Output :
```Tracing execve() calls... Press Ctrl+C to exit.```
