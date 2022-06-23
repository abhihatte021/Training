#include"Ass2header.h"

int main()
{
    //structure object creation
    struct BitManipulateStruct obj;

    //pointer to object of structure  allocateted 0-initialized memory using pointer
    struct BitManipulateStruct *ptr=(struct BitManipulateStruct* )calloc(1,sizeof(struct BitManipulateStruct));

    //enum object creation
    enum fnames choices;

    //structure pointer points to obj of same structure
    ptr = &obj;

    //object initialization
    obj.fptr1=&ToggleAllBits;
    obj.fptr2=&SwapBytes;

    //Taking 16-bit integer input from user
    printf("Enter the number\n");
    scanf("%hu",&obj.a);

    //calling Manipulator function
    Manipulator(ptr,choices);
    
    return 0;
}