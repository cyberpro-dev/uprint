#include "uprint.h"

int main() {
    uprint(1, "Hello stdout!\n");
    uprint(0, "Warning on stderr!\n");
    long len = uprint(2, "No output, just length.\n");
    // Use len if needed
    return 0;
}
