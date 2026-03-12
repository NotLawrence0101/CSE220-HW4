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

    int pLen = strgLen(plaintext);
    int max = strgLen(ciphertext);

    // Check if there is space for "__EOM__"
    if (pLen + 7 > max) {
        return -1;
    }

    int i = 0;

    while (plaintext[i] != '\0') {

        // Initialize the letter and 
        char c = plaintext[i];
        int shift = key + i;

        // Checks for if the letter is a lower or upper case letter and shifts the letter accordingly or keeps the same char if not a letter
        if (c >= 'a' && c <= 'z') {
            ciphertext[i] = ((c - 'a' + shift) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = ((c - 'A' + shift) % 26) + 'A';
        }
        else {
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
    (void)ciphertext;
    (void)plaintext;
    (void)key;
    if(ciphertext == NULL || plaintext == NULL){
        return -2;
    }

    int capacity = strgLen(plaintext);

    if(capacity == 0){
        return 0;
    }

    // Find the EOM marker of the string and store the index
    int eomIndex = -1;
    for(int i = 0; ciphertext[i] != '\0'; i++){
        if(ciphertext[i] == '_' &&
           ciphertext[i+1] == '_' &&
           ciphertext[i+2] == 'E' &&
           ciphertext[i+3] == 'O' &&
           ciphertext[i+4] == 'M' &&
           ciphertext[i+5] == '_' &&
           ciphertext[i+6] == '_'){
            eomIndex = i;
            break;
        }
    }

    // Accounts for if there is no EOM marker in the string and returns -1
    if(eomIndex == -1){
        return -1;
    }
    
    int decodedCount = 0;
    int limit = capacity - 1;

    for(int i = 0; i < eomIndex && i < limit; i++){

        char c = ciphertext[i];
        int shift = key + i;

        if(c >= 'a' && c <= 'z'){
            int val = (c - 'a' - shift) % 26;
            if(val < 0) val += 26;
            plaintext[i] = val + 'a';
            decodedCount++;
        }
        else if(c >= 'A' && c <= 'Z'){
            int val = (c - 'A' - shift) % 26;
            if(val < 0) val += 26;
            plaintext[i] = val + 'A';
            decodedCount++;
        }
        else{
            plaintext[i] = c;
        }
    }

    int end = (eomIndex < limit) ? eomIndex : limit;
    plaintext[end] = '\0';

    return decodedCount;
}
