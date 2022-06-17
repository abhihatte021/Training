#include"header.h"

int Get_file_data(const char * , struct student *);

int main()
{
    int Ret=0;
    struct student s1,s2;
    //struct student * ret=&s2;

    FILE *fp;
    const char fname[30] = "student.txt";

    //structure object initialization
    s1.roll_no=1;
    strcpy(s1.name,"Abhi");

    //Open file
    fp = fopen("student.txt","wb");
    if(fp==NULL)
    {
        perror("Error: ");
        return -1;
    }

    //Write data of s1 object into files
    fwrite(&s1,sizeof(struct student), 1,fp);

    //close file
    fclose(fp);
    
    //call API
    Ret=Get_file_data(fname,&s2);
    if(Ret==-1)
    {
        return -1;
    }

   /* 
   //Open file 
   // FILE *RF=fopen(fname,"rb");

    //Read data into s2 object
    //fread(&s2,sizeof(struct student),1,RF);
    */

    //print data of s2 object
    printf("Roll no: %d, Name : %s\n",s2.roll_no,s2.name);

    
    return 0;
}
