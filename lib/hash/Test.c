#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int main(void){

    char *word = "g";

    unsigned long hash = 0;
 
    for(int i = 0; i < strlen(word); i++){
        int position = word[i] - 'a' + 1;

        hash += position * pow(26,i);
    }

    printf("%ld\n", hash);
}