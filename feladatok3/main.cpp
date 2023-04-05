#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

bool isPrime(int n, int i);
int primeCount(int n[], int i);
int main() {
    ifstream f;
    f.open("graf.txt");
    int n, m;
    f >> n >> m;
    vector<int> adjList[n];
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        f >> x >> y;
        --x;
        --y;
        adjList[x].push_back(y);
        matrix[x][y] = 1;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1) {
                ++counter;
            }
        }
    }
    counter /= 2;
    cout << "Ketiranyu elek szama: " << counter << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1 && i > j) {
                matrix[i][j] = 0;
            } else if (matrix[i][j] == 1 && matrix[j][i] == 1 && i < j) {
                matrix[j][i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                matrix[j][i] = 1;
            }
        }
    }
    cout << "\nellista:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    cout<<"\n";
    int k[5] = {5,2,6,7,3};
    cout<<primeCount(k, 4);
    return 0;
}

bool isPrime(int n, int i) {
    if (n <= 2)
        return n == 2;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return isPrime(n, i + 1);
}
int primeCount(int n[], int i){
    if(i == -1)
        return 0;
    if(isPrime(n[i],2)){
        return 1 + primeCount(n, i-1);
    }
    return primeCount(n, i-1);
}
