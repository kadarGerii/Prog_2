//
// Created by Administrator on 2023-04-27.
//

#include "../Headers/backtrack_functions.h"
void feladat1(int n, int index, char*d, char *s){
    if(n == index){
        return;
    }
    for (int i = 0; i < strlen(d); ++i) {
        if (index == 0 || d[i] > s[index - 1]) {
            s[index] = d[i];
            feladat1(n, index + 1, d, s);
            printf("%s ", s);
        }
    }
}
void feladat2(char *betuk, char *s, int index) {
    if (index == 5) {
        printf("%s\n", s);
        return;
    }

    for (int i = 0; i < strlen(betuk); ++i) {
        s[index] = betuk[i];
        feladat2(betuk, s, index + 1);
    }
}
int sum(int n) {
    int ossz = 0;
    while (n != 0) {
        ossz += n % 10;
        n = n / 10;
    }
    return ossz;
}

void feladat3(int n, int ossz, int szam, int index) {
    if (index == n) {
        if (sum(szam) < ossz) {
            printf("%d\n", szam);
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        feladat3(n, ossz, szam * 10 + i, index + 1);
    }
}
void kiirZaszlo(int i){
    switch(i){
        case 0:
            printf("feher ");
        break;
        case 1:
            printf("fekete ");
        break;
        case 2:
            printf("piros ");
        break;
        case 3:
            printf("kek ");
        break;
        case 4:
            printf("zold ");
        break;
        case 5:
            printf("sarga ");
        break;
    }
}
void feladat4(){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < 6; ++k) {
                if (k == i || k == j) {
                    continue;
                }
                if (j == feher || j == fekete) {
                    kiirZaszlo(i);
                    printf(" ");
                    kiirZaszlo(j);
                    printf(" ");
                    kiirZaszlo(k);
                    printf("\n");
                }
            }
        }

    }
}