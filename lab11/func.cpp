//
// Created by Administrator on 2023-05-11.
//

#include "func.h"

void orszagok() {
    std::ifstream f;
    f.open("terkep.txt");
    int n;
    f >> n;
    Elek orszag[n];
    int color[n];
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }
    std::vector<int> adjList[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        orszag[i].from = x;
        orszag[i].to = y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjList[i].size(); ++j) {
            if(color[adjList[i][j]]==color[i])
                color[adjList[i][j]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << " " << color[i] << std::endl;
    }
}
int cmp(const void *a, const void  *b){
    Parok *p = (Parok*)a;
    Parok *q = (Parok*)b;
    if(p->chemistry - q->chemistry == 0){
        return p->from - q->from;
    }
    return p->chemistry - q->chemistry;
}
void kiir(int n, Parok parok[]){
    for (int i = 0; i < n; ++i) {
        std::cout<<parok[i].from+1<<" "<<parok[i].to+1<<" "<<parok[i].chemistry<<std::endl;
    }
}
void hazassag() {
    std::ifstream f;
    f.open("hazassag.txt");
    int n,m;
    f>>n;
    f>>m;
    Parok parok[n];
    for (int i = 0; i < n; ++i) {
        int x,y,z;
        f>>x>>y>>z;
        --x;--y;
        parok[i].from = x;
        parok[i].to = y;
        parok[i].chemistry = z;
    }
    qsort(parok, n, sizeof(Parok), cmp);
    //kiir(n, parok);
    int i = 1;
    int *csoport = new int[n];
    for (int j = 0; j < n; ++j)
    {
        csoport[j] =j;
    }
    std::cout << parok[0].from + 1 << " " << parok[0].to + 1 << " " << parok[0].chemistry << std::endl;
    csoport[parok[0].to] = csoport[parok[0].from];
    while(i != m-1){
        if(csoport[parok[i].from] != csoport[parok[i].to]){
            int temp = csoport[parok[i].to];
            for(int j = 0; j < n; ++j){
                if(csoport[j] == temp)
                    csoport[j] = csoport[parok[i].from];
            }
            std::cout << parok[i].from + 1 << " " << parok[i].to + 1 << " " << parok[i].chemistry << std::endl;
        }
        i++;
    }
    std::cout << parok[m-1].from + 1 << " " << parok[m-1].to + 1 << " " << parok[m-1].chemistry << std::endl;
}
