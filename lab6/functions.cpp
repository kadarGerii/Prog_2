//
// Created by Administrator on 2023-03-23.
//

#include "functions.h"
void fokszamok(){
    std::ifstream fin("graf.txt");
    int n, m;
    fin >> n >> m;
    std::vector<int> list[n];
    int *befokszam = new int[n];
    for (int i = 0; i < n; i++) {
        befokszam[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        int x,y;
        fin>>x>>y;
        --x;
        --y;
        befokszam[y]++;
        list[x].push_back(y);
    }
    std::cout << "kifokszamok:"<<std::endl;
    for(int i = 0; i < n; ++i){
        std::cout<<i+1<<" "<<list[i].size()<<std::endl;
    }
    std::cout << "befokszamok:"<<std::endl;
    for(int i = 0; i < n; ++i){
        std::cout<<i+1<<" "<<befokszam[i]<<std::endl;
    }

}
void teljes(){
    std::ifstream fin("graf.txt");
    int n, m;
    fin >> n >> m;
    std::vector<int> list[n];
    for(int i = 0; i < m; ++i){
        int x,y;
        fin>>x>>y;
        std::cout<<x<<" "<<y<<std::endl;
        --x;
        --y;
        list[x].push_back(y);
        list[y].push_back(x);
    }
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (list[i].size() == n-1) {
            counter++;
            if(counter == n){
                std::cout << "Teljes!"<<std::endl;
                break;
            }
        }
        else{
            std::cout<<"Nem teljes!"<<std::endl;
            break;
        }
    }
}
void izolalt(){
    std::ifstream fin("graf.txt");
    int n, m;
    fin >> n >> m;
    std::vector<int> list[n];
    int *befokszam = new int[n];
    for (int i = 0; i < n; i++) {
        befokszam[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        int x,y;
        fin>>x>>y;
        --x;
        --y;
        befokszam[y]++;
        list[x].push_back(y);
        list[y].push_back(x);
    }
    int izolalt = 0;
    int level = 0;
    for (int i = 0; i < n; ++i) {
        if (list[i].size() == 0) {
            ++izolalt;
        }
        if(list[i].size() == 1){
            ++level;
        }
    }
    std::cout << "Izolalt pontok szama: "<<izolalt<<std::endl;
    std::cout << "Levelek szama szama: "<<level<<std::endl;
}
void komplementer(){
    std::ifstream fin("graf.txt");
    int n, m;
    fin >> n >> m;
    int list[n][n];
    for(int i = 0; i < m; ++i){
        int x,y;
        fin >> x >> y;
        --x;
        --y;
        list[x][y] = 1;
        list[y][x] = 1;
    }
    std::ifstream fin2("graf2.txt");
    fin >> n >> m;
    int list2[n][n];
    for (int i = 0; i < m; ++i) {
        int x,y;
        fin >> x >> y;
        --x;
        --y;
        list[x][y] = 1;
        list[y][x] = 1;
    }
    int sum[n][n];
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            sum[i][j] = list[i][j] + list2[i][j];
            if(i == j){
                sum[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (list[i][j] != 1) {
                return;
            }
        }
    }
    std::cout << "Egymas komplementerei" << std::endl;
}
enum name{
    Elizabeth, Charles, Andrew, Edward, Arme, William, Harry, George, Charlotte
};
void uralkodo() {
    std::ifstream f;
    f.open("uralkodas.txt");
    int n,m;
    f>>n>>m;
    std::string x;
    std::string y;
    std::vector<std::string>list[n];

}