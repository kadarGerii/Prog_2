#include <iostream>
#include <fstream>
#include <cstring>
int cmp(const void *a, const void*b);
void feladat1();
void feladat2();
int main() {
    int x=1;
    while (x != 0) {
        std::cout << "1 - 1. feladat\n"
                     "2 - 2. feladat\n"
                     "0 - Bezar\n";
        std::cin>>x;
        switch(x) {
            case  1:feladat1();
            break;
            case 2 : feladat2();
            break;
            default :x=0;
            break;
        }
    }
    return 0;
}
int cmp(const void*a, const void*b){
    int *p = (int*)a;
    int *q = (int*)b;
    return *q-*p;
}
void feladat1(){
    std::cout << "1. feladat"<<std::endl<<std::endl;
    int n;
    std::ifstream f;
    f.open("halmaz.txt");
    if(!f){
        std::cout<<"Error\n";
        exit(-1);
    }
    f>>n;
    int *halmaz = new int[n];
    std::cout<<"Hasznalhato ertekek: { ";
    for (int i = 0; i < n; i++) {
        f>>halmaz[i];
        std::cout<<halmaz[i] << " ";
    }
    std::cout<<"}"<<std::endl;
    int osszeg;
    std::cout<<"Celosszeg:";std::cin>>osszeg;
    int sum=0;
    qsort(halmaz, n, sizeof(int), cmp);
    int i=0, coin = 0;
    while(true){
        sum += halmaz[i];
        std::cout<<halmaz[i]<<" ";
        coin++;
        if(sum == osszeg){
            std::cout<<"\nSiker! "<<coin<<" db ertekbol!"<<std::endl;
            break;
        }
        if(sum > osszeg){
            sum -= halmaz[i];
            ++i;
            --coin;
            std::cout<<" torolve";
        }
        if(i == n){
            std::cout<<"\nNem lehet kifizetni!"<<std::endl;
            break;
        }
        std::cout<< std::endl;
    }
}
void feladat2(){
    std::cout<<"2. feladat"<<std::endl<<std::endl;
    char *startWord = "hit";
    char *endWord = "cog";
    std::cout<<"Start word: "<<startWord<<std::endl;
    std::cout<<"End word: "<<endWord<<std::endl;
    char szotar[6][6] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int lepes = 0;
    std::cout<<"[ ";
    while (strcmp(startWord, endWord) != 0){
        int counter = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < strlen(szotar[i]); ++j) {
                if (startWord[j] != szotar[i][j]){
                    counter++;
                }
            }
            if (counter == 1) {
                std::cout<<szotar[i] << " ";
                startWord = szotar[i];
                lepes++;
            }
            counter = 0;
        }
    }
    std::cout<<"]"<<std::endl;
    std::cout<<lepes<<" lepesbol"<<std::endl;
}