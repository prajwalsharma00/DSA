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
//queue for the implementaiont of the level order 
struct queue{
    struct Node * data;
    struct queue* next;
};
struct queue* queue_header=NULL;
struct queue* queue_rear=NULL;
struct queue* add_value(struct Node *data){
    struct queue* a=(struct queue*)malloc(sizeof(struct queue));
    a->data=data;
    a->next=NULL;
    return a;
    

}

void enqueue(struct Node *data){
    if (data==NULL) return;
    if (queue_header==NULL){
        queue_header=add_value(data);
        queue_rear=queue_header;
        return;
        
    }

    queue_rear->next=add_value(data);
    queue_rear=queue_rear->next;
    return;
}

struct Node* dequeue(){

    if (queue_header==NULL){

        return NULL;
    }
    struct Node* temp=queue_header->data;
    struct queue* temp_queque=queue_header;
    queue_header=queue_header->next;
    free(temp_queque);
    if (queue_header==NULL) queue_rear=NULL;
    return temp;

}


int isempty(){
    if (queue_header==NULL){
        return 0;
    }
    return 1;
}
void level_order_traversal(struct Node *header){
    if (header==NULL){

        return;
    }
    enqueue(header);
    while(isempty()){
        struct Node *current=dequeue();
        printf("%d ",current->value);

        if (current->left) enqueue(current->left); 
        if (current->right) enqueue(current->right); 
    }

    }





int main(){
    insert_value(&header,1);
    insert_value(&header,10);
    insert_value(&header,-2);
    insert_value(&header,-20);
    insert_value(&header,40);
    insert_value(&header,100);

    level_order_traversal(header);
    //level order shoudl be 1 -2 10 -20 40 100 
}