//
// Created by Administrator on 2023-05-17.
//

#ifndef MINTAPARC2_FUN_H
#define MINTAPARC2_FUN_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stdlib.h>
void read(const char*filename, std::vector<int>*adjL, int &n);
void bfs(const char* filename, int u, std::vector<int>adjL[], int *szin, int &n);
#endif //MINTAPARC2_FUN_H
