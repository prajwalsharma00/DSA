#include<stdio.h>
#include<stdlib.h>


struct Nodes{
    int value;
    struct Nodes* left;
    struct Nodes* right;

};

struct Nodes * header;
struct Nodes* create_Node(int value){
    struct Nodes* temp=(struct Nodes*)malloc(sizeof(struct Nodes));
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert_value(struct Nodes **temp,int value){

    if(*temp==NULL){
        *temp=create_Node(value);
        return;
    }
    struct Nodes *current=*temp;  
//    while (1) {
//         if (value < current->value) {
//             if (current->left == NULL) {
//                 current->left = create_Node(value);  // ✅ Changes actual tree
//                 return;
//             }
//             current = current->left;  // ✅ Moves the pointer, but doesn’t modify header
//         } else {
//             if (current->right == NULL) {
//                 current->right = create_Node(value);
//                 return;
//             }
//             current = current->right;
//         }
//     }
    

void print_tree(struct Nodes* header){
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
     insert_value(&header,10);
    insert_value(&header,20);
    printf("%d",header->value);
    print_tree(header);
    

    // print_tree(header);

}