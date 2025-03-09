bool isalternative(int *color,int colorsize,int* counter){
    int count=0;
    int first_color=color[0];
    for (int i=1;i<colorsize;i++){
        if (color[i]==first_color){
            count=i-1;
            return false;
        }
        first_color=color[i];
    }
    *counter=count;
    return true;
}
int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int index=colorsSize+(k-1);
    int* color = malloc(sizeof(int) *index);
    memcpy(color, colors, colorsSize * sizeof(int));
    memcpy(color + colorsSize, colors, (k-1) * sizeof(int));
    int window_size=k-1;//2
    int bool_check=0;
    int value=0;
    int counter;
    for (int i=0;window_size<index;i++){
        if (!bool_check){
           
            bool_check=isalternative(color+i,k,&counter);
            if (bool_check){
                value++;
                
            }else{
                i+=counter;
            }//good till now 
            window_size++;
        }else{
           
            if (window_size>=index){
                
                value++;
            }
            else if (color[window_size-1]!=color[window_size]){
      
                value++;
                window_size++;
            }else{x
                
                i=(window_size-1);
                
                window_size+=(k-1);
             
                bool_check=0;
            }
        }
        
    }
    free(color);
    return value;
}
