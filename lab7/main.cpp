#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void bfs(int start, int bfsVisited[], vector<int> adjList[], int n);
int main() {

    ifstream f;
    f.open("graf.txt");
    int n, m;
    f>>n>>m;
    cout<<n<<" "<<m<<endl;
    vector<int> adjList[n];
    int *bfsVisited = new int[n];
    for (int i = 0; i < n; i++) {
        bfsVisited[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        int x,y;
        f>>x>>y;
        --x;--y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    bfs(0, bfsVisited, adjList,n);
    f.close();
    return 0;
}
void bfs(int start, int bfsVisited[], vector<int> adjList[],int n){
    int *q = new int[n];
    q[0] = start;
    bfsVisited[start] = 1;
    int head = 0, rear = 0;
    while (head <= rear) {
        int u = q[head];
        cout << u + 1 << ' ';
        for (int j = 0; j < adjList[u].size(); ++j) {
            int v = adjList[u][j];
            if (bfsVisited[v] == 0) {
                bfsVisited[v] = 1;
                q[++rear] = v;
            }
        } ++head;
    }
}