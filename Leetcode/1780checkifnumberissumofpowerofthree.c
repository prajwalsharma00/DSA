#include<math.h>
bool checker(int n){
    printf("%d\n",n);
    if (n==1 || n<0){
        return true;
    }
    if (n%3!=0){
        if ((n-1)%3==0){
            return checker(n-1);
        }else{
            return false;
        }
    }
    if (n==1){
        return true;
    }else{
        return checker(n/3);
    }
    
}

bool checkPowersOfThree(int n) {
    return checker(n);
    
}
