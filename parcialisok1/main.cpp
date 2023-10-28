#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

struct Elek {
    int from, to;
};
void bfs(int u, int szin[], std::vector<int> adjList[], int n, int suly[]) {
    int sum = 0;
    int *q = new int[n];
    szin[u] = 1;
    q[0] = u;
    int k = 0;
    int head = 0, rear = 0;
    while (head < n) {
        int u1 = q[head];
        std::cout<<suly[u1]<<" + ";
        sum+=suly[u1];
        for (int i = 0; i < adjList[u1].size(); ++i) {
            int v = adjList[u1][i];
            if (!szin[v]) {
                szin[v] = 1;
                q[++rear] = v;
            }
        }
        ++head;
    }
    std::cout<<" = "<<sum<<std::endl;
    std::cout<<"q = [ ";
    for (int i = n-1; i >= 0; --i) {
        std::cout<<q[i]+1<<" ";
    }
    std::cout << "]\n";
}

void kombinacio(int x[], int n, int p, int k) {
    if (k == p) {
        std::cout << "{ ";
        for (int i = 1; i <= k; ++i) {
            std::cout << x[i] << " ";
        }
        std::cout <<"}"<< std::endl;
    } else {
        for (x[k + 1] = x[k] + 1; x[k + 1] < n; x[k + 1]++) {
            kombinacio(x, n, p, k + 1);
        }
    }
}

void reszhalmaz(int halmaz[], int n) {
    std::cout<<"{}\n";
    for (int p = 1; p < n; ++p) {
        kombinacio(halmaz, n, p, 0);
    }
}
int max(int a[],int n);
int main() {
    std::ifstream f;
    f.open("graf.txt");
    if (!f) {
        printf("Error!\n");
        exit(-1);
    }
    int n, m;
    f >> m >> n;
    Elek *elek = new Elek[n];
    std::vector<int> adjList[m];
    for (int i = 0; i < n; ++i) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        elek[i].from = x;
        elek[i].to = y;
    }
    /*for (int i = 0; i < n; ++i) {
        std::cout << elek[i].from+1 << " " << elek[i].to+1 << std::endl;
    }*/
    int *suly = new int[m];
    for (int i = 0; i < m; ++i) {
        int x,y;
        f>>x>>y;
        suly[i] = y;
        //std::cout << suly[i]<<" "<<std::endl;
    }
    int k = 3;
    int *szin = new int[k-1];
    for (int i = 0; i < k; i++) {
        szin[i] = 0;
    }
    int start = max(suly, m);
    //std::cout <<start+1<<std::endl;
    bfs(start, szin, adjList, k, suly);
    //reszhalmazos feladat
    /*int n = 5;
    int x[] = {0, 1, 2, 3, 4, 5};
    reszhalmaz(x, n);*/
    return 0;
}
int max(int *a, int n) {
    int max = a[0], pos=0;
    for(int i = 1; i < n; ++i){
        if(a[i]>max){
            max=a[i];
            pos=i;
        }
    }
    return pos;
}