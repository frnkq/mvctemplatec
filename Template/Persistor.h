#ifndef PERSISTOR_H_INCLUDED
#define PERSISTOR_H_INCLUDED

#include "ArrayList.h"

int persistor_saveX(ArrayList* arrayList, char* fileName, char* header);
void persistor_saveAll();

int persistor_saveSomething(int backup);

#endif // PERSISTOR_H_INCLUDED
