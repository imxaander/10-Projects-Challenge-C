#include <stdlib.h>
#include <stdio.h>
#include "strimx.h"

int main(){
    char s[] = "xander ";
    // check the length of s
    printf("String length: %d\n", getStringLength(s));

    char s2[] = "isoN";
    printf("Concat String : %s\n", concatString(s, s2));
    printf("Concat String length: %d\n", getStringLength(concatString(s, s2)));

    char s3[] = "isoN";
    printf("s vs. s2 : %d\ns2 vs. s3: %d\n", compareString(s, s2), compareString(s2, s3));

    printf("%c", toUpperCase('c'));
    printf("Reversed : %s\n", reverseString(s3));

    changeCaseString(s2,  STRING_CASE_LOWERCASE);
    changeCaseString(s3, STRING_CASE_UPPERCASE);
    printf("LowerCase: %s\nUpperCase: %s",  s2, s3);
}