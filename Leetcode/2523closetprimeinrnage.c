/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdbool.h>
#include<math.h>
bool prime(int n){
    if (n<=1) return false;
     if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int * prime_finder(int first,int last,int* returnindex){
    int value=10;
    int *primes=malloc(sizeof(int)*value);
    int index=0;
    for (int i=first;i<=last;i++){
        if (index==value){
            value*=2;
            int *temp=realloc(primes,sizeof(*primes)*value);
            if (temp==NULL){
                free(temp);
            }else{
                primes=temp;
            }
        }
        if (prime(i)){
            primes[index++]=i;
        }

    }
    *returnindex=index;
    return primes;
    

}
int *minimumrange(int* primes,int index){
    int *answer=malloc(sizeof(int)*2);
    memset(answer,-1,sizeof(int)*2);

    if (index<2){
        return answer;
    }

    int first_prime=-1,second_prime=-1,difference=primes[1]-primes[0]+1;
  
    for (int i=0;i<index-1;i++){
        int temp_difference=primes[i+1]-primes[i];
    
        if (temp_difference<difference){
            first_prime=primes[i];
            second_prime=primes[i+1];
            difference=temp_difference;
        
        }
    }
    free(primes);
    
    answer[0]=first_prime;
    answer[1]=second_prime;
    return answer;
}
int* closestPrimes(int left, int right, int* returnSize) {
    int *answer;
     *returnSize=2;
    int *primes;
    int index;

    primes=prime_finder(left,right,&index);
    answer=minimumrange(primes,index);

    return answer;
    
}

