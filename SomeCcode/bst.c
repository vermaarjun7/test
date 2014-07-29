#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int data;
    struct node *left; 
    struct node *right;
};
  


struct node* insert(struct node* n, int num)
{
    
    if (n == NULL){
        struct node *nn = (struct node *) malloc(sizeof(struct node));
        nn->data = num;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    
    else if (num < n->data)
        n->left  = insert(n->left, num);
    else
        n->right = insert(n->right, num);
  
    return n;
}

int counter = 0;
void nodeCount(struct node* node)
{
    if (node == NULL)
        return ;
    
    counter++;
    nodeCount(node->left);
    nodeCount(node->right);

    
}
struct node* find(struct node *dNode,int key) 
{ 
    if (dNode == NULL)
        return ;

    else if (key == dNode->data)
         nodeCount(dNode);
        printf("%d\n",counter);
    
    else if (key < dNode->data)
        find(dNode->left, key);
    
    else
        find(dNode->right, key);



}




void printReverse(struct node *ad)
{
    if (ad ==NULL)
        return ;

    printReverse(ad->right);
    printf("%d\n",ad->data);
    printReverse(ad->left);
}

int leafCount(struct node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else
    return leafCount(node->left)+
           leafCount(node->right);      
}


int main()
{
  
  struct node *root = NULL;
    
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);
    printf("%d\n",leafCount(root));
    printf("-----------------");
    printReverse(root);
    printf("------------");
    nodeCount(root);
  
  return 0;
}