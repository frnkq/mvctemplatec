#include "fcUtilities.h"
#include <stdio.h>
#include <stdlib.h>

void cleanStdin(void){
    setbuf(stdin,NULL);

    /*
        int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    */
}

void clearScreen(void){

    system("@cls||clear");
}

void* read_orCreateFile(char* path, char* mode, int* fileCreated){
  FILE* this = fopen(path, mode);
  if(this == NULL){
    this = fopen(path, "w+");
    *fileCreated = 1;
    return this;
  }
  *fileCreated = 0;
  return this;
}
