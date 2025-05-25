// start.S
// Use of this software is governed by the terms in the EULA file.
.global _start
_start:
    bl main
    // syscall exit with main's return value
    mov x8, 93      // exit syscall number
    mov x0, x0      // exit code (return value from main)
    svc 0
