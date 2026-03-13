// Name: Lawrence Wong
// Student ID: 116408194

#include "cse_caesar.h"
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    (void) plaintext;
    (void) ciphertext;
    (void) key;

    // Accounts for if plaintext or ciphertext is NULL
    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }

    // Initialize lengths of inputted strings
    int pLen = strgLen(plaintext);

    // Accounts for if the plaintext is empty
    if (pLen == 0) {
        // Makes ciphertext read "undefined__EOM__" 
        int i = 0;
        char *temp = "undefined__EOM__";

        while (temp[i] != '\0') {
            ciphertext[i] = temp[i];
            i++;
        }
        ciphertext[i] = '\0';
        return 0;
    }

    // Check if there is space for the EOM marker
    if (pLen + 7 > strgLen(ciphertext)) {
        return -1;
    }

    int i = 0;

    while (plaintext[i] != '\0') {
        // Initialize the index plaintext letter
        char c = plaintext[i];
        int shift = key + i;

        if(c >= 'a' && c <= 'z'){ // Checks for if the letter is a lower case and shifts accordingly
            ciphertext[i] = ((c - 'a' + shift) % 26) + 'a';
        }
        else if(c >= 'A' && c <= 'Z'){ // Shifts capital letters accordingly
            ciphertext[i] = ((c - 'A' + shift) % 26) + 'A';
        }
        else if(c >= '0' && c <= '9'){ // Shifts numbers accordingly
            ciphertext[i] = ((c - '0' + shift) % 10) + '0';
        }
        else{ // Keeps all other characters that are not letters or numbers
            ciphertext[i] = c;
        }
        i++;
    }

    // Append "__EOM__" to the end of the resulting string
    ciphertext[i++] = '_';
    ciphertext[i++] = '_';
    ciphertext[i++] = 'E';
    ciphertext[i++] = 'O';
    ciphertext[i++] = 'M';
    ciphertext[i++] = '_';
    ciphertext[i++] = '_';

    // Close the string with a string terminator
    ciphertext[i] = '\0';

    return pLen;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    (void) ciphertext;
    (void) plaintext;
    (void) key;

    // Accounts for NULL inputs
    if(ciphertext == NULL || plaintext == NULL){
        return -2;
    }

    int capacity = strgLen(plaintext);

    // Accounts for empty string
    if(capacity == 0){
        return 0;
    }

    // Find the EOM marker if there is one and notes the index of it
    int eomIndex = -1;
    for(int i = 0; ciphertext[i] != '\0'; i++){
        if(ciphertext[i]=='_' && ciphertext[i+1]=='_' &&
            ciphertext[i+2]=='E' && ciphertext[i+3]=='O' &&
            ciphertext[i+4]=='M' && ciphertext[i+5]=='_' &&
            ciphertext[i+6]=='_'){
        // Check for undefined__EOM__
            if(i == 9 &&
                ciphertext[0]=='u' && ciphertext[1]=='n' &&
                ciphertext[2]=='d' && ciphertext[3]=='e' &&
                ciphertext[4]=='f' && ciphertext[5]=='i' &&
                ciphertext[6]=='n' && ciphertext[7]=='e' &&
                ciphertext[8]=='d'){
                    // Makes plaintext read "undefined" 
                    int j = 0;
                    char *temp = "undefined";

                    while (temp[j] != '\0'){
                        plaintext[j] = temp[j];
                        j++;
                    }
                    plaintext[j] = '\0';
                    return 0;
            }
            eomIndex = i;
            break;
        }
    }

    // Accounts for no EOM marker in the string
    if(eomIndex == -1){
        return -1;
    }

    int decoded = 0;
    int i = 0;

    // Itterates until EOM marker and at the end of the string
    while(i < eomIndex && i < capacity - 1){
        char c = ciphertext[i];
        int shift = key + i;

        if(c >= 'a' && c <= 'z'){ // Decodes the characters that are lower case
            int val = (c - 'a' - shift) % 26;
            if(val < 0){
                val += 26;
            }
            plaintext[i] = val + 'a';
            decoded++;
        }
        else if(c >= 'A' && c <= 'Z'){ // Decodes the characters that are upper case
            int val = (c - 'A' - shift) % 26;
            if(val < 0){ 
                val += 26;
            }
            plaintext[i] = val + 'A';
            decoded++;
        }
        else if(c >= '0' && c <= '9'){ // Decodes the characters that are numbers
            int val = (c - '0' - shift) % 10;
            if(val < 0){ 
                val += 10;
            }
            plaintext[i] = val + '0';
            decoded++;
        }
        else{
            plaintext[i] = c;
        }
        i++;
    }

    plaintext[i] = '\0';

    return decoded;
}