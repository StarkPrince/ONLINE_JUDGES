User defined functions: As a minimum, include the following 6 user-defined functions, all of which should be prototyped, and called from within main(.)
char *getDateAndTime0;
Returns a character string with the current date and time

int getInteger()
Read user input into a character string using fgets()
" x " returns −1 indicating program exit.
Otherwise, convert the string into an integer (which will be returned to main 0 ) using

int atoi(const char ∗   str);
or
int sscanf(const char *s, const char *format, ...);

void decimalToBinary(int decValue, char binString[]);
Accepts a decimal value decValue and a character string buffer binString[]. Convert decvalue into its corresponding binary value and store the result as a character string within binString []. binString[] may then be displayed from within main 0.