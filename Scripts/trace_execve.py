#!/usr/bin/env python3
from bcc import BPF

b = BPF(src_file="trace_sys_execve.c")

# Attach to the execve syscall
b.attach_kprobe(event="sys_execve", fn_name="trace_execve")

print("Tracing execve() calls... Press Ctrl+C to exit.")
try:
    b.trace_print()
except KeyboardInterrupt:
    print("Detaching...")
