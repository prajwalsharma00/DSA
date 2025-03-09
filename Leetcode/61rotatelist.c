/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int nodes_calculator(struct ListNode* head){
    int nodes=0;
    while(head){
        nodes++;
        head=head->next;
    }
    return nodes;
}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head==NULL) return head;
    if (head->next==NULL) return head;
    struct ListNode* temp=head;
    struct ListNode* temp_head;
    struct ListNode *lastnode;
    int nodes=nodes_calculator(head);
    k=k%nodes;
    for(int i=0;i<k;i++){
        while(temp->next){
            lastnode=temp;
            temp=temp->next;

            if (temp->next==NULL){

                lastnode->next=NULL;
                
                break;
            }
        }
        temp_head=temp;
        temp_head->next=head;
        head=temp_head; //dd->a
        

    }
    
    
    return head;
}
