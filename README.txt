Name: Lawrence Wong
Student ID: 116408194

CSE 220 HW4 README FILE

Test cases are located in the test_strg.c file and the test_caesar.c files respectively and can be run by running "make test".
The test cases are sectioned off by comments for each function in the files.


test_strg.c Test Cases:

strgLen Test Cases:
• Tests for regular basic use with "Hello" and single characters, which returns the size respectively.
• Tests counting spaces, symbols, numbers, letters, and any characters, which returns the size respectively.
• Tests NULL, which returns with -1.
• Tests empty string, which returns with 0.

strgCopy Test Cases:
• Tests for different array lengths, which  only copy up until the specified size additionally with a string terminator.
• Tests copying basic strings with chars, which copies the strings to the destination.
• Tests for copying spaces, symbols, numbers, letters, and any characters, which copies them respectively.
• Tests for NULL and empty string, which returns an empty string.

strgChangeCase Test Cases:
• Tests for adjacency for case changes, which letters does not change if adjacent to a number.
• Tests for upper and lower case letters, which changes the cases respectively if not adjacent to a number.
• Tests for two character strings with a number, which does not change the string.
• Tests for NULL string to copy, which returns with the specified char array.
• Tests for spaces and symbols, which returns unchanged except for only the letters.

strgDiff Test Cases:
• Tests for the same strings like "Hello" and "Hello", which returns with -1.
• Tests for different strings, which returns with 1.
• Tests for two empty strings, which returns -1.
• Tests for NULL in any of the strings, which returns with -2.
• Tests for spaces, which returns with 1 or 0 depending on if the strings are the same.

strgInterleave Test Cases:
• Tests for different char array lengths, which changes the char array to be the interwoven product.
• Tests for one string length larger than the other, which appends the rest of the larger string to the product after interweaving.
• Tests for single char and empty strings, which changes the char array respectively.
• Tests for NULL strings, which leaves the char array unchanged.
• Tests for interweaving spaces, which changes the char array accordingly.

strgReverseLetters Tests Cases:
• Tests for lowercase and uppercase letters in strings, which changes the char array to reverse the letters.
• Tests for numbers and other characters that are not letters, which reverses only the letters, but keeps the other characters in the same index.
• Tests for empty string, which leaves the char array unchanged.
• Tests for NULL char array, which leaves the char array unchanged.
• Tests for strings with only characters that are not letters, which leaves the string unchanged.
• Tests for palindromes, which changes the string, but results in the same result.

test_caesar.c Test Cases:

encryptCaesar Tests Cases:
• Tests for basic use, "hello", which changes the buffer to "jhpqu__EOM__" with the key and returns 5.
• Tests for NULL plaintext, which returns -2.
• Tests for the buffer and plaintext being too small for the EOM marker to be present in the ciphertext, which returns -1 and leaves the buffer char array unchanged.
• Tests for empty string, which changes the buffer to "undefined_EOM__", only if there is enough buffer space.
• Tests for numbers, which encrypts the numbers and wraps respectively.

decryptCaesar Tests Cases:
• Tests for basic use, "jhpqu__EOM__", which changes the buffer to "hello" with the key and returns 5.
• Tests for NULL string, which returns with -2 and leaves the buffer unchanged.
• Tests for if there is no EOM marker in the buffer array, which returns with -1 and leaves the buffer unchanged.
• Tests for "undefined__EOM__", which returns 0 and changes the buffer to say "undefined"
• Tests for numbers, which decrypts the numbers and wraps respectively.
