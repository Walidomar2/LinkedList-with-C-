#include "linkedlist.hpp"

list_t *LS_CreateNode(list_t *&head_obj, int value)
{
    list_t *tempPtr = new list_t;
    tempPtr->data = value;
    tempPtr->next = NULL;

    return tempPtr;
}

void LS_InsertAtBeg(list_t *&head_obj, int value)
{
    list_t *tempPtr = new list_t;

    tempPtr = LS_CreateNode(head_obj, value);
    tempPtr->next = head_obj;
    head_obj = tempPtr;
}

void LS_InsertAtEnd(list_t *&head_obj, int value)
{
    list_t *tempPtr = new list_t;
    tempPtr = LS_CreateNode(head_obj, value);

    if (head_obj == NULL)
    {
        head_obj = tempPtr;
    }
    else
    {
        list_t *tempPtr2 = head_obj;

        while (tempPtr2->next != NULL)
        {
            tempPtr2 = tempPtr2->next;
        }
        tempPtr2->next = tempPtr;
    }
}

void LS_InsertAtPos(list_t *&head_obj, int value, int position)
{
    if (position < 0)
    {
        cout << "Please Enter a positive number as position " << endl;
    }
    else
    {
        list_t *tempPtr = new list_t;
        tempPtr = LS_CreateNode(head_obj, value);

        if (position == 1)
        {
            LS_InsertAtBeg(head_obj, value);
        }
        else
        {
            int counter = 1;
            list_t *tempPtr2 = head_obj;

            while (counter != (position - 1) && tempPtr2->next != NULL)
            {

                counter++;
                tempPtr2 = tempPtr2->next;
            }

            // if the user enter number larger than list size so it will insert the number at end of the list
            if (tempPtr2->next == NULL)
            {
                LS_InsertAtEnd(head_obj, value);
            }
            // else will insert the number at the right position
            else
            {
                tempPtr->next = tempPtr2->next;
                tempPtr2->next = tempPtr;
            }
        }
    }
}

void LS_DeleteFromBeg(list_t *&head_obj)
{
    if (head_obj == NULL)
    {
        cout << "There is NO Nodes to delete";
    }
    else
    {
        list_t *tempPtr = new list_t;
        tempPtr = head_obj;
        head_obj = head_obj->next;
        delete tempPtr;
        cout << "Node deleted" << endl;
    }
}

void LS_DeleteFromEnd(list_t *&head_obj)
{
    if (head_obj == NULL)
    {
        cout << "There is NO Nodes to delete";
    }
    else
    {

        list_t *tempPtr = new list_t;
        if (head_obj->next == NULL)
        {
            tempPtr = head_obj;
            head_obj = NULL;
            delete tempPtr;
            cout << "Node deleted" << endl;
        }
        else
        {
            list_t *prevPtr = new list_t;
            tempPtr = head_obj->next;
            prevPtr = head_obj;

            while (tempPtr->next != NULL)
            {
                prevPtr = prevPtr->next;
                tempPtr = tempPtr->next;
            }

            prevPtr->next = NULL;
            delete tempPtr;
            cout << "Node deleted" << endl;
        }
    }
}

void LS_DeleteFromPos(list_t *&head_obj, int pos)
{
    if (pos < 0)
    {
        cout << "Please Enter Positive number";
    }
    else
    {
        if (pos == 1)
        {
            LS_DeleteFromBeg(head_obj);
        }
        else
        {
            int counter = 1;
            list_t *currentPtr = new list_t;
            list_t *prevPtr = new list_t;

            prevPtr = head_obj;
            currentPtr = head_obj->next;

            while (counter != (pos - 1) && currentPtr->next != NULL)
            {
                currentPtr = currentPtr->next;
                prevPtr = prevPtr->next;
            }

            if (currentPtr->next == NULL)
            {
                LS_DeleteFromEnd(head_obj);
            }
            else
            {
                prevPtr->next = currentPtr->next;
                delete currentPtr;
                cout << "Node deleted " << endl;
            }
        }
    }
}

void LS_SearchByValue(list_t *&head_obj, int value)
{
    if (head_obj == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        list_t *tempPtr = new list_t;
        tempPtr = head_obj;
        char flag = 0;
        int position = 1;
        while (tempPtr != NULL)
        {
            if (tempPtr->data == value)
            {
                flag = 1;
                break;
            }
            position++;
            tempPtr = tempPtr->next;
        }

        if (flag)
        {
            cout << "the element at position: " << position << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
}

void LS_DisplayList(list_t *head_obj)
{
    if (head_obj == NULL)
    {
        cout << "There is no Data in the list" << endl;
    }
    else
    {
        list_t *tempPtr = head_obj;

        cout << "List numbers : ";
        while (tempPtr != NULL)
        {
            cout << tempPtr->data << " ";
            tempPtr = tempPtr->next;
        }

        cout << endl;
    }
}