// Write a program that uses cout and cin to interactively request the following information:

// • A car make (e.g. Nissan)
// • A car model (e.g. Altima)
// • A car's year
// • A car's cost

// Output/Input:

// Make: Nissan
// Model: Altima
// Year: 2023
// Cost($): 30000
// After obtaining the above information the program should display the following summary:

// Output:

// Your new Nissan Altima (2023) costs $30000.

// Then, determine and output the integer representation of the each character in “Programming Workshop”. Please include the output of your program as a comment at the top of your source file.

#include <iostream>
using namespace std;

int main()
{
    string make, model;
    int year, cost;

    cout << "Make: ";
    cin >> make;

    cout << "Model: ";
    cin >> model;

    cout << "Year: ";
    cin >> year;

    cout << "Cost($): ";
    cin >> cost;

    cout << "Your new " << make << " " << model << " (" << year << ") costs $" << cost << "." << endl;

    cout << "Integer representation of each character in 'Programming Workshop':" << endl;
    string str = "Programming Workshop";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << ": " << (int)str[i] << endl;
    }

    return 0;
}
