#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

string valatasNevre(int x) {
    switch (x) {
        case 0:
            return "Akos";
        case 1:
            return "Balint";
        case 2:
            return "Geza";
        case 3:
            return "Julia";
        case 4:
            return "Eszter";
        case 5:
            return "Boti";
    }
}

void dfs(int u, vector<int> adjList[], int visited[], int posmin) {
    visited[u] = 1;
    cout << valatasNevre(u) << " ";
    if (u == posmin) {
        return;
    }
    for (int j = 0; j < adjList[u].size(); ++j) {
        int v = adjList[u][j];
        if (!visited[v]) {
            visited[v] = 1;
            dfs(v, adjList, visited, posmin);
        }
    }
}

int osszeg(int n) {
    if (n == 0)
        return 0;
    return n % 10 + osszeg(n / 10);
}

int *stat(int tomb2[], int i, int tomb[]) {
    if (i == -1)
        return tomb2;
    ++tomb2[osszeg(tomb[i])];
    return stat(tomb2, i - 1, tomb);
}

int main() {
    ifstream f;
    f.open("parcialis.txt");
    int n, m;
    f >> n >> m;
    vector<int> adjList[n];
    int *visited = (int *) calloc(n, sizeof(int));
    int *fokszam = (int *) calloc(n, sizeof(int));
    int *apa = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < m; ++i) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        fokszam[x]++;
        fokszam[y]++;
    }
    int max = fokszam[0], min = fokszam[0];
    int pos = 0, posmin = 0;
    for (int i = 1; i < n; ++i) {
        if (fokszam[i] > max) {
            max = fokszam[i];
            pos = i;
        }
        if (fokszam[i] < min) {
            min = fokszam[i];
            posmin = i;
        }
    }
    cout << "Legtobb baratja " << valatasNevre(pos) << "-nek van!" << endl;
    cout << "Legkevesebb baratja " << valatasNevre(posmin) << "-nek van!" << endl;
    dfs(pos, adjList, visited, posmin);
    int *tomb;
    int size;
    cout << "\nTomb merete: ";
    cin >> size;
    tomb = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        cin >> tomb[i];
    }
    int maximum = 0;
    for (int i = 0; i < 4; ++i) {
        if (osszeg(tomb[i]) > maximum) {
            maximum = osszeg(tomb[i]);
        }
    }
    cout << maximum << endl;
    int *tomb2 = (int *) calloc(maximum, sizeof(int));
    stat(tomb2, 4, tomb);
    for (int i = 0; i <= maximum; ++i) {
        cout << i << " " << tomb2[i] << endl;
    }
    return 0;
}