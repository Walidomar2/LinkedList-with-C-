/**
 * @author : Walid Omar
 * @brief  :
 ** This C++ program provides a simple menu-driven interface for performing various operations on a linked list.
 ** The program initializes an empty linked list and allows the user to interactively choose from a menu of options,
 ** including inserting elements at the beginning, at a certain position, or at the end of the list. Additionally,
 ** the program supports deleting nodes from the beginning, from the end, or from a specified position,
 ** searching for nodes by value, and displaying the current state of the linked list.
 ** Functions:
 ** - LS_CreateNode: Creates a new linked list node with a given value.
 ** - LS_InsertAtBeg: Inserts a new node at the beginning of the linked list.
 ** - LS_InsertAtPos: Inserts a new node at a specified position in the linked list.
 ** - LS_InsertAtEnd: Inserts a new node at the end of the linked list.
 ** - LS_DeleteFromBeg: Deletes a node from the beginning of the linked list.
 ** - LS_DeleteFromEnd: Deletes a node from the end of the linked list.
 ** - LS_DeleteFromPos: Deletes a node from a specified position in the linked list.
 ** - LS_SearchByValue: Searches for a node with a specific value in the linked list.
 ** - LS_DisplayList: Displays the elements of the linked list.
 */

#include <iostream>
#include "linkedlist.hpp"
using namespace std;

/********************************** Global Variables Declaration *******************************************/

list_t *head = new list_t;

/********************************** Main Function *******************************************/
int main()
{
    // init our list to empty list
    head = NULL;
    int userInput = 1;

    while (userInput != 0)
    {
        cout << " 0 --> the exit the program" << endl;
        cout << " 1 --> Enter elements At the beginning of the list" << endl;
        cout << " 2 --> Enter elements At Certin position in the list" << endl;
        cout << " 3 --> Enter elements At the End of the list" << endl;
        cout << " 4 --> Delete A node from Beginning  " << endl;
        cout << " 5 --> Delete A node from End  " << endl;
        cout << " 6 --> Delete A node from certin position " << endl;
        cout << " 7 --> Search in the list " << endl;
        cout << " 8 --> Display your list" << endl;
        cout << "Enter your choice: ";
        cin >> userInput;

        switch (userInput)
        {
        case 1:
        {
            int n, val;
            cout << "Enter the number of elements: ";
            cin >> n;
            cout << "Enter the elements." << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "value= ";
                cin >> val;
                LS_InsertAtBeg(head, val);
            }
            cout << "elements Inserted" << endl;
            cout << "***************************************************" << endl;
            break;
        }
        case 2:
        {
            int n, val, position;
            cout << "Enter the number of elements: ";
            cin >> n;
            cout << "Enter the elements." << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "position= ";
                cin >> position;
                cout << "value= ";
                cin >> val;
                LS_InsertAtPos(head, val, position);
            }
            cout << "elements Inserted" << endl;
            cout << "***************************************************" << endl;
            break;
        }

        case 3:
        {
            int n, val;
            cout << "Enter the number of elements: ";
            cin >> n;
            cout << "Enter the elements." << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "value= ";
                cin >> val;
                LS_InsertAtEnd(head, val);
            }
            cout << "elements Inserted" << endl;
            cout << "***************************************************" << endl;
            break;
        }
        case 4:
        {
            LS_DeleteFromBeg(head);

            cout << "***************************************************" << endl;
            break;
        }

        case 5:
        {
            LS_DeleteFromEnd(head);
            cout << "***************************************************" << endl;
            break;
        }

        case 6:
        {
            cout << "Enter the position of the node you want to delete: ";
            int pos;
            cin >> pos;

            LS_DeleteFromPos(head, pos);
            cout << "***************************************************" << endl;
            break;
        }

        case 7:
        {
            cout << "Enter the Value you want to search for: ";
            int val;
            cin >> val;

            LS_SearchByValue(head, val);
            cout << "***************************************************" << endl;
            break;
        }

        case 8:
        {
            LS_DisplayList(head);
            cout << "***************************************************" << endl;
            break;
        }

        default:
            cout << "Enter write number from the list" << endl;
        }
    }

    return 0;
}
