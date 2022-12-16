/* Write an assembly program, that enter a string from keyboard such as "computer systems engineering", convert it to capital letter, print in order, and finally print it in reverse order. */ 

/* take input from keyboard */ 
 mov ah, 1 
 int 21h 
 mov ah, 2 
 int 21h 
 mov ah, 9 
 int 21h 
 mov ah, 4ch 
 int 21h

/* convert to capital letter */
    mov ah, 2
    int 21h
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h

/* print in order */
    mov ah, 2
    int 21h
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h

/* print in reverse order */
    mov ah, 2
    int 21h
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h

steps to solve this problem
1. take input from keyboard
2. convert to capital letter
3. print in order
4. print in reverse order
