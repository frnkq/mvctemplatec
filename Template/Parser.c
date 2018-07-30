#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"


//#include "Person.h"

int parser_parseEntities(ArrayList* arrayList, char* fileName){
  int returnAux = -1;
  if(arrayList != NULL && fileName != NULL){
    FILE* file = fopen(fileName, "r");
    if(file != NULL){
        //Person* person;
        //char id[256];
        //char firstName[256];
        //char lastName[256];

      //disregard first line
      //fscanf(file, "%[^,],%[^,],%[^,\n]\n", id,firstName,lastName);
      do{
         int read = 6;//fscanf(file, "%[^,],%[^,],%[^,\n]\n", id,firstName,lastName);

        if(read==6){
            //entity = Entity_new();
            //Person_setId(person, idInt);
            //Person_setFirstName(person, firstName);
            //Person_setLastName(person, lastName);
            //al_add(arrayList, entity);
            returnAux = 1;
        }else{
            returnAux = -1;
            printf("\nHubo un error leyendo el archivo");
            break;
        }
      }while(feof(file)==0);
      fclose(file);
    }else{
      printf("\n\nERROR: el archivo %s no existe", fileName);
    }
  }
  return returnAux;
}
