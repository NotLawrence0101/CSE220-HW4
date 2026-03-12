// Name: Lawrence Wong
// Student ID: 116408194

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

    // Accounts for size being 0 and NULL inputs
    if(size == 0 || destination == NULL || source == NULL)
        return;

    size_t i = 0;

    // Copies the source to destination while source wasn't string terminator
    while(i < size-1 && source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }

    // Ends the string with a string terminator
    destination[i] = '\0';
}

void strgChangeCase(char *s) {
    (void)s;

    // Uses the previous get string length function
    int len = strgLen(s);

    // Returns if s is NULL and length of string is 0
    if(s == NULL || len == 0){
        return;
    }

    for(int i = 0; i < len; i++){
        // Checks if the left neighbor of the index is a digit or not
        int isLeftDigit = (i > 0 && s[i-1] >= '0' && s[i-1] <= '9');
        // Checks if the right neighbor of the index is a digit or not
        int isRightDigit = (i < len-1 && s[i+1] >= '0' && s[i+1] <= '9');

        // Combines both digit checks to check if there is an adjacent digit to the current char
        if(!isLeftDigit && !isRightDigit){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] -= 32; // Deincrements to change lowercase to uppercase through ascii values
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32; // Increments to change uppercase to lowercase through ascii values
            }
        }
    }
}

int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;

    // Returns -2 if any of the strings are NULL
    if(s1 == NULL || s2 == NULL){
        return -2;
    }

    // Get the string lengths and initialize max and isEqual
    int len1 = strgLen(s1);
    int len2 = strgLen(s2);
    int max;
    int isEqual = 0;

    // Gets the max size value between the two strings
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
    
    // Iterates through the max size value and checks if either of the strings are different character by character
    for(int i = 0; i < max; i++){
        if(*s1 != *s2){
            return i;
        }
        s1++;
        s2++;
    }
    // Returns -1 for if the string length is equal and there are no differences found from the above for loop
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

    // Accounts for if the destination is NULL or size is 0
    if(size == 0 || d == NULL){
        return;
    }

    // Accounts for string1 or string2 is NULL
    if(s1 == NULL || s2 == NULL){
        d[0] = '\0';
        return;
    }
    
    // Keep track of the indices of the string1 and string2 and the index of destination
    size_t s1Index = 0;
    size_t s2Index = 0;
    size_t i = 0;

    while(i < size-1 && (s1[s1Index] != '\0' || s2[s2Index] != '\0')){
        if(s1[s1Index] != '\0' && i < size-1){
            d[i] = s1[s1Index];
            i++;
            s1Index++;
        }
        if(s2[s2Index] != '\0' && i < size-1){
            d[i] = s2[s2Index];
            i++;
            s2Index++;
        }
    }
    d[i] = '\0';
}

void strgReverseLetters(char *s) {
    (void) s;

    // Accounts for s being NULL
    if (s == NULL) {
        return;
    }

    int len = strgLen(s);

    // Accounts for length being 1 or less than, because reversing results in the same
    if (len <= 1) {
        return;
    }

    // Assign two left and right pointers for the string
    char *left = s;
    char *right = s + len - 1;

    while(left < right) {
        // Move left pointer to next letter if it is not a letter and there is enough space
        while(left < right && !((*left >= 'a' && *left <= 'z') || (*left >= 'A' && *left <= 'Z'))) {
            left++;
        }

        // Move right pointer to previous letter if it is not a letter and there is enough space
        while(left < right && !((*right >= 'a' && *right <= 'z') || (*right >= 'A' && *right <= 'Z'))) {
            right--;
        }

        // Swap letters if right is greater than left
        if (left < right) {
            char temp = *left;
            *left = *right;
            *right = temp;

            left++;
            right--;
        }
    }
}
