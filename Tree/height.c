#include<stdio.h>
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

int height(struct Node* header){
    if (header==NULL){
        return -1;
    }

    int value_left=height(header->left);
    int value_right=height(header->right);
    return (value_left>value_right?value_left:value_right)+1;

    

}
int main(){
    insert_value(&header,1);
    insert_value(&header,3);
    insert_value(&header,-2);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    printf("%d\n",height(header));
}