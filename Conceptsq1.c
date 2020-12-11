int additem (iItem *head, int input){
    iItem* newItem;
    newItem = (iItem*)malloc(sizeof(iItem));
    if (newItem == NULL)return 0;
    //if (head == NULL) return 0; 
    newItem->val = input;
    newItem->next = head;
    head = newItem;
    //*head = newItem;
    return 1;
}

/*line 4 condition checking is never fulfilled, the error checking should be
checking for the head pointer in the input

line 8 is wrong because it does not change the head pointer*/

int main(){
    int choice, input, ret;
    iItem *head = NULL;
    addItem(head, 5);
    addItem(head, 10);
    return 0;
}
