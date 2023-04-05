#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
void menet(int start, vector<int> szL[], int visited[], int apa[]){
    visited[start] = 1;
    cout<<apa[start] + 1<<" ";
    for(int i=0; i<szL[start].size();++i){
        int v = szL[start][i];
        if(!visited[v]){
            if(v % 2 != start % 2){
                apa[v] = start;
                menet(v, szL, visited,apa);
            }
        }
    }
}

int* stat(string s, int i, int betu[]){
    if(i == s.length()){
        return betu;
    }
    betu[s[i]-'a']++;
    return stat(s, i+1, betu);
}

int main() {
    ifstream f;
    f.open("graf.txt");
    int n, m;
    f>>n>>m;
    vector<int>szL[n];
    int *apa = (int*)calloc(n, sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) {
        int x,y;
        f>>x>>y;
        --x;--y;
        szL[x].push_back(y);
        szL[y].push_back(x);
    }
    //menet(0, szL, visited,apa);
    int *betu = (int*)calloc('z'-'a', sizeof(int));
    stat("kadarakos", 0, betu);
    for (char i = 'a'; i < 'z'; i++) {
        cout<<i<<" "<<betu[i-'a']<<endl;
    }
    return 0;
}
