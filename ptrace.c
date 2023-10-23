#include "types.h"
#include "user.h"
#include "syscall.h"

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
    switch (syscall_name) {
        case "fork":
            mask = SYS_fork;
            break;
        case "exit":
            mask = SYS_exit;
            break;
        case "wait":
            mask = SYS_wait;
            break;
        case "pipe":
            mask = SYS_pipe;
            break;
        case "read":
            mask = SYS_read;
            break;
        case "kill":
            mask = SYS_kill;
            break;
        case "exec":
            mask = SYS_exec;
            break;
        case "fstat":
            mask = SYS_fstat;
            break;
        case "chdir":
            mask = SYS_chdir;
            break;
        case "dup":
            mask = SYS_dup;
            break;
        case "getpid":
            mask = SYS_getpid;
            break;
        case "sbrk":
            mask = SYS_sbrk;
            break;
        case "sleep":
            mask = SYS_sleep;
            break;
        case "uptime":
            mask = SYS_uptime;
            break;
        case "open":
            mask = SYS_open;
            break;
        case "write":
            mask = SYS_write;
            break;
        case "mknod":
            mask = SYS_mknod;
            break;
        case "unlink":
            mask = SYS_unlink;
            break;
        case "link":
            mask = SYS_link;
            break;
        case "mkdir":
            mask = SYS_mkdir;
            break;
        case "close":
            mask = SYS_close;
            break;
        case "ptrace":
            mask = SYS_ptrace;
            break;
        default:
            // No system call exists
            printf(2, "Unknown syscall: %s\n", syscall_name);
            break;
    }

    return mask;
}

int main(int argc, char *argv[])
{
    const char *syscall_name = argv[1];
    int mask = call_to_mask(syscall_name);

    int test = ptrace(mask);


    exit();
}
