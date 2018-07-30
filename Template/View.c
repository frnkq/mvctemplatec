#include <stdio.h>
#include <stdlib.h>

#include "View.h"
#include "fcgetInputs.h"
#include "fcUtilities.h"
#include "Model.h"
#include "Parser.h"


//#include "Person.h"


void view_init(){
  char salir = 'n';
  do{
      view_printMainMenu();
      int opcion = view_askOption();
      switch(opcion){
      case 1:
        break;

      case 2:
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
  char opcion1[] = "1-Separar archivo data.csv en hombres.csv y mujeres.csv";
  char opcion2[] = "2-Hacer un blacklists de mails '.ru' y guardar una copia de data.csv sin ellos";
  char opcion3[] = "3-Crear un whitelist de mails '.com' ";
  char opcion4[] = "4- Salir";
  fprintf(stdout, "%s\n%s\n%s\n%s\n%s\n%s",
          menu, separator, opcion1, opcion2, opcion3, opcion4);
}

int view_askOption(){
  int opcion=-1;
  getIntWithLimitsInf("", "Opcion invalida", &opcion, 1, 4);

  return opcion;
}
