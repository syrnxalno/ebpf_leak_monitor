#include <uapi/linux/ptrace.h>

int trace_execve(struct pt_regs *ctx) {
    bpf_trace_printk("execve() called\\n");
    return 0;
}
