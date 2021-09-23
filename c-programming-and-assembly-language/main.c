#include <stdio.h>


void add4();
void func1(); // this function contains examples form lecture 06

int main()
{
    func1();
}

void func1() {

    // evaluate the expression: x*y + a-b
    int x = 2, y = 3, a = 4, b = 5;
    int ans;

    __asm {
        mov eax, x
        mul y
        add eax, a
        sub eax, b
        mov ans, eax
    }

    printf("x: %d, y: %d, a: %d, b: %d\n", x, y, a, b);
    printf("ans: %d\n", ans);


    // evaluate the expression: (x^y) | (a&b)
    x = 1, y = 1, a = 1, b = 0;

    __asm {
        mov ebx, x
        xor ebx, y
        mov ecx, a
        and ecx, b
        or ebx, ecx
        mov ans, ebx
    }

    printf("Answer for boolean expression: %d\n", ans);


    // z = p * q using repeated addition
    short int p = 2, q = 3;
    int z = 0;

    __asm {
            xor eax, eax
            mov cx, q
    loc:    add ax, p
            dec ecx
            jnz loc
            mov z, eax
    }

    printf("Repeated addition: %d\n", z);
}

void add4() {
    
    // add 4 to the integer using inline assembly

    int x = 2;

    // x = x + 4;
    __asm {
        mov eax, x
        add eax, 0x0004
        mov x, eax
    }

    printf("X: %d\n", x);
}