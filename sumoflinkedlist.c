void add_data(int val,struct ListNode** header){
    struct ListNode* returndata=malloc(sizeof(*returndata));
    returndata->val=val;
    returndata->next=NULL;
    struct ListNode* temp=*header;
    if (*header==NULL){
        *header=returndata;
        return ;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=returndata;
    return;
}
void addstruct(struct ListNode* data,struct ListNode**header){
    struct ListNode* temp=*header;
    if (*header==NULL){
        *header=data;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=data;
    return;

}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1==NULL && list2==NULL){
        return NULL;
    }else if (list1==NULL){
        return list2;
    }else if (list2==NULL){
        return list1;
    }
    struct ListNode * header=NULL;
    while(list1!=NULL && list2!=NULL){
        
        if(list1->val<list2->val){
            
            add_data(list1->val,&header);
            list1=list1->next;
        }else{
            add_data(list2->val,&header);
            list2=list2->next;

        }
    }
    if (list1==NULL){
        addstruct(list2,&header);
    }else if (list2==NULL){
        addstruct(list1,&header);
    }
    
    return header;

    
}
