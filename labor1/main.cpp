#include <iostream>
#include <fstream>
using namespace std;
struct Elek{
    int kezdoPont;
    int vegPont;
};
struct Szomszedsag{
    int fokszam;
    int *szomszed = (int*)calloc(6, sizeof(int));
};
void writeMatrix(int csomoPont, int **pontMatrix);
void listaMatrix(int **pontMatrix, Elek *Ellista, int el);
void szomszedok(Elek *Ellista, int el, Szomszedsag *szomszedsagiLista, int csomoPont);
int main() {
    cout << "Hello, World!" << endl;
    ifstream file;
    file.open("pontPontMatrix.txt");
    int csomoPont, el;
    file>>csomoPont;
    file >> el;
    Elek *ElLista = new Elek[el];
    for (int i = 0; i < el; i++) {
        file>>ElLista[i].kezdoPont>>ElLista[i].vegPont;
        cout << ElLista[i].kezdoPont<<" "<<ElLista[i].vegPont<<endl;
    }
    int** pontMatrix = (int**)calloc(csomoPont, sizeof(int*));
    for (int i = 0; i < csomoPont; ++i) {
        pontMatrix[i] = (int*)calloc(csomoPont, sizeof(int));
    }
    listaMatrix(pontMatrix, ElLista, el);
    cout<<endl;
    writeMatrix(csomoPont, pontMatrix);
    Szomszedsag *szomszedsagLista = (Szomszedsag*)calloc(csomoPont, sizeof(Szomszedsag));
    szomszedok(ElLista,el, szomszedsagLista,csomoPont);
    return 0;
}
void writeMatrix(int csomoPont, int **pontMatrix){
    for (int i = 0; i < csomoPont; ++i) {
        for (int j = 0; j < csomoPont; ++j) {
            cout << pontMatrix[i][j] << " ";
        }
        cout<<endl;
    }
}
void listaMatrix(int **pontMatrix, Elek *Ellista, int el){
    for (int i = 0; i < el; ++i) {
                pontMatrix[Ellista[i].kezdoPont-1][Ellista[i].vegPont-1] = 1;
                pontMatrix[Ellista[i].vegPont-1][Ellista[i].kezdoPont-1] = 1;
    }
}
void szomszedok(Elek *Ellista, int el, Szomszedsag *szomszedsagiLista, int csomoPont){
    for (int i = 0; i < el; ++i){
        if(Ellista[i].kezdoPont == i+1 || Ellista[i].vegPont == i+1){
            szomszedsagiLista[i].fokszam ++;
        }
    }
    for(int i = 0; i < csomoPont; ++i){
        szomszedsagiLista[i].szomszed = (int*)realloc(szomszedsagiLista[i].szomszed,szomszedsagiLista[i].fokszam*sizeof (int));
        for(int j = 0; j < szomszedsagiLista[i].fokszam; ++j){
            szomszedsagiLista[i].szomszed[j] = Ellista[i].vegPont;
            cout << "[" << szomszedsagiLista[i].szomszed[j] << " ";
        }
        cout << "]" <<endl;
    }

}