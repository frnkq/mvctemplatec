#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//
/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL){
           resizeUp(this);
           this->pElements[al_len(this)] = pElement;
           this->size++;
           returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL){
        free(this->pElements);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL){
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL){
        if(index >= 0 && index < al_len(this) ){
            returnAux = this->pElements[index];
        }
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        int i;
        for(i=0;i<al_len(this);i++){
            if(this->pElements[i] == pElement){
                returnAux = 1;
                break;
            }else{
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL){
        if(index >= 0 && index < al_len(this) ){
            this->pElements[index] = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this != NULL){
     if(index >= 0 && index < al_len(this) ){
            int i;
            for(i=index; i<(this->size);i++){
                this->pElements[i] = this->pElements[i+1];
                returnAux = 0;
            }
            this->size--;
        }
    }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL){
       this->size = 0;
       void* auxPtr = realloc(this->pElements, sizeof(void *)*AL_INITIAL_VALUE);
       if(auxPtr != NULL){
            this->pElements = auxPtr;
            this->reservedSize = AL_INITIAL_VALUE;
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    if(this != NULL){
        returnAux = al_newArrayList();
        returnAux->pElements = malloc(sizeof(void *)*(this->size));
        returnAux->size = this->size;
        int i;
        for(i=0;i<al_len(this);i++){
            returnAux->pElements[i] = this->pElements[i];
        }
    }
    return returnAux;
}



/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        if(index >0 && index < al_len(this)){
            resizeUp(this);
            void* auxElement = al_get(this, index);
            int i;
            this->size++;
            for(i=al_len(this);i>index;i--){
                al_set(this, i, al_get(this, i-1));
            }
            al_set(this, index, pElement);


        }
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL){
        int i;
        for(i=0;i<al_len(this);i++){
            if(this->pElements[i] == pElement){
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL){
        if(this->size == 0){
            returnAux = 1;
        }else{
            returnAux = 0;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL){
        if(index >= 0 && index < al_len(this)){
            returnAux = this->pElements[index];
            al_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;

    ArrayList* auxAl = al_newArrayList();
    if(this != NULL && auxAl != NULL){
      if(from >= 0 && from < al_len(this) && to >=0 && to < al_len(this)){
        void* auxElements = (void*) malloc(sizeof(void*) * (to-from) );
        if(auxElements != NULL){
          auxAl->pElements = auxElements;
          auxAl->size = 1;
          auxAl->reservedSize = 1;
          if(to-from != 0){
            auxAl->size = to-from-1;
            auxAl->reservedSize = to-from-1;
          }

          int i;
          for(i=0;i<(auxAl->size);i++){
            auxAl->pElements[i] = this->pElements[from];
            if(i != auxAl->size)
                from++;
          }
          returnAux = auxAl;
        }
      }
    }

    return returnAux;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL){
        if(al_len(this2) >= al_len(this)){
            int i;
            for(i=0;i<al_len(this2);i++){
                int contains = al_contains(this, this2->pElements[i]);
                if(contains == -1 ){
                   returnAux = 0;
                   break;
                }else if(contains == 0){
                    if(i != this2->size)
                        returnAux = 0;
                    break;
                }
            }

            if(i==al_len(this2)){
                returnAux = 1;
            }
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* , void*), int order)
{
    int returnAux = -1;

    if((this != NULL && pFunc != NULL) && (order == 1 || order == 0)){
        int p,j;
        void* auxElement;
        for(p=1;p<al_len(this);p++){
            auxElement = al_get(this, p);
            j = p-1;
            if(order == 1){
                while((j>=0) && ( pFunc(auxElement, al_get(this, j) )== -1) ){
                    this->pElements[j+1] = this->pElements[j];
                    j--;
                }
                this->pElements[j+1] = auxElement;

            }else{
                while((j>=0) && ( pFunc(auxElement, al_get(this, j) )== 1) ){
                    this->pElements[j+1] = this->pElements[j];
                    j--;
                }
                this->pElements[j+1] = auxElement;
                }
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Removes duplicates elements of list using a compare pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if not dupplicate items
 *                  - (1) if removed dupplicate items
 */
ArrayList* al_removeDuplicates(ArrayList* this, int (*pFunc)(void*, void*)){
    ArrayList* returnAux = al_newArrayList();
    if(this != NULL && pFunc != NULL){
        int i,j;
        int flag = 0;
        int n = al_len(this);
        for(i=0;i<n;i++){
            for(j = i-1;j >= 0;j--){
                if(pFunc(al_get(this, i), al_get(this, j) )==0){
                    flag = 1;
                }
            }
            if(flag == 0){
                al_add(returnAux, al_get(this, i));
            }
            flag = 0;
        }
    }
    return returnAux;
}

/** \brief Creates a sublist of elements that comply with pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return ArrayList* Return the sublist of the elements that comply with the pFunc
 */
ArrayList* al_reduce(ArrayList* this, int (*pFunc)(void*)){
  ArrayList* returnAux = al_newArrayList();
  if(this != NULL && pFunc != NULL){
    int i;
    int len = al_len(this);
    for(i=0;i<len;i++){
      if(pFunc(al_get(this, i))==1){
        al_add(returnAux, al_get(this, i));
      }
    }
  }
  return returnAux;
}

/** \brief Maps all the elements in pElements to a function
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to the function that will be applied to each element
 * \return -2 if the function returned -1 every time
 *          -1 if the function returned -1 at least one time
 *          1 if the function never returned -1
 */
int al_map(ArrayList* this, int (*pFunc)(void*)){
    int returnAux = -2;
    if(this != NULL && pFunc != NULL){
        int i;
        int pFuncStatus;
        for(i=0;i<al_len(this);i++){
            pFunc(al_get(this, i));
        }
        if(pFuncStatus == -1){
            returnAux = -1;
            if(i==al_len(this) && pFuncStatus==-1){
                returnAux = -2;
            }
        }else{
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 *                  - (1) if ok but not resized
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL){
        if(this->size == this->reservedSize){
            void* auxPtr = realloc(this->pElements, sizeof(void*)*(this->reservedSize+AL_INCREMENT));
            if(auxPtr != NULL){
                this->pElements = auxPtr;
                this->reservedSize += AL_INCREMENT;
                returnAux = 0;
            }
        }
        returnAux = 1;
    }
    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
