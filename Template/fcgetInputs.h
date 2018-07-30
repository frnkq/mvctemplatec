#ifndef FCGETINPUTS_H_INCLUDED
#define FCGETINPUTS_H_INCLUDED

#define TMP_DATA_LENGTH 300


//THIS LIBRARY DEPENDS ON fcUtilities.h

/** \brief Gets user input and saves it in a char[] datatype variable
 *
 * \param message[] char* Message to display before user input
 * \param data[] char* variable where user's input will be saved
 * \return int 1 if succeded
 *
 */
int getData(char* message, char* data);


/******************************VERIFIERS****************************/
/** \brief Checks if a string has only numbers as a value
 *
 * \param char[] data. Character array to check for non-numeric values
 * \return -1 if data has a non-numeric value, 1 if it's only numbers
 *
 */
int isNumeric(char data[]);

/** \brief Checks if a string has only numbers or whitespaces as a value
 *
 * \param char[] data. Character array to check for non-numeric or non-whitespaces values
 * \return -1 if data has a non-numeric or non-whitespace value, 1 if it's only numbers or whitespace
 *
 */
int isNumericWithSpace(char data[]);

/** \brief Check if a string has only alphabetic characters
 *
 * \param char[] data. String to check
 * \return 1 if the string is only alphabetical, -1 if it isn't
 *
 */
int isAlpha(char data[]);

/** \brief Check if a string has only alphabetic characters, including a whitespace
 *
 * \param char[] data. String to check
 * \return 1 if the string is only alphabetical (including whitespace), -1 if it isn't
 *
 */
int isAlphaWithSpace(char data[]);

/** \brief Check if a string has only alpha-numeric characters
 *
 * \param char[] data. String to check
 * \return 1 if the string is only alphanumerical -1 if it isn't
 *
 */
int isAlphaNumeric(char data[]);

/** \brief Check if a string has only alpha-numeric characters, including whitespace
 *
 * \param char[] data. String to check
 * \return 1 if the string is only alphanumerical (including whitespace) -1 if it isn't
 *
 */
int isAlphaNumericWithSpace(char data[]);

/** \brief Verifies if a certain char[] variable has an integer as value, checking if it has a non digit character diffrent than only one dash and if the total value is between the limits of int typedata
 *
 * \param char[] data Variable to check
 * \return 1 if is int, -1 if its something else
 *
 */
int isInt(char data[]);

/** \brief Verifies if a certain char[] variable has a float as value, based on if it has more than one dot or a character that isn't a digit
 *
 * \param char[] data variable to check
 * \return 1 if is float, -1 if its something else
 *
 */
int isFloat(char data[]);


int isLong(char data[]);

int isValidStringLimit(char data[], int lenght);
/**************************END VERIFIERS****************************/


/*******************************GETTERS*****************************/
/** \brief Calls getData() for getting user input, isInt() for verifying user's input. If isInt() returns 1, user's input will be parsed to integer and saved to *num
 *
 * \param char[] message to display before user input
 * \param int* num variable where data will be saved after being parsed to int
 * \return isInt(data) returns the response of IsInt()
 *
 */
int getInt(char message[], int* num);

/** \brief Calls getData() for getting user input, isInt() for verifying user's input. If isInt() returns 1, user's input will be parsed to integer and saved to *num. If isInt() returns -1, function will run again
 *
 * \param char[] message to display before user input
 * \param char[] error, error to display in case of error
 * \param int* num variable where data will be saved after being parsed to int
 * \return 1
 *
 */
int getIntInf(char message[], char error[], int* num);


/** \brief Calls getData() for getting user input, isInt() for verifying user's input. If isInt() returns 1, user's input will be parsed to integer and saved to *num if it's between the limits top and bottom.
 *
 * \param char[] message to display before user input
 * \param int* num variable where data will be saved after being parsed to int
 * \param int bottom bottom limit
 * \param int top top limit
 * \return 1 if it's an integer between the limits, -1 if it's not
 *
 */
int getIntWithLimits(char message[], int* num, int bottom, int top);

/** \brief Executes getIntWithLimits() until it get's a valid input
 *
 * \param char[] message to display before user input
 * \param char[] error, error to display in case of error
 * \param int* num variable where data will be saved after being parsed to int
 * \param int bottom bottom limit
 * \param int top top limit
 * \return 1 if it's an integer between the limits
 *
 */
int getIntWithLimitsInf(char message[], char error[], int* num, int bottom, int top);

/** \brief Calls getData() for getting user input, isFloat() for verifying user's input. If isFloat() returns 1, user's input will be parsed to float and saved to *num
 *
 * \param char[] message to display before user input
 * \param float* num variable where data will be saved after being parsed to float
 * \return isFloat(data) returns the response of IsFloat()
 *
 */
int getFloat(char message[], float* num);

/** \brief Executes getFloat() until it gets a valid input
 *
 * \param char[] message to display before user input
 * \param char[] error, error to display in case of error
 * \param float* num variable where data will be saved after being parsed to float
 * \return isFloat(data) returns the response of IsFloat()
 *
 */
int getFloatInf(char message[], char error[], float* num);

/** \brief Calls getData() for getting user input, isFloat() for verifying user's input. If isFloat() returns 1, user's input will be parsed to float and saved to *num if it's between the limits top and bottom
 *
 * \param char[] message to display before user input
 * \param int* num variable where data will be saved after being parsed to int
 * \param int bottom bottom limit
 * \param int top top limit
 * \return 1 if it's an integer between the limits, -1 if it's not
 *
 */
int getFloatWithLimits(char message[], float* num, float bottom, float top);

/** \brief Executes getFloatWithLimits() until it gets a valid input
 *
 * \param char[] message to display before user input
 * \param char[] error, error to display in case of error
 * \param int* num variable where data will be saved after being parsed to int
 * \param int bottom bottom limit
 * \param int top top limit
 * \return 1 if it's an integer between the limits, -1 if it's not
 *
 */
int getFloatWithLimitsInf(char message[], char error[], float* num, float bottom, float top);


int getLong(char message[], long* num);
int getLongInf(char message[], char error[], long* num);
int getLongWithLimits(char message[], long* num, long bottom, long top);
int getLongWithLimitsInf(char message[], char error[], long* num, long bottom, long top);

/** \brief Using getData(), asks for user's input and save it to myString
 *
 * \param char[] message, message to display before user input
 * \param char* myString, pointer to a string where user's input will be saved
 * \return 1 if it's a valid string, -1 if it isn't
 *
 */
int getString(char message[], char* myString);

/** \brief Using getData(), asks for user's input and save it to myString if its length is less than limit parameter
 *
 * \param char[] message, message to display before user input
 * \param char* myString, pointer to a string where user's input will be saved
 * \param int limit, length limit of the string
 * \return 1 if it's a valid string, -1 if it isn't
 *
 */
int getStringLimited(char message[], char* myString, int limit);

/** \brief Executes getStringLimited() until it gets a valid input
 *
 * \param char[] message, message to display before user input
 * \param char[] error, error to display in case of error
 * \param char[] error, error to display in case of error
 * \param char* myString, pointer to a string where user's input will be saved
 * \param int limit, length limit of the string
 * \return 1 if it's a valid string
 *
 */
int getStringLimitedInf(char message[], char error[], char* myString, int limit);

/***************************END GETTERS*****************************/


#endif // FCGETINPUTS_H_INCLUDED
