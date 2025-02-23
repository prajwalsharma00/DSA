#include<math.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int array[nums1Size+nums2Size];
    int index=0;
    int index_first_array=0;
    int index_second_array=0;
    while(index_first_array<nums1Size && index_second_array<nums2Size){
        if (nums1[index_first_array]<nums2[index_second_array]){
            array[index++]=nums1[index_first_array++];
        }else{
            array[index++]=nums2[index_second_array++];
        }

    }
    if(index_first_array>=nums1Size){
        for (int i=index_second_array;i<nums2Size;i++){
            array[index++]=nums2[i];
        }

    }else{
        for (int i=index_first_array;i<nums1Size;i++){
            array[index++]=nums1[i];
        }
    }

    double middle=(index-1)/2.0;
  
    if (fmod(middle,1)==0){
        int value=middle;
        
        return array[value];
    }
    int idx1 = (int)floor(middle);
    int idx2 = (int)ceil(middle);
    double answer = (array[idx1] + array[idx2]) / 2.0;
    return answer;
    
}
