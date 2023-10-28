#include <stdio.h>

typedef struct{
    int kezdoPont;
    int vegPont;
}Elek;
int main() {
    FILE *file;
    file.open("pontPontMatrix");
    int csomoPont, el;
    file>>csomoPont;
    file >> el;
    Elek *ElLista = new Elek[el];
    for (int i = 0; i < el; i++) {
        file>>ElLista[i].kezdoPont>>ElLista[i].vegPont;
        cout << ElLista[i].kezdoPont<<" "<<ElLista[i].vegPont<<endl;
    }
    return 0;
}
