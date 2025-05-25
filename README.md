### Use of this software is governed by the terms in the EULA file.
# uprint

**`uprint`** is a lightweight, zero-lib, syscall-only print library for AArch64.

Perfect for bare-metal C, OS dev, or minimalist Termux builds.

## Features

- Direct syscall printing
- `uprint(fd, msg)` with auto-length
- `fd = 0` → stderr, `1` → stdout, `2` → null
- No libc, no bloat, pure speed

## Usage

```c
#include "uprint.h"
uprint(1, "Hello world!\n");
