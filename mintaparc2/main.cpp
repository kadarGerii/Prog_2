#include "H\fun.h"

void bfs(int u, int szin[], std::vector<int> adjList[], std::vector<int> adjList1[], int m, int lehetosegek, int n) {
    int *q = new int[m];
    szin[u] = 1;
    q[0] = u;
    int head = 0, rear = 0;
    int k = 0;
    while (k < lehetosegek) {
        while (head < m) {
            int u1 = q[head];
            std::cout << u1 + 1 << " ";
            for (int i = 0; i < adjList[u1].size(); ++i) {
                int v = adjList[u1][i];
                if (!szin[v]) {
                    szin[v] = 1;
                    q[++rear] = v;
                }
            }
            ++head;
        }
        head = 0;
        rear = 0;
        for (int i = 0; i < m; ++i) {
            szin[i] = 0;
        }
        ++k;
        for (int i = 0; i < m; ++i) {
            if (adjList1[i].size() > 1) {
                std::swap(adjList[i][0], adjList[i][1]);
            }
        }
        std::cout << std::endl;
        szin[u] = 1;
    }
}

int main() {
    std::ifstream f;
    f.open("graf.txt");
    if (!f) {
        printf("Error!\n");
        exit(-1);
    }
    int n, m;
    f >> m >> n;
    std::vector<int> adjList[m];
    std::vector<int> adjList1[m];
    int szin[5] = {0};
    for (int i = 0; i < n; ++i) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        adjList[x].push_back(y);
        adjList1[x].push_back(y);
        adjList[y].push_back(x);
    }

    int lehetosegek = 0;
    for (int i = 0; i < m; ++i) {
        if (adjList1[i].size() > 1)
            lehetosegek += adjList1[i].size();
    }
    /*for (int i = 0; i < m; ++i) {
        for (int j = 0; j < adjList1[i].size(); ++j) {
            std::cout << adjList1[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    std::cout << lehetosegek << " db lehetoseg:" << std::endl;
    /*for (int i = 0; i < lehetosegek; ++i) {
        bfs(0, szin, adjList, n, 2);
        for (int j = 0; j < n; ++j) {
            szin[j] = 0;
        }
        std::cout << std::endl;
    }*/
    bfs(0, szin, adjList, adjList1, m, 2, n);
    return 0;
}