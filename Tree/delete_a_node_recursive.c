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


struct Nodes* deletenode(struct Nodes* header,int value){
    if (header==NULL) return header;
    else if (header->value>value) header->left=deletenode(header->left,value);
    else if (header->value<value) header->right=deletenode(header->right,value);
    else{
        //case 2. if eitehr one of the nodes are  i fit have one node
        if (header->right == NULL) {
            struct Nodes* temp = header;
            header=header->left;
            free(temp);
            temp=NULL;
        }
        else if (header->left == NULL) {
            struct Nodes* temp = header;
            header=header->right;
            free(temp);
            temp=NULL;
        }
        else{
            struct Nodes* lowest_value=minimum_value_tree(header);
            header->value=lowest_value->value;
            header->right=deletenode(header->right,lowest_value->value);
            
        }


    }

    return header;

}
int main(void){
    insert_value(&header,-99);
    insert_value(&header,3);
    insert_value(&header,-1);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    deletenode(header,-1);

    print_tree(header);
    printf("%d",header->value);
    printf("the minimum value is teh %d\n",minimum_value_tree(header)->value);
    // printf("%d %d\n",search(header,3),search(header,2));
}
