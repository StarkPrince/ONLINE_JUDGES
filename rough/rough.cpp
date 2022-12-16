#include <bits/stdc++.h>
using namespace std;

// Function to print the array
signed main()
{
    // for loop which starts at -9 and ends at -10 (not inclusive) and decrements by 1
    for (int num1 = -9; num1 > -10; num1 -= 1)
    {
        cout << "Hello" << endl;
        // for loop which starts at 12 and ends at 12 (not inclusive) and decrements by 1
        for (int num2 = 12; num2 > 12; num2 -= 1)
        {
            cout << "there!" << endl;
        }
    }
    // this is going to be printed once
    cout << "Done!";
    return 0;
}

// what would be the output of this program and why?
// a) Hello
//    Done!
// b) Hello
//    there!
//    Done!
// c) Hello
//    there!
//    there!
//    Done!
// d) Hello
//    there!
//    there!

// Answer: a)

// Explanation: The first for loop is never going to be executed because the condition num1 > -10 is never going to be true. The second for loop is also never going to be executed because the condition num2 > 12 is never going to be true. The program will print "Hello" once and then print "Done!" once.

steps to solve this problem : 1. Read the question carefully 2. Write the code 3. Run the code 4. Check the output 5. Explain the output