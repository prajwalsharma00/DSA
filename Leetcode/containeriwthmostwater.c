int maxArea(int* height, int heightSize) {
    int size=0;
    int first_index=0;
    int second_index=heightSize-1;
    while(first_index!=second_index){
        int difference=second_index-first_index;
        int min=*(height+first_index)<*(height+second_index)?*(height+first_index):*(height+second_index);

        int temp_size=difference*min;
        
        
        if(*(height+first_index)==min){
                first_index++;
            }
        else{
                second_index--;
            }
        

            
        
        size=temp_size>size?temp_size:size;
    }
    
    return size;
    
}
