
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
    struct Nodes* temp=(struct Nodes*)malloc(sizeof(struct Nodes));
    temp->left=NULL;
    temp->right=NULL;
    temp->value=value;

    if (*header==NULL){
        *header=temp;

    }else{
        if ((*header)->value > value){
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
void print_tree(struct Nodes *header){
    if (header==NULL){
        return;
    }
    printf("%d \n",header->value);
    print_tree(header->left);
    print_tree(header->right);


}

int main(void){
    insert_value(&header,1);
    insert_value(&header,3);
    insert_value(&header,-1);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    print_tree(header);
    printf("%d %d\n",search(header,3),search(header,2));
}