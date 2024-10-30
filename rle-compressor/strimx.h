#ifndef STRIMX
#define STRIMX 

#define STRING_CASE_UPPERCASE 2
#define STRING_CASE_LOWERCASE 1

#include <malloc.h>
#include <stdbool.h>


// FUNCTION DECLARATIONS
char toLowerCase(char c);
char toUpperCase(char c);

/* 
    GOALS: finding the:
    length - DONE , 
    concatenation, 
    comparison, 
    reversing a string, 
    and case conversion. 
*/ 


// in getting string length, we just need to use
// strlen() function. but for the sake of this project...

// Note: u cannot use sizeof() here because sizeof() only checks the pointer's size
// when you check the size of a character pointer, it will return 4 or 8 bytes (size of character in bytes)
// but it depends on your system.
__u_int getStringLength(char* s){
    unsigned int i = 0;
    while(*(s+i) != '\0'){
        i++;
    }
    // +1 because of the ending \0
    return i+1;
}

// concatString returns char* of a string that is concatenated s1 + s2
char* concatString(char* s1, char* s2){
    // to concatenate string, we can use getStringLength() tio get the length 
    // and then allocate the memory for that addition of string 
    __u_int s1_size = getStringLength(s1);
    __u_int s2_size = getStringLength(s2);
    __u_int cS_size = s1_size + s2_size - 1;
    // printf("%d", cS_size);
    char* cS = (char*) malloc((cS_size) * sizeof(char));
    
    for(__u_int i = 0; i < cS_size; i++){
        if(i < s1_size-1){
            *(cS + i) = *(s1+i);
        }else{
            // we need to add s1_size because in the stinrg, it is the offset of the second string :D
            *(cS + i) = *(s2 + (i - (s1_size - 1)));
        }
    }
    cS[cS_size-1]  = '\0';
    return cS;
}

// compares string, returns `true` if the string contains the same characters and otherwise `false`
bool compareString(char* s1, char* s2){
    
    if(getStringLength(s1) != getStringLength(s2)){
        return false;
    }
    // i couldve made this faster by setting string lengths to a var
    for(__u_int i = 0; i < getStringLength(s1); i++){
        if(*(s1+i) != *(s2+i)) return false;
    }

    return true;
}

// reverses a string `s`
char* reverseString(char* s){
    __u_int sL = getStringLength(s);
    char* rS = (char*) malloc(sL * sizeof(char));
    for(int i = sL-2; i >= 0; i--){
        *(rS+i) = *(s + (sL - (i+2)));
    }
    *(rS + (sL -1)) = '\0'; 

    return rS;
}

// changes the case of a string, type can be : `STRING_CASE_UPPERCASE` and `STRING_CASE_LOWERCASE`
void changeCaseString(char* s, int type){
    __u_int sS = getStringLength(s);
    switch (type)
    {
    case 1:
        for(__u_int i = 0; i < sS; i++){
            *(s+i) = toLowerCase(*(s+i));
        }
        break;
    case 2:
        for(__u_int i = 0; i < sS; i++){
            *(s+i) = toUpperCase(*(s+i));
        }
        break;
    }
}
char toLowerCase(char c){
    return (c > 64 && c < 91 )?  c + 32 : c; 
}

char toUpperCase(char c){
    return (c > 96 && c < 123 )?  c - 32 : c; 
}

#endif