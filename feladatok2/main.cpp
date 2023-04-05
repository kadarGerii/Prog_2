#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
int szamjOsszeg(int n);
int nagy(int n[], int i, int max, int pos);
int main() {
    ifstream f;
    f.open("graf.txt");
    int n, m;
    f >> n >> m;
    vector<int> iranyitott[n];
    vector<int> iranyitatlan[n];
    int *befokszam = (int *) calloc(n, sizeof(int));
    int *kifokszam = (int *) calloc(n, sizeof(int));
    int *fokszam = (int *) calloc(n, sizeof(int));
    int *visited = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < m; ++i) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        iranyitott[x].push_back(y);
        ++kifokszam[x];
        ++befokszam[y];
        iranyitatlan[x].push_back(y);
        iranyitatlan[y].push_back(x);
        ++fokszam[x];
        ++fokszam[y];
    }
    cout << "\nKi- vagy befokszam megegyezik(1.2):" << endl;
    for (int i = 0; i < n; ++i) {
        if (fokszam[i] == befokszam[i] || fokszam[i] == kifokszam[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (iranyitatlan[i][j] == 1 && fokszam[i] > 1) {
                iranyitatlan[i][j] = 0;
                cout << "Torolt el: " << i + 1 << "-" << j + 1 << endl;
            }
        }
    }
    int asd[5] = {123, 564, 111, 876, 901};
    int max = szamjOsszeg(asd[0]);
    cout<<nagy(asd, 4, max,0);
    return 0;
}
int szamjOsszeg(int n){
    if(n == 0) return 0;
    return n%10 + szamjOsszeg(n/10);
}
int nagy(int n[], int i, int max, int pos){
    if(i == 0)
        return pos;
    if(szamjOsszeg(n[i]) > max){
        max = szamjOsszeg(n[i]);
        pos = n[i];
        return nagy(n, i-1,max, pos);
    }
    return nagy(n,i-1, max, pos);
}