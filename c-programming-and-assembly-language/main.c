#include <stdio.h>

int main()
{
    int x = 2;
    
    // x = x + 4;
    __asm {
        mov eax, x
        add eax, 0x0004
        mov x, eax
    }

    printf("X: %d\n", x);
}