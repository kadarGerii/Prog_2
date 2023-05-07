//
// Created by Administrator on 2023-05-04.
//

#include "functions.h"

int cmp(const void *a, const void *b) {
    Elek *p = (Elek *)a;
    Elek *q = (Elek *)b;
    if(p->length > q->length)
        return 1;
    else if(p->length < q->length)
        return -1;
    else return 0;
}
bool igeretes(int x[], int n){
    for(int i = 0; i < n-1; ++i){
        if (x[i] != x[i+1]) {
            return false;
        }
    }
    return true;
}
