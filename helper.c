#include"header.h"

int Get_file_data(const char* fname , struct student *temp)
{
    FILE *ReadF = NULL;

    //Open file
    ReadF=fopen(fname,"rb");
    if(ReadF==NULL)
    {
        perror("Error: ");
        return -1;
    }
    /*
    struct student s1copy;

    fread(&s1copy,sizeof(struct student),1,ReadF);
    strcpy(temp->name,s1copy.name);
    temp->roll_no=s1copy.roll_no;
    */
    
    //Read data from file to another object
    fread(temp,sizeof(struct student),1,ReadF);

    //close object
    fclose(ReadF);

    return 0;

}
