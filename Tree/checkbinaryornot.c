#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};
struct Node* header=NULL;

struct Node* create_Node(int value){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    return node;

}
void insert_value(struct Node** header,int value){
    if (*header==NULL){
        *header=create_Node(value);
        return;
    }
    struct Node* current=*header;
    while(1){
        if (current->value > value){
            if (current->left==NULL){
                current->left=create_Node(value);
                return ;
            }
            current=current->left;
        }
        if (current->value < value){
            if (current->right==NULL){
                current->right=create_Node(value);
                return;
            }
            current=current->right;
        }
    }
}
int isSubTreeLesser(struct Node* root,int value){
    if (root==NULL){
        return 1;
    }
    return root->value<=value?1:0;


}

int isSubTreeGreater(struct Node* root,int value){
    if (root==NULL){
        return 1;
    }
    return root->value>=value?1:0;

}

int check_binary_search_or_not(struct Node *header){
    if (header==NULL) return 1;
    if (isSubTreeGreater(header->right,header->value)
    &&isSubTreeLesser(header->left,header->value) 
    && check_binary_search_or_not(header->left)
     && check_binary_search_or_not(header->right)){
        return 1;
    }
    return 0;

}
void print_tree(struct Node *header){
    if (header==NULL){
        return;
    }
   
    print_tree(header->left);
    printf("%d \n",header->value);
    print_tree(header->right);


}
int main(){
    insert_value(&header,1);
    insert_value(&header,3);
    insert_value(&header,-2);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    struct Node *new_not_binary=(struct Node*)malloc(sizeof(struct Node));
    struct Node *left=(struct Node*)malloc(sizeof(struct Node));
    struct Node *right=(struct Node*)malloc(sizeof(struct Node));

    new_not_binary->value=10;
    left->value=20;
    right->value=0;
    new_not_binary->left=left;
    new_not_binary->right=right;
    print_tree(new_not_binary);

    printf("%d",check_binary_search_or_not(new_not_binary));
}