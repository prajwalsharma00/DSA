
#include<string.h>
bool isalltwo(int alphabet[],int index){
    int count=alphabet[(index)%26];
    for (int i=0;i<26;i++){
        if (alphabet[i]==0){

        }else if (alphabet[i]!=count){
            return false;
        }

    }
    return true;
}

bool areOccurrencesEqual(char* s) {
    int alphabet[26];
    memset(alphabet,0,sizeof(alphabet));
    for (int i=0;i<strlen(s);i++){
        int index=(s[i])%26;
        alphabet[index]++;
 
    };
    return isalltwo(alphabet,s[0]);



}
