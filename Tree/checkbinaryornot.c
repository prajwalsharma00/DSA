#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
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
        if (current->value <= value){
            if (current->right==NULL){
                current->right=create_Node(value);
                return;
            }
            current=current->right;
        }
    }
}
// int isSubTreeLesser(struct Node* root,int value){
//     if (root==NULL){
//         return 1;
//     }
//     if (root->value>=value) return 0;
//     return (isSubTreelesser(root->left,value) && isSubTreeLesser(root->right,value) ); 


// }

// int isSubTreeGreater(struct Node* root,int value){
//     if (root==NULL){
//         return 1;
//     }
//     if (root->value <=value ) return 0;
//     return (isSubTreeGreater(root->left,value) && issubTreeGreater(root->right,value));



// }

// int check_binary_search_or_not(struct Node *header){
//     if (header==NULL) return 1;
//     if (isSubTreeGreater(header->right,header->value)
//     &&isSubTreeLesser(header->left,header->value) 
//     && check_binary_search_or_not(header->left)
//      && check_binary_search_or_not(header->right)){
//         return 1;
//     }
//     return 0;

// }
void print_tree(struct Node *header){
    if (header==NULL){
        return;
    }
   
    print_tree(header->left);
    printf("%d \n",header->value);
    print_tree(header->right);


}

// using the min and max constraint

int isBinarySearchTree(struct Node* root,int min,int max){
    if (root==NULL){
        return 1;
    }
    printf("root value %d \n",root->value);
    if (root->value >=min && root->value<= max &&
    isBinarySearchTree(root->left,min,root->value)&&
    isBinarySearchTree(root->right,root->value ,max)){
        return 1;
    }
    return 0;
}

int main(){
    insert_value(&header,7);
    insert_value(&header,4);
    insert_value(&header,9);

    insert_value(&header,1);
    insert_value(&header,6);
    insert_value(&header,4);
    print_tree(header);

    printf("%d",isBinarySearchTree(header,INT_MIN,INT_MAX));
}