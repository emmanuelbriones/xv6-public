#include "types.h"
#include "syscall.h"
#include "ptrace.h"
#include "defs.h"

int ptrace(int mask) {
    if (mask == 0){
        cprintf("ptrace failed\n");
        return 0;
    }
    // Tracing logic goes here
    else {
        cprintf("Mask: %d\n", mask);
        return mask;
    }
}

int call_to_mask(const char *syscall_name) {
    int mask = 0; // Initialize the mask to 0

    // Map the syscall name to the corresponding syscall number (mask) using a switch statement
    if (strncmp(syscall_name, "fork", 4) == 0) {
        mask = SYS_fork;
    } else if (strncmp(syscall_name, "exit", 5) == 0) {
        mask = SYS_exit;
    } else if (strncmp(syscall_name, "wait", 5) == 0) {
        mask = SYS_wait;
    } else if (strncmp(syscall_name, "pipe", 5) == 0) {
        mask = SYS_pipe;
    } else if (strncmp(syscall_name, "read", 5) == 0) {
        mask = SYS_read;
    }else if (strncmp(syscall_name, "kill", 5) == 0) {
        mask = SYS_kill;
    }else if (strncmp(syscall_name, "exec", 5) == 0) {
        mask = SYS_exec;
    }else if (strncmp(syscall_name, "fstat", 6) == 0) {
        mask = SYS_fstat;
    }else if (strncmp(syscall_name, "chdir", 6) == 0) {
        mask = SYS_chdir;
    }else if (strncmp(syscall_name, "dup", 4) == 0) {
        mask = SYS_dup;
    }else if (strncmp(syscall_name, "getpid", 7) == 0) {
        mask = SYS_getpid;
    }else if (strncmp(syscall_name, "sbrk", 5) == 0) {
        mask = SYS_sbrk;
    }else if (strncmp(syscall_name, "sleep", 6) == 0) {
        mask = SYS_sleep;
    }else if (strncmp(syscall_name, "uptime", 7) == 0) {
        mask = SYS_uptime;
    }else if (strncmp(syscall_name, "open", 5) == 0) {
        mask = SYS_open;
    }else if (strncmp(syscall_name, "write", 6) == 0) {
        mask = SYS_write;
    }else if (strncmp(syscall_name, "mknod", 6) == 0) {
        mask = SYS_mknod;
    }else if (strncmp(syscall_name, "unlink", 7) == 0) {
        mask = SYS_unlink;
    }else if (strncmp(syscall_name, "link", 5) == 0) {
        mask = SYS_link;
    }else if (strncmp(syscall_name, "mkdir", 6) == 0) {
        mask = SYS_mkdir;
    }else if (strncmp(syscall_name, "close", 6) == 0) {
        mask = SYS_close;
    }else{
        cprintf("sys call does not exist\n");
    }
       
    return mask;
}

int main(int argc, char *argv[])
{
    const char *syscall_name = argv[1];
    int mask = call_to_mask(syscall_name);

    int test = ptrace(mask);

    printf(2, "Test: %d\n", test);

    exit();
}
