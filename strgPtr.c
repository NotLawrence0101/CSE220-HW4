#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int strgLen(const char *s) {
    (void)s;

    // Returns if s is NULL
    if(s == NULL){
        return -1;
    }
    int i = 0;
    // Increments through the string until it reaches the '\0' character 
    while(*s != '\0') {
        i++;
        s++;
    }
    return i;
}

void strgCopy(const char *source, char *destination, size_t size) {
    (void)source;
    (void)destination;
    (void)size;

    if(size == 0 || destination == NULL || source == NULL)
        return;

    size_t i = 0;

    while(i < size-1 && source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    
    destination[i] = '\0';
}

void strgChangeCase(char *s) {
    (void)s;
    /* TODO */

    // Uses the previous get string length function
    int len = strgLen(s);
    // Returns if s is NULL and length of string is 0
    if(!s || len == 0){
        return;
    }
    for(int i = 0; i < len; i++){
        // Checks if the left neighbor of the index is a digit or not
        int isLeftDigit = (i > 0 && *(s-1) >= '0' && *(s-1) <= '9');
        // Checks if the right neighbor of the index is a digit or not
        int isRightDigit = (i < len-1 && *(s+1) >= '0' && *(s+1) <= '9');
        if(!isLeftDigit && !isRightDigit){
            if(*s >= 'a' && *s <= 'z'){
                *s -= 32; // Deincrements to change lowercase to uppercase through ascii values
            }
            else if(*s >= 'A' && *s <= 'Z'){
                *s += 32; // Increments to change uppercase to lowercase through ascii values
            }
            s++;
        }
    }
}

int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;
    /* TODO */
    if(s1 == NULL || s2 == NULL){
        return -2;
    }

    int len1 = strgLen(s1);
    int len2 = strgLen(s2);
    int max;
    int isEqual = 0;

    if(len1 > len2){
        max = len2;
    }
    else if(len1 < len2){
        max = len1;
    }
    else{
        isEqual = 1;
        max = len1;
    }
    
    for(int i = 0; i < max; i++){
        if(*s1 != *s2){
            return i;
        }
        s1++;
        s2++;
    }
    if(isEqual){
        return -1;
    }
    return max;
}

void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
    /* TODO */
}

void strgReverseLetters(char *s) {
    (void)s;
    /* TODO */
}
