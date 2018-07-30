#ifndef FCUTILITIES_H_INCLUDED
#define FCUTILITIES_H_INCLUDED

#include <stdlib.h>

void cleanStdin(void);
void clearScreen(void);

void* read_orCreateFile(char* path, char* mode, int* fileCreated);

#endif // FCUTILITIES_H_INCLUDED
