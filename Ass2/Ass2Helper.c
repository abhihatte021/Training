#include "Ass2header.h"

//defination of functions

//This function toggles all the bits of the input integer.
void ToggleAllBits(unsigned short int *iPtr)
{
  (*iPtr) = ~(*iPtr); //performing NOT operation
}

//This function swaps the Higher and Lower bytes of the input integer and returns the new value.
int SwapBytes(unsigned short int i)
{
    /*
    //Don't use another logic while solving bit manipulation questions
  //union declaration
  union out
  {
   struct Inner //Inner structure declaration
   {
    unsigned char lsb;
    unsigned char msb;
   }in;           //Inner structure object creation
   unsigned short int b;
  };

  union out uobj; //union object creation
  uobj.b=i;      //union object initialization

  unsigned char lsb=0; //new variable of type unsigned char initialization

  //Swapping of lsb and msb
  lsb = uobj.in.lsb;  //coping lsb in new varible 
  uobj.in.lsb=uobj.in.msb; //coping msb in lsb
  uobj.in.msb=lsb;  //coping lsb in msb

  i=uobj.b; //

  //We can use this shifting logic to directly swap bytes of only 16 bit integer
  i=i<<8; //shifting 8 bits because our input integer is of 16 bits
  */
  int lshift=0;
  int rshift =0;
  lshift = i<<8;
  rshift = i>>8;
  i = (lshift | rshift);

  return i;
}

//This function call the above two function using switch case,function pointer and enumeration
void Manipulator(struct BitManipulateStruct *sobj,enum fnames eChoice)
{
    int option=0;
    int iRet=0;

    printf("Enter your choice :\n 1:TOGGLE\n 2:SWAP\n");
    scanf("%d",&option);
    switch (option)
    {
    case TOGGLE:
        sobj->fptr1(&(sobj->a)); //Calling ToggleAllBits function using function pointer fptr1
        printf("Toggled number is %d\n",(sobj->a));
        break;

    case SWAP:
    
        iRet=sobj->fptr2(sobj->a);  //Calling SwapBytes function using function pointer fptr2
        printf("Swapped number is %d\n",iRet);       //printing swaped integer
        break;
    
    default:
        printf("Please enter valid choice\n");
        break;
    }
}
