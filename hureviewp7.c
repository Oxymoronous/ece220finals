//Implement delete_node for a BST:

typedef struct bstnode {
  int x;
  struct bstnode *left, *right;
} bstnode;

void delete_node(bstnode **root, int victim){
    //no tree to begin with
    if (*root == NULL){
        return;
    }

    if(*root->x == victim){
        //if node to be deleted is a leaf node
        if ((*root->left == NULL) && (*root->right == NULL)){
            free(*root);
            return;
        }

        //if node to be deleted has only one child node
        if((*root->left == NULL)&&(*root->right->left == NULL)&&(*root->right->right == NULL)){
            //(has only right child node)
            bstnode* replace = *root->right;
            int replace_val = *root->right->x;
            free(*root);
            root = &replace;
            *root->x = replace_val;
            *root->left == NULL;
            *root->right == NULL;
            return;
        }
        if((*root->right == NULL)&&(*root->left->left == NULL)&&(*root->left->right == NULL)){
            //(has only left child node)
            bstnode* replace = *root->left;
            int replace_val = *root->left->x;
            free(*root);
            root = &replace;
            *root->x = replace_val;
            *root->left == NULL;
            *root->right == NULL;
            return;
        }

        //if node to be deleted has two child nodes
        bstnode* onestepright = *root->right;   //taking one step to the right
        bstnode* sacrifice;
        while(onestepright){
            //getting the leftmost leaf node from the 'one step to the right'
            sacrifice = onestepright;
            onestepright = onestepright->left;
        }
        int sac_val = sacrifice->x;
        *root->x = sac_val;
        delete_node(&onestepright, sac_val);
        return; 
    } 
};

bstnode* newnode(int key){
    bstnode* tmp = (bstnode*)malloc(sizeof(node));
    tmp->x = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

bstnode* insert(bstnode* node, int value){
    if (node == NULL){
        return newnode(value);
    }
    if (value<node->x){
        node->left = insert(node->left,key);
    }else{
        node->right = insert(node->right,key);
    }
    return node;
}

//traversal of tree (inorder)
void inorder(bstnode* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->x);
        inorder(root->right);
    }
}

int main(){
    bstnode* root = NULL;
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);
    inorder(root);
}
