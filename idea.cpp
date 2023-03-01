Write a completely separate program that reads students' names followed by their test scores from a data file. The program should read in the data till end of file is found (or the maximum students is reached) and then process
the data as described here. The program should output each student's name followed by the test scores and the relevant grade. It should also find and print the highest test score and the name of the students having the highest
test score.

Student data should be stored in an array of structures. The structure should contain the following members; studentFName and studentLName of string, testScore of type int, and grade of type char. Suppose that the
class has 20 students. The array should be 20 elements long. Try to use exception handling in the event invalid data is found while reading the data file.
Your program must contain at least the following functions:
• Afunction to read the students' data into the structure array from a data file
• Afunction to assign the relevant grade to each student.
• Afunction to find the highest test saye.
• Afunction to print the names of the students having the highest test score.
Your program must output each student's name in this form: last name followed by a comma, followed by a space, followed by the first name; the name must be left justified. Moreover, other than declaring the variables and
opening the input and output files, the function main should only be a collection of function calls.
You create your test data text file but it should be no more than 20 rows of data which have 2 names and a test score. It may look something like this:

Thomas Baker 87 
Bob Jones 99 
Suzy Smith 76 

and so on ,
