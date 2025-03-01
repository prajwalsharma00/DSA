

struct counter{
    int value;
    int count;
    struct counter *next;
};
struct counter* addstruct(int value){
    struct counter* newstruct=malloc(sizeof(*newstruct));
    newstruct->value=value;
    newstruct->count=1;
    newstruct->next=NULL;
    return newstruct;

}
void add(int value,struct counter** header){
    struct counter* temp=*header;
    printf("reached here \n");
    if (*header==NULL){
        *header=addstruct(value);
        return;
        
    }
    printf("reached here 111\n");
    
    while(temp->next!=NULL){
        if(temp->value==value){
            temp->count++;
            return;
        }
        temp=temp->next;
    }
    if (temp->value==value){
        temp->count++;
    }
    temp->next=addstruct(value);
    return ;



}
void printstruct(struct counter* header){
    struct counter *temp=header;
    while(temp!=NULL){
        printf("%d --\n",temp->value);
        temp=temp->next;
    }
}
int maximum(struct counter* header){
    printf("reached till here  %d \n ",header->count);
    int count=0;
    
    int value=-1;
    while(header!=NULL){
        count=count>header->count?count:header->count;
        value=count>header->count?value:header->value;
        header=header->next;
    }
    return value;
}
int majorityElement(int* nums, int numsSize) {
    struct counter* header;
    for (int i=0;i<numsSize;i++){
        add(nums[i],&header);

    }
    printf("vlaue\n");
    return maximum(header);

    
}
