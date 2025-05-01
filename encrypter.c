#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



// int intcspn(int numbers[], int size_numbers, int);


// int intcspn(int numbers[], int size_numbers, int num){
//     for(int i = 0; i < size_numbers; i++){
//         if(numbers[i] == num)
//     }
// }



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

int random_number_generator();


int random_number_generator(){
    int random = (rand() % 10) + 1; 
    return random;
}


void encrypter(char st[], int numbers[]);


void encrypter(char st[], int numbers[]){ 
    for(int i = 0; i < string_length(st); i++){
        numbers[i] = random_number_generator();
        if(isalpha(st[i])){
            if(islower(st[i])){
                while(numbers[i] > 5){
                    numbers[i] = random_number_generator();
                }
                st[i] = (st[i] - 'a' + numbers[i]) % 26 + 'a';
            }
            else if(isupper(st[i])){
                while(numbers[i] > 6){
                    numbers[i] = random_number_generator();
                }
                st[i] = (st[i] - 'A' + numbers[i]) % 26 + 'A';
            }
        
        }else if(isdigit(st[i])){
                st[i] = (st[i] - '0' + numbers[i]) % 10 + '0'; 
            }
    }
    printf("Encrypted : %s\n" ,st);
}



int main(){
    srand(time(0));
    char st[2462];
    int numbers[1234];
    fgets(st, 2462, stdin);
    st[strcspn(st, "\n")] = '\0';
    encrypter(st, numbers);
    for(int i = 0; i < string_length(st); i++){
        printf("%d", numbers[i]);
        if(i < string_length(st)- 1){
            printf(",");
            }
    } 
    printf("\n");
    // decrypter(st, numbers);
    // char st[] = "snow";
    // printf("The length of the string is %d", string_length(st));
    return 0; 
}