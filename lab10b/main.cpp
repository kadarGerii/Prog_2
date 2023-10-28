#include <iostream>
#include <vector>
#include "functions.h"
#include <fstream>

int main() {
    std::ifstream f;
    f.open("graf.txt");
    int n;
    f >> n;
    std::vector<int> adjList[n];
    Elek elek[n];
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        f >> x >> y >> z;
        --x;
        --y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        elek[i].from = x;
        elek[i].to = y;
        elek[i].length = z;
    }
    qsort(elek, n, sizeof(Elek), cmp);
    int i = 1;
    int *csoport = new int[n];
    for (int j = 0; j < n; ++j)
    {
        csoport[j] =j;
    }
    std::cout << elek[0].from + 1 << " " << elek[0].to + 1 << " " << elek[0].length << std::endl;
    csoport[elek[0].to] = csoport[elek[0].from];
    while(i != n){
        if(csoport[elek[i].from] != csoport[elek[i].to]){
            int temp = csoport[elek[i].to];
            for(int j = 0; j < n; ++j){
                if(csoport[j] == temp)
                    csoport[j] = csoport[elek[i].from];
            }
            std::cout << elek[i].from + 1 << " " << elek[i].to + 1 << " " << elek[i].length << std::endl;

        }
        i++;
    }
    return 0;
}
