#include <stdio.h>


void add4();
void func1(); // this function contains examples form lecture 06
void func2(); // this function contains examples from lecture 07

int main()
{
    func2();
}

void func2() {

    // compute: z = x/y, r = x % y
    int x = 50;     //mov x, 0x000A
    int y = 12;     //mov y, 0x0014
    int z, r;
    

    // optimizing here, we perform one ALU operation and get the both results
    // compiler would have done the ALU operation twice
    __asm {
            xor edx, edx
            xor eax, eax
            mov eax, x
            div y
            mov z, eax
            mov r, edx
    }

    printf("qoutient: %d, rem: %d\n", z, r);

    int a, b, c, d;
    // a=x+y, b=a-y, c=b*y, d=c/y
    // the compiler blindly translates these instrucitons and there are lots of redundant mov instrucions
    
    __asm {
            mov eax, x
            add eax, y
            mov a, eax
            sub eax, y
            mov b, eax
            mul y
            mov c, eax
            div y
            mov d, eax
    }

    printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);


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