#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"

int parser_parseX(ArrayList* arrayList, char* fileName){
  int returnAux;
  if(arrayList != NULL && fileName != NULL){
    FILE* file = fopen(fileName, "r");
    if(file != NULL){
      //Entity* entity;
      //buffer variables
      //char b1[256];
      //char b2[256];

      //disregard first line
      //fscanf(file, "[^,],[^,\n]\n", b1, b2);

      do{
        //fscanf(file, "[^,],[^,\n]\n", b1, b2);
        //entity = entity_new();
        //entity_setB1(entity, b1);
        //entity_setB2(entity, b2);
        //al_add(arrayList, entity);
        returnAux = 1;
      }while(feof(file)==0);
    }else{
      printf("\n\nERROR: el archivo %s no existe", fileName);
    }
  }

  return returnAux;
}
