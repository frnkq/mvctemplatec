#include "fcgetInputs.h"
#include "fcUtilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>


int getData(char* message, char* data){
  printf("\n%s", message);
  scanf("%[^\n]", data);
  return 1;
}


int isNumeric(char data[]){
  int i;
  while(data[i] != '\0'){
    if( !isdigit(data[i]) ){
      return -1;
    }
    i++;
  }
  return 1;
}


int isNumericWithSpace(char data[]){
  int i;
  while(data[i] != '\0'){
    if( !isdigit(data[i]) && data[i] != ' '){
      return -1;
    }
    i++;
  }
  return 1;
}

int isAlpha(char data[]){
  int i;
  while(data[i] != '\0'){
    if(!isalpha(data[i])){
      return -1;
    }
    i++;
  }
  return 1;
}


int isAlphaWithSpace(char data[]){
  int i;
  while(data[i] != '\0'){
    if(!isalpha(data[i]) && data[i] != ' '){
      return -1;
    }
    i++;
  }
  return 1;
}


int isAlphaNumeric(char data[]){
  int i;
  while(data[i] != '\0'){
    if(!isalpha(data[i]) && !isdigit(data[i])){
      return -1;
    }
    i++;
  }
  return 1;
}


int isAlphaNumericWithSpace(char data[]){
  int i;
  while(data[i] != '\0'){
    if(!isalpha(data[i]) && !isdigit(data[i]) && data[i] != ' '){
      return -1;
    }
    i++;
  }
  return 1;
}


int isInt(char data[]){
  int i = 0;
  int nDashes = 0;
  char maxint[12];
  char minint[12];
  sprintf(maxint, "%d", INT_MAX);
  sprintf(minint, "%d", INT_MIN);

  while(data[i] != '\0'){
    if( ( !(isdigit(data[i])) && data[i] != '-') ||
          nDashes > 1 ||
          strcmp(data, maxint) > 0 ||
          strcmp(data, minint) < 0 ){

      if(data[i] == '-') nDashes++;
      return -1;
    }
    i++;
  }
  return 1;
}

int isFloat(char data[]){
  int i = 0;
  int nDots = 0;
  while(data[i] != '\0'){
    //counts dots
    if(data[i] == '.'){
      nDots++;
    }
    //returns -1 if data[i] is not a digit nor a point, or if the number of dots it's more than one, or if the first character is a dot
    if( ( !isdigit(data[i]) && data[i] != '.' ) || nDots>1 || data[0]=='.'){
      return -1;
    }
    i++;
  }
  return 1;
}

int isLong(char data[]){
  if(isNumeric(data)==1 && isInt(data)==-1) return 1;
  return -1;
}

int isValidStringLimit(char data[], int length){
  if(strlen(data) > length){
    return -1;
  }

  return 1;
}

int getInt(char message[], int* num){
  char data[TMP_DATA_LENGTH];
  getData(message, data);
  if(isInt(data)) *num = atoi(data);

  return isInt(data);
}

int getIntInf(char message[], char error[], int* num){
  int status;
  do{
    status = getInt(message, num);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);
  return 1;
}

int getIntWithLimits(char message[], int* num, int bottom, int top){
  char data[TMP_DATA_LENGTH];
  int tmp;
  getData(message, data);
  if(isInt(data)) tmp = atoi(data);
  if(tmp>=bottom && tmp <= top){
    *num = tmp;
    return 1;
  }
  return -1;
}

int getIntWithLimitsInf(char message[], char error[], int* num, int bottom, int top){
  int status;
  do{
    status = getIntWithLimits(message, num, bottom, top);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);
  return 1;
}


int getFloat(char message[], float* num){
  char data[TMP_DATA_LENGTH];
  getData(message, data);
  if(isFloat(data)) *num = atof(data);

  return isFloat(data);
}

int getFloatInf(char message[], char error[], float* num){
  int status;
  do{
    status = getFloat(message, num);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);

  return 0;
}

int getFloatWithLimits(char message[], float* num, float bottom, float top){
  char data[TMP_DATA_LENGTH];
  float tmp;
  getData(message, data);
  if(isFloat(data)) tmp = atof(data);
  if(tmp>=bottom && tmp <= top){
    *num = tmp;
    return 1;
  }
  return -1;
}

int getFloatWithLimitsInf(char message[], char error[], float* num, float bottom, float top){
  int status;
  do{
    status = getFloatWithLimits(message, num, bottom, top);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);
  return 1;
}

int getLong(char message[], long* num){
  char data[TMP_DATA_LENGTH];
  getData(message, data);
  if(isLong(data)) *num = atol(data);

  return isLong(data);
}

int getLongInf(char message[], char error[], long* num){
  int status;
  do{
    status = getLong(message, num);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);
  return 1;
}

int getLongWithLimits(char message[], long* num, long bottom, long top){
  char data[TMP_DATA_LENGTH];
  long tmp;
  getData(message, data);
  if(isFloat(data)) tmp = atol(data);
  if(tmp>=bottom && tmp <= top){
    *num = tmp;
    return 1;
  }
  return -1;
}

int getLongWithLimitsInf(char message[], char error[], long* num, long bottom, long top){
  int status;
  do{
    status = getLongWithLimits(message, num, bottom, top);
    cleanStdin();
    if(status == -1) printf("\n%s", error);
  }while(status == -1);
  return 1;
}


int getString(char message[], char* myString){
  getData(message, myString);
  return 1;
}

int getStringLimited(char message[], char* myString, int limit){
  char tmp[TMP_DATA_LENGTH];
  getData(message, tmp);
  if(strlen(tmp)>limit){
    return -1;
  }
  strcpy(myString, tmp);
  return 1;
}

int getStringLimitedInf(char message[], char error[], char* myString, int limit){
  int status;
  do{
    cleanStdin();
    status = getStringLimited(message, myString, limit);
    if(status == -1) printf("\n%s", error);
  }while(status==-1);
  return 1;
}
