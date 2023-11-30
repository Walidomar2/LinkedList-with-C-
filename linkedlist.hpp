#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

#include <iostream>
using namespace std;

/********************************** Data types Declaration *******************************************/

typedef struct list
{
    int data;
    struct list *next;
} list_t;

/********************************** Functions Declaration *******************************************/
list_t *LS_CreateNode(list_t *&head_obj, int value);
void LS_InsertAtBeg(list_t *&head_obj, int value);
void LS_InsertAtEnd(list_t *&head_obj, int value);
void LS_InsertAtPos(list_t *&head_obj, int value, int position);
void LS_DeleteFromBeg(list_t *&head_obj);
void LS_DeleteFromPos(list_t *&head_obj, int pos);
void LS_DeleteFromEnd(list_t *&head_obj);
void LS_SearchByValue(list_t *&head_obj, int value);
void LS_DisplayList(list_t *head_obj);

#endif