//
// Created by Administrator on 2023-03-02.
//

#include "../Headers/functions.h"
int szamElofordulas(int n, int x){
    if(n==0)
        return 0;
    if(n % 10 == x)
        return 1 + szamElofordulas(n/10, x);
    else
        return szamElofordulas(n / 10, x);
}
int sum = 0, rem;
int reverse_function(int num){
    if(num){
        rem=num%10;
        sum=sum*10+rem;
        reverse_function(num/10);
    }
    else
        return sum;
    return sum;
}
bool palindrome(int n){
    if(n == reverse_function(n))
        return true;
    return false;
}
bool binary(int n){
    if(n == 0){
        return true;
    }
    if(n % 10 == 0 || n % 10 == 1)
        return binary(n/10);
    return false;
}
bool ascending(int n){
    if(n == 0)
        return true;
    if(n % 10 > (n/10) % 10)
        return ascending(n/10);
    return false;
}
int lnko(int x, int y){
    if(x == 0)
        return y;
    return lnko(y % x, y);
}
int temp, e = 10;
int tenToB(int n, int b){
    if(n == 0)
        return 0;
    return n % b + 10 * tenToB(n/10, b);
}