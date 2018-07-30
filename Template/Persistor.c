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

        fprintf(file, header);
        int i;
        for(i=0;i<al_len(arrayList);i++){
          //entity_print(pElement, file, pretty);
          //entity_print(al_get(arrayList, i), file, 0);
        }
      }else{
        printf("\nHubo un error en la creacion del archivo");
      }
    }else{
      printf("\n\nERROR: Ya existe un archivo con ese nombre");
    }
  }
  return returnAux;
}

void persistor_saveAll(){
  return;
}
