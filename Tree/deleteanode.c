#include<stdio.h>
#include<unistd.h>


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct Nodes{
    int value;
    struct Nodes* left;
    struct Nodes* right;

};
struct Nodes *header=NULL;

void insert_value(struct Nodes** header,int value){
    
    if (*header==NULL){
        struct Nodes* temp=(struct Nodes*)malloc(sizeof(struct Nodes));
    temp->left=NULL;
    temp->right=NULL;
    temp->value=value;

    *header=temp;

    }else{
        if ((*header)->value >= value){
            insert_value(&((*header)->left),value);
        }else{
            insert_value(&((*header)->right),value);
        }
    }

}
int  search(struct Nodes* header,int value){

    if (header==NULL) return -1;
    
    if (header->value==value){
        return 0;
    }else if (header->value > value){
            return search(header->left,value);
    }
    return search (header->right,value);
    
}
struct Nodes* minimum_value_tree(struct Nodes* header){
    if (header==NULL) return header;
    int minimum=header->value;
    struct Nodes* minimum_value=header;
    while(header!=NULL){
       
        minimum=minimum<header->value?minimum:header->value;
        if (minimum==header->value){
            minimum_value=header;
        }
         header=header->left;
    }

    return minimum_value;


}
void print_tree(struct Nodes *header){
    if (header==NULL){
        return;
    }
    printf("%d \n",header->value);
    print_tree(header->left);
    print_tree(header->right);


}
struct Nodes* traversal(struct Nodes* header,int value){
    if (header==NULL){
        return NULL;
    }
    if (header->left->value==value){
        return header;
    }
    if (header->value >=value){
        return traversal(header->left,value);

    }
    return traversal(header->right,value);
}

void delete(struct Nodes** header, int value) {
    struct Nodes** parent = header;  // Initialize parent correctly
    struct Nodes** child = header;   // Pointer to track node to delete

    if (*child == NULL) return; // If tree is empty, return

    // Find the node with target value and track its parent
    while (*child != NULL && (*child)->value != value) {
        parent = child;  // Update parent before moving child

        if ((*child)->value > value) {
            child = &((*child)->left);
        } else {
            child = &((*child)->right);
        }
    }

    // If the node wasn't found
    if (*child == NULL) return;

    printf("fine till now %d  %d \n", (*parent)->value, (*child)->value);

    // Case 1: Node has at most one child
    if ((*child)->left == NULL || (*child)->right == NULL) {
        struct Nodes* temp = *child;
        struct Nodes* newChild = (*child)->left ? (*child)->left : (*child)->right;

        // Update the parent’s child pointer
        if (*parent == temp) { // Deleting root node case
            *header = newChild;
        } else if ((*parent)->left == temp) {
            (*parent)->left = newChild;
        } else {
            (*parent)->right = newChild;
        }

        free(temp);
        return;
    }

    // Case 2: Node has two children
    struct Nodes* min_value = minimum_value_tree((*child)->right);
    (*child)->value = min_value->value;
    delete(&((*child)->right), min_value->value); // Recursive delete for duplicate
}
`

int main(void){
    insert_value(&header,-99);
    insert_value(&header,3);
    insert_value(&header,-1);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    delete(&header,-1);

    print_tree(header);
    printf("%d",header->value);
    printf("the minimum value is teh %d\n",minimum_value_tree(header)->value);
    // printf("%d %d\n",search(header,3),search(header,2));
}