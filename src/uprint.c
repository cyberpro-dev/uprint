// Use of this software is governed by the terms in the EULA file.
#include "uprint.h"
typedef unsigned long size_t;

static size_t ustrlen(const char *s) {
    size_t len = 0;
    while (s[len]) len++;
    return len;
}

static long my_syscall(long n, long a1, long a2, long a3) {
    register long x8  __asm__("x8") = n;
    register long x0  __asm__("x0") = a1;
    register long x1  __asm__("x1") = a2;
    register long x2  __asm__("x2") = a3;

    __asm__ volatile ("svc #0"
                      : "+r"(x0)
                      : "r"(x1), "r"(x2), "r"(x8)
                      : "memory");

    return x0;
}

long uprint(int fd, const char *message) {
    size_t len = ustrlen(message);
    if (fd == 2) {
        return (long)len; // print to nowhere (dry-run)
    }
    return my_syscall(64, fd, (long)message, len);
}
