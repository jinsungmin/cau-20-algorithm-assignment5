#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fibo(int num);


int fiboArr[10];
int main(void) {
    int num;
    int i;
   
    while (1) {
        printf("Input Fibonacci Number: ");
        scanf("%d", &num);

        for (i = 1; i <= num; i++) {
            fiboArr[i - 1] = fibo(i);   
        }
        printf("%d\n", fibo(num));

        for (i = 0; i < num; i++) {
            printf("%d ", fiboArr[i]);            
        }

        printf("\n");
    }
    
    
    return 0;
}

int fibo(int num) {

    if (num == 1) {
        fiboArr[num-1] = 1;
        return 1;
    }
    else if (num == 2) {
        fiboArr[num-2] = 1;
        return 1;
    }
    else {
        if (fiboArr[num - 2] != 0) {
            return fiboArr[num - 2] + fiboArr[num - 3];
        }
        return fibo(num - 1) + fibo(num - 2);
    }
}