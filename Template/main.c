#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"

int main()
{
    controller_init();
    controller_kill();

    /**
      void Entity_print(Entity* this, FILE* output, int pretty){
        if(this != NULL){
          int id;
          char nombre[256];

          Categoria_getId(this, &id);
          Categoria_getNombreCat(this, nombre);

          char sequence[256];

          if(pretty){
            strcpy(sequence, "ID: %d, Nom:%s\n");
          }
          else{
            strcpy(sequence, "%d,%s\n");
          }

          fprintf(output, sequence, id, nombre);
        }
      }
    **/
    return 0;
}
