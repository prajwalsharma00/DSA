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

int min(){
    struct Node* temp=header;
    if (temp==NULL){
        return -1;
    }else{
       while(temp->left!=NULL){
        temp=temp->left;

       }
       return temp->value;

    }
}

int max(struct Node *temp){
    // struct Node* temp=header;
    // if (temp==NULL){
    //     return -1;
    // }else{
    //    while(temp->right!=NULL){
    //     temp=temp->right;

    //    }
    //    return temp->value;

    // }
    //recursive solution 
    if (temp==NULL){
        return -1;
    }
    if (temp->right==NULL){
        return temp->value;
    }
    return max(temp->right);
    
}
int main(){
    insert_value(&header,99);
    insert_value(&header,3);
    insert_value(&header,-2);
    insert_value(&header,2);
    insert_value(&header,4);
    insert_value(&header,10);
    printf("%d",min());
    printf("\n%d",max(header));
}
