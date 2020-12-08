#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"

int main()
{
	int n;
	printf("Please enter n: ");
	scanf("%d", &n);
	node * head;
	head = farey_seq(n);
	if(head == NULL)
		printf("The linked list is empty");
	delete_list(head);
}

node * farey_seq(int n)
{
	/*You code goes here*/
	if (n == 0) return NULL;
	node* head = (node*)malloc(sizeof(node));
	head->numerator = 0;
	head->denominator = 1;
	head->next = (node*)malloc(sizeof(node));
	head->next->numerator = 1;
	head->next->denominator = 1;
	head->next->next = NULL; //finish initializing first order

    if (n == 1){
        print_list(head, n);
        return head; //just need to print and return
    }
    print_list(head, 1); //just print out the order 1 seq first
    //below is looping the remaining sequences and printing em
    int i,a,b,c,d;
    node* tmp;
    int newnum,newden;
    node* save = head;
	for (i = 2; i<=n ; i++){
        while ((head)&&(head->next)){
            a = head->numerator;
            b = head->next->numerator;
            c = head->denominator;
            d = head->next->denominator;
            if (c+d<=i){
                tmp = head->next;
                newnum = a+b;
                newden = c+d;
                head->next = (node*)malloc(sizeof(node));
                head->next->numerator = newnum;
                head->next->denominator = newden;
                head->next->next = tmp;
                break;
            }
            head = head->next;
        }
        print_list(save, i);
	}
	return save;
}
void print_list(node * head, int n)
{
	if(head == NULL)
		return;
	printf("level %d: ", n);
	while(head != NULL)
	{
		printf("%d/%d ", head->numerator, head->denominator);
		head = head->next;
	}
	printf("\n");
}

void delete_list(node * head)
{
	node * temp;
	while(head != NULL){
		temp = head->next;
		free(head);
		head = temp;
	}
}
