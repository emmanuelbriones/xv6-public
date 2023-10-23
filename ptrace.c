#include "types.h"
#include "user.h"
#include "syscall.h"
#include "ptrace.h"

int ptrace(int mask) {
    if (mask == 0){
        printf(2, "ptrace failed\n");
        return 0;
    }
    // Tracing logic goes here
    else {
        printf(2, "Mask: %d\n", mask);
        return mask;
    }
}

int call_to_mask(const char *syscall_name) {
    int mask = 0; // Initialize the mask to 0

    // Map the syscall name to the corresponding syscall number (mask) using a switch statement
    if (strcmp(syscall_name, "fork") == 0) {
        mask = SYS_fork;
    } else if (strcmp(syscall_name, "exit") == 0) {
        mask = SYS_exit;
    } else if (strcmp(syscall_name, "wait") == 0) {
        mask = SYS_wait;
    } else if (strcmp(syscall_name, "pipe") == 0) {
        mask = SYS_pipe;
    } else if (strcmp(syscall_name, "read") == 0) {
        mask = SYS_read;
    }else if (strcmp(syscall_name, "kill") == 0) {
        mask = SYS_kill;
    }else if (strcmp(syscall_name, "exec") == 0) {
        mask = SYS_exec;
    }else if (strcmp(syscall_name, "fstat") == 0) {
        mask = SYS_fstat;
    }else if (strcmp(syscall_name, "chdir") == 0) {
        mask = SYS_chdir;
    }else if (strcmp(syscall_name, "dup") == 0) {
        mask = SYS_dup;
    }else if (strcmp(syscall_name, "getpid") == 0) {
        mask = SYS_getpid;
    }else if (strcmp(syscall_name, "sbrk") == 0) {
        mask = SYS_sbrk;
    }else if (strcmp(syscall_name, "sleep") == 0) {
        mask = SYS_sleep;
    }else if (strcmp(syscall_name, "uptime") == 0) {
        mask = SYS_uptime;
    }else if (strcmp(syscall_name, "open") == 0) {
        mask = SYS_open;
    }else if (strcmp(syscall_name, "write") == 0) {
        mask = SYS_write;
    }else if (strcmp(syscall_name, "mknod") == 0) {
        mask = SYS_mknod;
    }else if (strcmp(syscall_name, "unlink") == 0) {
        mask = SYS_unlink;
    }else if (strcmp(syscall_name, "link") == 0) {
        mask = SYS_link;
    }else if (strcmp(syscall_name, "mkdir") == 0) {
        mask = SYS_mkdir;
    }else if (strcmp(syscall_name, "close") == 0) {
        mask = SYS_close;
    }else{
         printf(2, "Sys call does not exist\n");
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
