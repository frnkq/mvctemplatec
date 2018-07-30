#include <stdio.h>
#include <stdlib.h>
#include "Model.h"
#include "Persistor.h"

int persistor_saveX(ArrayList* arrayList, char* fileName, char* header){
  int returnAux = -1;
  if(arrayList != NULL && fileName != NULL){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
      file = fopen(fileName, "w");
      if(file != NULL){
        //file header
        fprintf(file, header);
        fprintf(file, "\n");

        int i;
        for(i=0;i<al_len(arrayList);i++){
          //entity_print(pElement, file, pretty);
          //Person_print(al_get(arrayList, i), file, 0);
        }
        returnAux = 1;
      }else{
        printf("\nHubo un error en la creacion del archivo");
      }
      fclose(file);
    }else{
      printf("\n\nERROR: Ya existe un archivo con el  nombre: %s", fileName);
    }
  }
  return returnAux;
}

/*
int persistor_saveSomething(int backup){
    int returnAux = -1;
    if(al_len(someArrayList)>0){
        char filename[256];
        if(backup){
            strcpy(filename, "something.csv");
        }else{
            strcpy(filename, "something.csv.bak");
        }
        int saved = persistor_saveX(something, filename, "HE,A,DER");
        if(saved){
            printf("\nSomething exportado correctamente");
            returnAux = 1;
        }
    }else{
        printf("\nHubo un error al exportar los hombres");
    }
    return returnAux;
}
*/

void persistor_saveAll(){
  //persistor_saveSomething(1); -->1 means backup
  return;
}
