//
// Created by Administrator on 2023-02-24.
//

#include "func.h"
void fromOneToN(int n, int i){
    if(n == 0)
        return;
    printf("%d ", i);
    fromOneToN(n-1, i+1);
}
int sumOfNum(int n){
    if(n == 0)
        return 0;
    return n % 10 + sumOfNum(n-1);
}
int evenNum(int n, int i){
    if(n == 0)
        return i;
    if(n % 2 == 0){
        return evenNum(n / 10, i + 1);
    }
    else return evenNum(n / 10, i);
}
int minimum(int n, int i){
    if(n == 0)
        return i;
    if(n % 10 < i){
        i = n % 10;
        return minimum(n / 10, i);
    }
    else return minimum(n/10, i);
}