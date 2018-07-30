#include <stdio.h>
#include <stdlib.h>

#include "Model.h"
#include "ArrayList.h"
#include "Persistor.h"


//#include "Entity.h"

void model_init(){
  entity = al_newArrayList();
}

void model_kill(){
  persistor_saveAll();
  al_clear(entity);
  al_deleteArrayList(entity);
}
