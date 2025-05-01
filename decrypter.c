#include <stdio.h>
#include <string.h>
#include <ctype.h>


int string_length(char st[]);



int string_length(char st[]){
    // char check = st; 
    int i = 0;
    int count; 
    while(st[i] != '\0'){
        i++; 
    } 
    return i;
}


void decrypter(char st[], int numbers[]);


void decrypter(char st[], int numbers[]){
    for(int i = 0; i < string_length(st); i++){
        if(isalpha(st[i])){
            if(islower(st[i])){
                st[i] = (st[i] - 'a' - numbers[i] + 26) % 26 + 'a';
            }
            else if(isupper(st[i])){
                st[i] = (st[i] - 'A' - numbers[i] + 26) % 26 + 'A';
            }        
        }else if(isdigit(st[i])){
                st[i] = (st[i] - '0' - numbers[i] + 10) % 10 + '0'; 
            }

    }
    printf("Decrypted : %s\n" ,st);
}



int main(){
    char st[2462] = "fqpm ku jdd ";
    int numbers[] = {5,4,1,1,9,2,2,5,3,3,5,6};
    // fgets(st, 2462, stdin);
    decrypter(st, numbers);
    // char st[] = "snow";
    // printf("The length of the string is %d", string_length(st));
    return 0; 
}