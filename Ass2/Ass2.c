#include<stdio.h>

struct BitManipulateStruct
{
    unsigned short int a; 
    void (*fptr1) (unsigned short int *);
    int (*fptr2) (unsigned short int);
};
enum fnames {TOGGLE=1,SWAP=2};

//void ToggleAllBits(int *);
//int SwapBytes(int);
void ToggleAllBits(unsigned short int *iPtr)
{
  (*iPtr) = ~(*iPtr);
  printf("%d\n",(*iPtr));
}

int SwapBytes(unsigned short int i)
{
  /*union out
  {
   struct 
   {
    unsigned char lsb;
    unsigned char msb;
   }in;
   unsigned short int b;
  };

  union out aa;
  aa.b=i;
  unsigned char lsb = aa.in.lsb;
  aa.in.lsb=aa.in.msb;
  aa.in.msb=lsb;

  i=aa.b;*/
  int lshift=0;
  int rshift =0;
  lshift = i<<8;
  rshift = i>>8;
  i = (lshift | rshift);

  return i;
}

void Manipulator(struct BitManipulateStruct *Iobj,enum fnames IChoice)
{
    int option=0;
    int iRet=0;
    printf("Which your choice :\n 1:TOGGLE\n 2:SWAP\n");
    scanf("%d",&option);
    switch (option)
    {
    case TOGGLE:
        Iobj->fptr1(&(Iobj->a));
        break;

    case SWAP:
    
        iRet=Iobj->fptr2(Iobj->a);
        printf("%d\n",iRet);
        break;
    
    default:
        printf("Please enter valid choice\n");
        break;
    }
}

int main()
{
    struct BitManipulateStruct obj1;
    struct BitManipulateStruct *ptr=NULL;
    enum fnames choices;

    ptr = &obj1;
    obj1.fptr1=&ToggleAllBits;
    obj1.fptr2=&SwapBytes;

    printf("Enter the number\n");
    scanf("%hu",&obj1.a);

    Manipulator(ptr,choices);
    
    return 0;
}

