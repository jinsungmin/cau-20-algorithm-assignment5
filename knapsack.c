#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int weight[6] = { 6,10,3,5,1,3 };
int value[6] = { 60,20,12,80,30,60 };
int a[6] = { 1,2,3,4,5,6 };
int ratio[6];

void swap(int* x, int* y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void sort() {
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);
                swap(&value[j], &value[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }
}
void main()
{
    
    int i, j;
    int n  = 6;
    int capacity = 16;
    int pt, x[6];
   
    
    for (i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    sort();

    pt = 0;
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            pt = pt + value[i];
            capacity = capacity - weight[i];
            printf("item(%d,%d) [%d]\n", weight[i], value[i], ratio[i]);
        }   
    }
    printf("maximum profit is %d", pt);
    
    return 0;
}