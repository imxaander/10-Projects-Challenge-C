#ifndef MYCHELPER
#define MYCHELPER
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void swap_int(int* a, int* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void print_int_array_contents(int* a, int b){
    for(int i = 0; i < b; i++){
        printf("%i", *(a+i));
    }
}


//--------------------VECTORS----------------------------
struct Vector2d{
    double x, y;
};

typedef struct Vector2d Vector2d;
void print_vector2d(Vector2d* a){
    printf("%f, %f\n", a->x, a->y);
}
Vector2d add_vector2d(Vector2d* a, Vector2d* b){
    Vector2d c = {a->x + b->x, a->y + b->y};
    return c;
}
double dot_product_vector2d(Vector2d* a, Vector2d* b){
    return (double)(a->x * b->x) + (a->y * b->y);
}

//--------------------STRING----------------------------
#define STRING_CASE_UPPERCASE 2
#define STRING_CASE_LOWERCASE 1

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
unsigned int getStringLength(char* s){
    unsigned int i = 0;
    while(*(s+i) != '\0'){
        i++;
    }
    // +1 because of the ending \0
    return i+1;
}

char* concatString(char* s1, char* s2){
    // to concatenate string, we can use getStringLength() tio get the length 
    // and then allocate the memory for that addition of string 
    unsigned int s1_size = getStringLength(s1);
    unsigned int s2_size = getStringLength(s2);
    unsigned int cS_size = s1_size + s2_size - 1;

    char* cS = (char*) malloc((cS_size) * sizeof(char));
    
    for(unsigned int i = 0; i < cS_size; i++){
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

bool compareString(char* s1, char* s2){
    
    if(getStringLength(s1) != getStringLength(s2)){
        return false;
    }
    // i couldve made this faster by setting string lengths to a var
    for(unsigned int i = 0; i < getStringLength(s1); i++){
        if(*(s1+i) != *(s2+i)) return false;
    }

    return true;
}

char* reverseString(char* s){
    unsigned int sL = getStringLength(s);
    char* rS = (char*) malloc(sL * sizeof(char));
    for(int i = sL-2; i >= 0; i--){
        *(rS+i) = *(s + (sL - (i+2)));
    }
    *(rS + (sL -1)) = '\0'; 

    return rS;
}

void changeCaseString(char* s, int type){
    unsigned int sS = getStringLength(s);
    switch (type)
    {
    case 1:
        for(unsigned int i = 0; i < sS; i++){
            *(s+i) = toLowerCase(*(s+i));
        }
        break;
    case 2:
        for(unsigned int i = 0; i < sS; i++){
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


//--------------------INPUT OUTPUT----------------------------
char* get_line(void){
    char* lineResult = (char*) malloc(0);

    char tmp = getchar(); //pointer to the current scanned character in the input stream
    if(tmp == '\n' ) return NULL;

    unsigned int currentStringLength = 0;
    while(tmp != '\n'){
        // printf("char : %c", tmp);
        char* tmpResult = realloc(lineResult, (++currentStringLength * sizeof(char)));
        *(tmpResult + currentStringLength - 1) = tmp;
        
        lineResult = tmpResult;
        // printf("string : %s\n", lineResult);
        tmp = getchar();
    };
    // printf("%s", lineResult);
    return lineResult;
}
#endif