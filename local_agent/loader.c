#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bpf/libbpf.h>
#include <bpf/bpf.h>

#include "agent.skel.h"   // include the auto-generated skeleton (important)

int main()
{
    struct agent_bpf *skel;
    struct bpf_link *link;
    int err;

    // Open and load BPF application
    skel = agent_bpf__open_and_load();
    if (!skel) {
        fprintf(stderr, "Failed to open and load BPF object\n");
        return 1;
    }

    // Attach tracepoint
    link = bpf_program__attach_tracepoint(skel->progs.handle_execve, "syscalls", "sys_enter_execve");
    if (!link) {
        fprintf(stderr, "Failed to attach tracepoint\n");
        return 1;
    }

    printf("Successfully started! Press Ctrl+C to stop.\n");
    while (1) {
        sleep(1);
    }

    // Clean up (you can improve this later)
    agent_bpf__destroy(skel);

    return 0;
}
