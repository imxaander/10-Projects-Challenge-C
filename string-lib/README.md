# Imxaander String Function Library

This project aims to create simple C functions that utilizes macros and ascii. 


## Function descriptions
`__u_int getStringLength(char* s);`

 - Description: Calculates the length of the provided string without using strlen. It iterates over each character until it reaches the null terminator ('\0').
 - Parameters:
    - `char* s`: Pointer to the input string.
 - Returns: The length of the string, including the null terminator.


`char* concatString(char* s1, char* s2);`
 - Description: Concatenates two strings, s1 and s2, by allocating memory for the combined length and appending s2 to s1.
 - Parameters:
   - `char* s1`: First string.
   - `char* s2`: Second string to append to s1.
 - Returns: A pointer to the concatenated string. Remember to free the returned string after use to avoid memory leaks.

`bool compareString(char* s1, char* s2);`
 - Description: Compares two strings, s1 and s2, to check if they are identical in length and content.
 - Parameters:
   - char* s1: First string.
   - char* s2: Second string.
 - Returns: true if the strings are identical, false otherwise.

`char* reverseString(char* s);`
 - Description: Reverses the input string by allocating memory for the reversed version.
 - Parameters:
   - char* s: The input string.
 - Returns: A pointer to the reversed string. Free the returned string after use.

`void changeCaseString(char* s, int type);`
 - Description: Converts the case of each character in the string based on the type parameter.
    - type = STRING_CASE_LOWERCASE (1): Converts the string to lowercase.
    - type = STRING_CASE_UPPERCASE (2): Converts the string to uppercase.
 - Parameters:
   - `char* s: Pointer to the string to modify.`
   - int type: Conversion type (use STRING_CASE_UPPERCASE or STRING_CASE_LOWERCASE).

`char toLowerCase(char c);`
 - Description: Converts an uppercase character to lowercase. If the character is already lowercase or is not a letter, it returns the character as-is.
 - Parameters:
   - `char c`: The character to convert.
 - Returns: The lowercase equivalent of c, if applicable.

`char toUpperCase(char c);`
 - Description: Converts a lowercase character to uppercase. If the character is already uppercase or is not a letter, it returns the character as-is.
 - Parameters:
   - `char c`: The character to convert.
 - Returns: The uppercase equivalent of c, if applicable.
