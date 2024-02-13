#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXBUFFERSIZE     80000
char buffer[MAXBUFFERSIZE];
char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
int k;

void getAnInput();
void encrypt(char c[]);
char rotate(char c);
char *get_string();

char *get_string() {
    char *str = malloc(sizeof(char) * 1000);
    if (str != NULL)
    {
        fgets(str, 1000, stdin);
    } else {
        return NULL;
    }
    return str;
    
}



void getAnInput() {
    char c;
    int valid_choice = 0;
    int char_count;
    do  {
        c = getchar();
        char_count = 0;
        while (c != '\n' && char_count < MAXBUFFERSIZE)  {
            buffer[char_count++] = c;
            c = getchar();
        }
        buffer[char_count] = 0x00;
        valid_choice = 1;
    } while (valid_choice == 0);
}

char rotate(char c) {
    char ci;
    for (size_t i = 0; i < 26; i++)  {
        if (c == alphabet[i]) {
            return alphabet[(i + k) % 26]; 
        } else if (c == toupper(alphabet[i])) {
            return toupper(alphabet[(i + k) % 26]);
        }  
    }
    return c;      
}

void encrypt(char c[]) {
    for (size_t i = 0; i < strlen(c) ; i++)  {
       c[i] = rotate(c[i]);
    } 
}



int main(int argc, char *argv[]) {
    getAnInput();
    k = atoi(buffer);
    if (argc == 2 && k > 0 && k ==(int)k)   {
         printf("Success! ");
         printf("%d\n", k)    ;
    } else {
        printf("Key :");
        return 1;
    }
    printf("plaintext : ");
    getAnInput();
    encrypt(buffer);
    printf("ciphertext ; ");
    printf("%s\n", buffer);
    return 0;
}