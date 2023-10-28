#include <iostream>
#include <fstream>

struct Elek {
    int from, to, length;
};

int cmp(const void *a, const void *b);

int cmp2(const void *a, const void *b);

void feladat1();

int main() {
    feladat1();
    return 0;
}

void feladat1() {
    std::ifstream f;
    f.open("graf.txt");
    int n, m, p;
    f >> n >> m >> p;
    //std::cout<<n<<" "<<m<<" "<<p << std::endl;
    Elek elek[n];
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        f >> x >> y >> z;
        --x;
        --y;
        elek[i].from = x;
        elek[i].to = y;
        elek[i].length = z;
    }
    qsort(elek, n, sizeof(Elek), cmp);
    int i = 1;
    int k =1;
    int *csoport = new int[n];
    for (int j = 0; j < n; ++j) {
        csoport[j] = j;
    }
    Elek a[n-1];
    //std::cout << elek[0].from + 1 << " " << elek[0].to + 1 << " " << elek[0].length << std::endl;
    csoport[elek[0].to] = csoport[elek[0].from];
    a[0].from = elek[0].from;
    a[0].to = elek[0].to;
    a[0].length = elek[0].length;
    while (i != n - 1) {
        if (csoport[elek[i].from] != csoport[elek[i].to]) {
            int temp = csoport[elek[i].to];
            for (int j = 0; j < n; ++j) {
                if (csoport[j] == temp)
                    csoport[j] = csoport[elek[i].from];
            }
            //std::cout << elek[i].from + 1 << " " << elek[i].to + 1 << " " << elek[i].length << std::endl;
            a[k].from = elek[i].from;
            a[k].to = elek[i].to;
            a[k].length = elek[i].length;
            ++k;
        }
        i++;
    }
    qsort(a, n - 1, sizeof(Elek), cmp2);
    int szuper = 0, sum = 0;
    for (int j = 0; j < n - 1; j++) {
        sum += a[j].length;
        std::cout << a[j].from + 1 << " " << a[j].to + 1 << " " << a[j].length << std::endl;
    }
    k = 0;
    while (sum > p) {
        a[k].length = 1;
        szuper ++;
        for (int j = 0; j < n - 1; j++) {
            sum += a[j].length;
        }
        ++k;
        sum = 0;
    }
    std::cout << "\nSzuper ut " << szuper << std::endl;
}

int cmp(const void *a, const void *b) {
    Elek *p = (Elek *) a;
    Elek *q = (Elek *) b;
    return p->length - q->length;
}

int cmp2(const void *a, const void *b) {
    Elek *p = (Elek *) a;
    Elek *q = (Elek *) b;
    return p->length - q->length;
}