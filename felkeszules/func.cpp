//
// Created by Administrator on 2023-05-10.
//

#include "func.h"
int cmp(const void* a, const void* b){
    int *q = (int*)a;
    int *p = (int*)b;
    return *q-*p;
}
void felvono(){
    //adott n ember
    int a[] = {1, 13, 3, 4, 5, 6, 7, 10, 9, 8, 11, 12, 2, 14, 15};
    qsort(a, 15, sizeof(int), cmp);
    int ido = 0;
    for (int i = 0; i < 14; ++i) {
        ido += 2*a[i];
    }
    std::cout<<"Ossz ido: "<<ido << std::endl;
}
int cmpMusor(const void *a, const void *b){
    Musor *q = (Musor*)a;
    Musor *p = (Musor*)b;
    return q->end - p->end;
}
void musorok() {
    Musor musor[5];
    musor[0] = {1,4};
    musor[1] = {3,4};
    musor[2] = {2,3};
    musor[3] = {4,6};
    musor[4] = {3,5};
    qsort(musor, 5, sizeof(Musor), cmpMusor);
    std::cout<< musor[0].start << " " << musor[0].end << std::endl;
    int v = musor[0].end;
    for (int i = 1; i < 5; ++i) {
        if(musor[i].start >= v){
            std::cout<< musor[i].start << " " << musor[i].end << std::endl;
            v = musor[i].end;
        }
    }
}
int strToInt(std::string city){
    if(city == "\nBacon" || city == "Bacon")
        return 0;
    if(city == "\nBarot" || city == "Barot")
        return 1;
    if(city == "\nKommando" || city == "Kommando")
        return 2;
    if(city == "\nKovaszna" || city == "Kovaszna")
        return 5;
    if(city == "\\nMaros" || city == "Maros")
        return 4;
    if(city == "\nKezdi" || city == "Kezdi")
        return 3;
    if(city == "\nSzorcse" || "Szorcse")
        return 6;
    return 7;
}
std::string intToStr(int x){
    switch (x) {
        case 0:
            return "Bacon";
        case 1: return "Barot";
        case 2: return "Kommando";
        case 3: return "Kezdi";
        case 4: return "Maros";
        case 5: return "Kovaszna";
        case 6: return "Szorcse";
        case 7 : return "Budapest";
        default:return "Nope xd";
    }
}
int cmpKruskal(const void* a, const void* b){
    Elek *p = (Elek *)a;
    Elek *q = (Elek *)b;
    if(p->length > q->length)
        return 1;
    else if(p->length < q->length)
        return -1;
    else return 0;
}
void kruskal(){
    std::ifstream f;
    f.open("graf.txt");
    int n;
    f >> n;
    std::vector<int> adjList[n];
    Elek elek[n];
    for (int i = 0; i < n; ++i) {
        std::string x1,y1;
        int x, y, z;
        char p = ' ';
        getline(f, x1,p);
        getline(f, y1, p);
        //std::cout << x1<<" "<<y1<<std::endl;
        f>>z;
        x = strToInt(x1);
        y = strToInt(y1);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        elek[i].from = x;
        elek[i].to = y;
        elek[i].length = z;
    }
    qsort(elek, n, sizeof(Elek), cmpKruskal);
    int i = 1;
    int *csoport = new int[n];
    for (int j = 0; j < n; ++j)
    {
        csoport[j] =j;
    }
    std::cout << intToStr(elek[0].from) << " " << intToStr(elek[0].to) << " " << elek[0].length << std::endl;
    csoport[elek[0].to] = csoport[elek[0].from];
    while(i != n-1){
        if(csoport[elek[i].from] != csoport[elek[i].to]){
            int temp = csoport[elek[i].to];
            for(int j = 0; j < n; ++j){
                if(csoport[j] == temp)
                    csoport[j] = csoport[elek[i].from];
            }
            std::cout << intToStr(elek[i].from) << " " << intToStr(elek[i].to) << " " << elek[i].length << std::endl;

        }
        i++;
    }
}