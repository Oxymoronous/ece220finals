#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
  if (!head){
    return 0; //not really necessary because input constrain
  }
  node** array = (node**)malloc(sizeof(node*));
  int index = 0;
  array[0] = NULL;
  while(head){
    node* ele;
    for(int i = 0; i<index; i++){
        ele = array[i];
        if (ele == head){
            free(tmp);
            return 1;
        }
    }
    array = realloc(index+1, sizeof(node*));
    array[index++] = head;
    head = head->next;
  }
  free(tmp);
  return 0;
}

node *CopyList(node *head)
{
   //Insert Code here. You can change the return statement given.
    node* oriwalk = head;
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
        cpynext->arbit = head->arbit;
        head = head->next;
        cpynext = cpynext->next;
    } //finish creating a copy of the ll as a singly ll, the random pointers are shared

    //double loop: loop through every single node in ori ll, and have 'tmp' to remember what
    //              that should be in the copied ll, and then loop through the copied ll, and update
    node* cpywalk = rv;
    node* tmp;
    node* randptr;
    while(oriwalk){
        tmp = cpywalk;
        while (cpywalk){
            randptr = cpywalk->arbit;
            if (randptr == oriwalk){
                cpywalk->arbit = tmp;
            }
            cpywalk = cpywalk->next;
        }
        oriwalk = oriwalk->next;
        cpywalk = tmp->next;
    }
    return rv;
}


