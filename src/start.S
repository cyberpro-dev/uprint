// start.S
.global _start
_start:
    bl main
    // syscall exit with main's return value
    mov x8, 93      // exit syscall number
    mov x0, x0      // exit code (return value from main)
    svc 0
