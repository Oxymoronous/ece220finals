#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
  if (!head){
    return 0; //not really necessary because input constrain
  }
  node* array = (node*)malloc(sizeof(node));
  int index = 0;
  array[0] = NULL;
  while(head){
    index += 1;
    node* ele;
    for(int i = 0; i<count; i++){
        ele = array[i];
        if (ele == head){
            return 1;
        }
    }
    array+1 = (node*)malloc(sizeof(node)); //STUCK: how to create a dynamic array on the run?
    array[index] = head;
    head = head->next;
  }
  return 0;
}


typedef struct node{
    int value;
    struct node * next; 
    struct node * arbit;
}node;

node *CopyList(node *head)
{
   //Insert Code here. You can change the return statement given.
    node* cpynext = NULL;
    node* rv;
    node* rand;
    while(head){
        if (!cpynext){
            cpynext = (node*)malloc(sizeof(node));  //edge case: creating head node of copied ll
            rv = copynext;  //final answer
        }
        cpynext->value = head->value;
        cpynext->next = (node*)malloc(sizeof(node));
        /*traverse through the ll following the arbitrary pointers?
        rand = head->arbit;
        if (rand == head){
            cpynext->arbit = cpynext; //the random pointer points back to current node
        }
        STUCK: if I traverse randomly, how to remember the pointer that points to my
        */
        
        /*somehow need to create a hashtable?
        HASHTABLE {ori pointer: copied pointer}
        */
        head = head->next;
        cpynext = cpynext->next;
    }


   return NULL;
}

node *CopyList(node* head)
{
    node* rand;
    while (head){
        node* cpy = (node*)malloc(sizeof(node));
        cpy->value = head->value;
        rand = head->arbit;
    }
}

