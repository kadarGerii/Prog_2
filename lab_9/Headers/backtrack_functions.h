//
// Created by Administrator on 2023-04-27.
//

#ifndef LAB_9_BACKTRACK_FUNCTIONS_H
#define LAB_9_BACKTRACK_FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum color{
    feher,
    fekete,
    piros,
    kek,
    zold,
    sarga
};
void feladat1(int n, int index, char*d, char*s);
void feladat2(char *betuk, char *s, int index);
void feladat3(int n, int sum, int szam, int index);
int sum(int n);
void kiirZaszlo(int i);
void feladat4();
#endif //LAB_9_BACKTRACK_FUNCTIONS_H
