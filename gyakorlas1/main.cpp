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
int main() {
    ifstream f;
    f.open("graf.txt");
    int n,m;
    f>>n>>m;
    vector<int>szL[n];
    int *szin = (int*)calloc(n,sizeof(int));
    for(int i=0; i < m; i++){
        int x,y;
        f>>x>>y;
        --x;--y;
        szL[x].push_back(y);
        szL[y].push_back(x);
    }
    bfs(0, szL, szin, n);
    return 0;
}
