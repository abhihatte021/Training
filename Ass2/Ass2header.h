#include<stdio.h>
#include<stdlib.h>

//A structure 'BitManipulateStruct' which have a 16-bit integer and two function pointers.
struct BitManipulateStruct
{
    unsigned short int a; 
    void (*fptr1) (unsigned short int *);
    int (*fptr2) (unsigned short int);
};

//An enum with two values: TOGGLE and SWAP.
enum fnames {TOGGLE=1,SWAP=2};

//Function Declaration

//This function toggles all the bits of the input integer.
void ToggleAllBits(unsigned short int *);

//This function swaps the Higher and Lower bytes of the input integer and returns the new value.
int SwapBytes(unsigned short int);

//This function call the above two function using switch case,function pointer and enumeration
void Manipulator(struct BitManipulateStruct*,enum fnames);

