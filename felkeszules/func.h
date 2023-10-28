#ifndef FELKESZULES_FUNC_H
#define FELKESZULES_FUNC_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
void felvono();
struct Musor{
    int start, end;
};
struct Elek{
    int from, to, length;
};
void musorok();
void kruskal();
#endif //FELKESZULES_FUNC_H
