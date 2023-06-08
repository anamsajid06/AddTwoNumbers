// AddTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        long long number1 = 0;
        long long number2 = 0;

        ListNode* current;

        //iterate list1 and convert to int
        current = l1;
        long long multiplier1 = 1;
        while (current != NULL)
        {
            //multiply value by multiplier
            number1 = current->val * multiplier1 + number1;
            multiplier1 = multiplier1 * 10;
            current = current->next;
        }
        cout << number1 << endl;

        //iterate list2 and convert to int
        current = l2;
        long long multiplier2 = 1;
        while (current != NULL)
        {
            //multiply value by multiplier
            number2 = current->val * multiplier2 + number2;
            multiplier2 = multiplier2 * 10;
            current = current->next;
        }
        cout << number2 << endl;

        //add numbers
        long long result = number1 + number2;

        //convert result to list
        ListNode *resultList = new ListNode;
        ListNode* temp = resultList;
        while (result != 0)
        {
            temp->val = result % 10;
            result = result / 10;

            if (result != 0)
            {
                temp->next = new ListNode;
                temp = temp->next;
            }
        }

        return resultList;
    }
};


int main()
{

    //list 1
    //ListNode l3(3); //3rd node pointing to null
    //ListNode l2(4, &l3); //2nd node pointing to 3rd
    //ListNode l1(2, &l2); //1st node pointing to 2nd
    ListNode l1(9);

    //list 2
    ListNode m10(9);
    ListNode m9(9, &m10);
    ListNode m8(9, &m9);
    ListNode m7(9, &m8);
    ListNode m6(9, &m7);
    ListNode m5(9, &m6);
    ListNode m4(9, &m5);
    ListNode m3(9, &m4); //3rd node pointing to null
    ListNode m2(9, &m3); //2nd node pointing to 3rd
    ListNode m1(1, &m2); //1st node pointing to 2nd

    Solution obj1;
    ListNode* result = obj1.addTwoNumbers(&l1, &m1);

    ListNode* currentNode = result;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
