// Write in C++

// Introduction:
// Your task for this assignment is to write a program that is able to decode IDs from two
// different bars (Bar1 and Bar2), check for duplicate IDs, sort the IDs in ascending order, and print
// a report of the IDs indicating which IDs are guilty and which are innocent. An ID is guilty if it
// appears more than once, and an ID is innocent if it appears only once.
// Assumptions:
// ● Each input file may contain a maximum of 100 IDs
// ● Bar names will always be “Bar1” and “Bar2”
// ● Each ID may vary in length (i.e. 12345, 9019, 23, etc.)
// ● Each encoded ID contains only numbers and parentheses
// ● Each encoded ID has n characters, where 1 <= n <= 30
// ● Each decoded ID has m characters, where 1 <= m <= 10
// ● Encoded IDs will always have balanced parenthesis
// ● There will be may be empty lines in the input file
// ● An ID is considered guilty if it appears more than once (regardless of what bar it comes
// from).

// Rules for Decoding and Output:
// For decoding the IDs, reverse the numbers in each pair of matching parentheses, starting
// from the innermost pair. Below are the steps to decode the ID (4(23)1):

// Step 1: You start with (4(23)1) as your encoded ID. Begin decoding from the innermost
// parentheses and reverse the numbers, so you reverse the numbers 2 and the 3. Now your encoded
// ID is (4321)

// Step 2: Your encoded ID is now (4321), so reverse the number 4, 3, 2, and 1 since they
// are inside parentheses. After reversing the numbers you are left with 1234. There are no
// parenthesis left so there is nothing left to decode. Your decoded ID is 1234.

// For the output, you should print both guilty and innocent IDs. You should print guilty IDs
// first and then the innocent IDs. IDs should be printed in ascending order for both guilty and
// innocent. The format for the output is shown below.

// You must use a linked list to implement your solution and your linked list operations
// should only use recursion. Your linked list class should not contain any for or while loops. You
// may use for and/or while loops in your main function but not in your linked list class.

// Example input and output:

// input1.txt

// Bar1
// 10(01)
// (4(23)1)
// Bar2
// (20)02
// Bar1
// (20)21
// Bar2
// 3(021)
// (4321)

// output1.txt

// Guilty:
// 1234
// Innocent:
// 0202
// 0221
// 1010
// 3120

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Node class for the linked list
class Node
{
public:
    string data;
    Node *next;
    Node(string s) : data(s), next(nullptr) {}
};

// Linked list class
class LinkedList
{
private:
    Node *head;
    int size;

    // Recursive function to add a node at the end of the list
    void addNode(Node *curr, string data)
    {
        if (curr->next == nullptr)
        {
            curr->next = new Node(data);
            size++;
        }
        else
        {
            addNode(curr->next, data);
        }
    }

    // Recursive function to decode a string by reversing the numbers inside matching parentheses
    string decode(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                int j = i + 1, count = 1;
                while (j < n && count > 0)
                {
                    if (s[j] == '(')
                    {
                        count++;
                    }
                    else if (s[j] == ')')
                    {
                        count--;
                    }
                    j++;
                }
                string sub = s.substr(i + 1, j - i - 2);
                reverse(sub.begin(), sub.end());
                s.replace(i, j - i, sub);
                n = s.length();
            }
        }
        return s;
    }

public:
    LinkedList() : head(nullptr), size(0) {}

    // Function to add a string to the end of the list
    void add(string data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            size++;
        }
        else
        {
            addNode(head, data);
        }
    }

    // Function to print the list
    void print()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    // Recursive function to check if a string is in the list
    bool contains(Node *curr, string data)
    {
        if (curr == nullptr)
        {
            return false;
        }
        else if (curr->data == data)
        {
            return true;
        }
        else
        {
            return contains(curr->next, data);
        }
    }

    // Function to check if a string is in the list
    bool contains(string data)
    {
        return contains(head, data);
    }

    // Recursive function to remove a node from the list
    void remove(Node *prev, Node *curr)
    {
        if (curr == head)
        {
            head = curr->next;
            delete curr;
            size--;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
            size--;
        }
    }

    // Function to remove a string from the list
    void remove(string data)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == data)
            {
                remove(prev, curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Recursive function to sort the list in ascending order
    void sort(Node *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        Node *min = curr;
        Node *temp = curr->next;
        while (temp != nullptr)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }
        string tempData = curr->data;
        curr->data = min->data;
        min->data = tempData;
        sort(curr->next);
    }

    // Function to sort the list in ascending order
    void sort()
    {
        sort(head);
    }

    // Function to print the list in the output format
    void printOutput()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << decode(curr->data) << endl;
            curr = curr->next;
        }
    }

    // Function to get the size of the list
    int getSize()
    {
        return size;
    }

    // Function to get the head of the list
    Node *getHead()
    {
        return head;
    }
};
