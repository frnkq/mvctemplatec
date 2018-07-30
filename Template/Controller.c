#include "Controller.h"
#include "View.h"
#include "Model.h"

void controller_init(){
  model_init();
  view_init();
}

void controller_kill(){
  model_kill();
  view_kill();
}
