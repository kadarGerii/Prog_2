//
// Created by Administrator on 2023-03-09.
//

#include "functions.h"
void hanoiTornya(int k, char s, char d, char h)
{
    if (k == 1){
        printf("\n1 %c %c", s, d);
        return;
    }
    hanoiTornya(k-1, s, d, h);
    printf("\n%d %c %c", k, s, d);
    hanoiTornya(k-1, h, d, s);
}
int maximum(int *t, int i, int j){
    if(i == j)
        return i;
    else{
        int m1 = maximum(t, i, (i+j) / 2);
        int m2 = maximum(t, (i+j) / 2 + 1, j);
        if (t[m1] > t[m2])
            return m1;
        return m2;
    }
}
void merge(int *a, int x, int y, int z){

    int i, j, k;
    int n1 = y - x + 1;
    int n2 = z - y;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[x + i];
    for (j = 0; j < n2; j++)
        R[j] = a[y + 1+ j];
    i = 0;
    j = 0;
    k = x;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *a, int i, int j){
    if(i < j){
        int k = (i+j)/2;
        mergeSort(a, i, k);
        mergeSort(a, k+1, j);
        merge(a, i, k, j);
    }
}
int sum(int a[], int i, int j){
    if(i == j)
        return a[i];
    else{
        int kozep = (i+j)/2;
         int x = sum(a, i, kozep);
         int y = sum(a,kozep+1, j);
         return x+y;
    }
}