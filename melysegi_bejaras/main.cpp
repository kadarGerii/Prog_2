#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void bejaras(int u, int szin[], vector<int> szomszedsagiLista[]);
int main()
{
    ifstream fin("graf.txt");
    int n,m;
    fin >> n >> m;
    vector <int> szomszedsagiLista[n];
    int *szin = (int*)calloc(n,sizeof(int));
    for( int i = 0 ; i < m ; ++i ){
        int x, y;
        fin >> x >> y;
        --x;
        --y;
        szomszedsagiLista[x].push_back(y);
        szomszedsagiLista[y].push_back(x);
    }
    for(int i = 0; i < n; ++i){
        if(szin[i] == 0){
            bejaras(i, szin, szomszedsagiLista);
        }
    }
    fin.close();
    return 0;
}

void bejaras(int u, int szin[], vector<int> szomszedsagiLista[]){
    szin[u] = 1;
    cout << u+1 << ' ';
    for(int j = 0 ; j < szomszedsagiLista[u].size() ; ++j ){
        int v = szomszedsagiLista[u][j];
        if ( !szin[v] ){
            bejaras(v, szin, szomszedsagiLista);
        }
    }
}
