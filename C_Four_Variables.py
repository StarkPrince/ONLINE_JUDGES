Design the circuit to check if the input number is a simple power of 2, that is n=2  x   and output x , otherwise, output 255 . Also output 255 if the number is zero (this is also the case of n being not a power of 2 , but usually students ask about this case).
Examples:
1. n=00010000 ; output x=00000100(x=4;n=2  4  ) ;
2. n=01010000 ; output x=11111111(255)

External control signals: Start and Restart.


Algorithm 1:
count =0 
input n 
while n>0 
{
count = count +1 
    n=n&(n-1)
}
output count
    
Algorithm 2: (checking the least significant bit for 1 and adding it to count, easy condition logic, as it is a wire) 

count =0
Input n
while n != 0 {
if LSB (n) =1 
{ count = count +1
    n=n>>1
    }
}