//
// Created by Administrator on 2023-02-20.
//

#include "Exercises.h"
int factorial(int n){
    if (n>=1)
        return n*factorial(n-1);
    else
        return -1;
}
int lnko(int a, int b){
    if(b>a)
        return lnko(b,a);
    if(b==0)
        return a;
    else
        return lnko(b,a%b);
}
int power(int x, int n){
    if(n == 0)
        return 1;
    else{
        return x * power(x, n-1);
    }
}
int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int number(int n){
    if(n/10 > 0)
    return n % 10 * number(n/10);
}
void arrayReverse(int n, int* array){
    if (n <= 0)
        return;
    printf("%d ", array[n - 1]);
    arrayReverse(n - 1, array);
}
int sumOfArray(int n, int* array){
    if(n <= 0)
        return 0;
    return array[n-1] + sumOfArray(n-1, array);
}
int maxValue(int n, int i, int* array){
    if(i + 1 == n)
        return array[i];
    int maximum = maxValue(n, i + 1, array);
    return array[i] > maximum ? array[i] : maximum;
}
int evenInArray(int n, int* array, int sum){
    if(n <= 0)
        return sum;
    if(array[n-1] % 2 == 0){
        return evenInArray(n-1, array, sum+1);
    }
    return evenInArray(n-1, array, sum);
}
int prime(int x){
    if(x <= 0)
        return 0;
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;
    if(x % 2 == 0)
        return 0;
    for(int i = 3; i*i < x; ++i){
        if(x % i == 0)
            return 0;
    }
    return 1;
}
int primeInArray(int n, int* array, int sum){
    if(n <= 0)
        return sum - 1;
    if(prime(array[n-1]))
        return primeInArray(n-1, array, sum+1);
    return primeInArray(n-1, array, sum);
}