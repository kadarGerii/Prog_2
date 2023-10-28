#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
void bfs(int u, vector<int>szL[], int szin[], int n){
    int *q = new int[n];
    q[0] = u;
    szin[u] = 1;
    int head=0,rear=0;
    while (head<=rear) {
        int u1 = q[head];
        cout<<u1 + 1<<" ";
        for(int j = 0; j < szL[u1].size(); ++j){
            int v = szL[u1][j];
            if(!szin[v]){
                szin[v] = 1;
                q[++rear] = v;
            }
        }++head;
    }
}
void bfsrovidut(int u, vector<int>szL[], int szin[], int n, int apa[], int dist[]){
    int *q = new int[n];
    q[0] = u;
    dist[u] = 0; apa[u] = -1;
    szin[u] = 1;
    int head=0,rear=0;
    while (head<=rear) {
        int u1 = q[head];
        cout<<u1 + 1<<" ";
        for(int j = 0; j < szL[u1].size(); ++j){
            int v = szL[u1][j];
            if(!szin[v]){
                szin[v] = 1;
                dist[v] = u+1;
                apa[v] = u;
                q[++rear] = v;
            }
        }++head;
    }
}
void legrovidebbut( int u , int apa[]){
    if( apa[u] != -1 ) {
        legrovidebbut( apa[u] , apa);
    }
    cout << u+1 << ' ';
}
int main() {
    ifstream f;
    f.open("graf.txt");
    int n,m;
    f>>n>>m;
    int *apa = (int*) malloc(n*sizeof(int));
    int *dist = (int*) malloc(n*sizeof(int));
    vector<int>szL[n];
    int *szin = (int*)calloc(n,sizeof(int));
    for(int i=0; i < m; i++){
        int x,y;
        f>>x>>y;
        --x;--y;
        szL[x].push_back(y);
        szL[y].push_back(x);
    }
    //bfs(0, szL, szin, n);
    bfsrovidut(4, szL, szin, n, apa, dist);
    printf("\n");
    cout << "Legrovidebb utak:\n";
    for( int i = 0 ; i < n ; ++i ){
        legrovidebbut(i, apa);
        cout << endl;
    }
    return 0;
}
