/**
 * What is Bitfield:
 * A bitfield in C is a way to allocate a specific number of bits (not bytes) inside a struct.
 *
 * @param argc
 * @param argv
 * @return
 */
#include <stdio.h>
#include <_stdlib.h>

/**
 * A bitfield in C is a way to allocate a specific number of bits (not bytes) inside a struct.
 * Normally in C we  write as given below:
 * This struct uses 8 bytes, even if you only need 1–2 bits to represent a and b.
 */

typedef struct normal {
    unsigned int a; /* 4 Bytes (32-bits on most system */
    unsigned int b; /* 4 Bytes */
} Normal;

/**
 * With Bitfield, we can tell the compiler that use only N-bits for this filed.
 * And how we do this, given below:
 * Now, instead of wasting 8 bytes, the compiler packs them into 1 byte (or maybe 4, depending on system alignment).
 */

typedef struct bitfields {
    unsigned int a: 3; /* Use only 3-bits */
    unsigned int b: 5; /* Use only 5-bits */
} Bitfields;

typedef struct Flags {
    unsigned int isOn: 1; // needs only 1 bit (0/1)
    unsigned int mode: 2; // needs 2 bits (0–3)
    unsigned int value: 5; // needs 5 bits (0–31)
} Flags;


int main(int argc, char *argv[]) {
    const Flags f = {1, 2, 15};

    printf("isOn = %u\n", f.isOn);
    printf("mode = %u\n", f.mode);
    printf("value = %u\n", f.value);

    printf("Size of the structure normal is = %zu\n", sizeof(Normal));
    printf("Size of the structure bitfields is = %zu\n", sizeof(Bitfields));
    printf("Size of the structure Flags is = %zu\n", sizeof(Flags));

    return EXIT_SUCCESS;
}

/**
* Why use bitfields?
Memory efficiency:
Useful in low-level programming (e.g., firmware, device drivers, protocols).
Example: controlling registers in microcontrollers (where each bit is meaningful).
Readable code:
Instead of doing bitmasks manually, you can write f.isOn = 1; instead of flags |= (1 << 0);.
*/
