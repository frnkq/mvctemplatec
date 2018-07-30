#include <stdio.h>
#include <stdlib.h>

#include "View.h"
#include "fcgetInputs.h"
#include "fcUtilities.h"

void view_init(){
  char salir = 'n';
  do{
      view_printMainMenu();
      int opcion = view_askOption();
      switch(opcion){
      case 1:
        //solo llamar funciones
        break;

      case 2:
        //solo llamar funciones
        break;

      case 3:
        //solo llamar funciones
        break;

      case 4:
        salir = 's';
        break;
      }
  }while(salir=='n');
}

void view_kill(){
  clearScreen();
  cleanStdin();
  printf("Adios");
}

void view_printMainMenu(){
  char menu[] = "\nMenu\n";
  char separator[] = "------------";
  char opcion1[] = "1-";
  char opcion2[] = "2-";
  char opcion3[] = "3-";
  char opcion4[] = "4- Salir";
  fprintf(stdout, "%s\n%s\n%s\n%s\n%s\n%s",
          menu, separator, opcion1, opcion2, opcion3, opcion4);
}

int view_askOption(){
  int opcion=-1;
  getIntWithLimitsInf("", "Opcion invalida", &opcion, 1, 4);

  return opcion;
}
