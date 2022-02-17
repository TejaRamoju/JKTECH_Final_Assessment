#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
void read();
void write();
struct record
{
  char name[30];
  int id;
  int sal;
}s;
main()
{
int ch;
    while(1)
    {
        printf("\n1:Write Records");
        printf("\n2:Read Records");
        printf("\nEnter a number: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            write();
            break;
            case 2:
            read();
            break;
            default:
            printf("\nOption not Available\n");
            break;
        }
    }
getch();
}
void write()
{
int i=0;
int n = 0;
FILE *fp;
    fp=fopen("EmployeeDetails.txt","wb");
    if(fp==NULL)
    {
        printf("can't create file");
        getch();
        exit(1);
    }
    printf("\nEnter Number of Records: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Employee ID: ");
        scanf("%d",&s.id);
        printf("Enter Employee Name: ");
        scanf("%s",s.name);
        printf("Enter the Salary: ");
        scanf("%d",&s.sal);
        printf("\n");
        fwrite(&s,sizeof(s),1,fp);
    }
fclose(fp);
}
void read()
{
FILE *fp;
    fp=fopen("EmployeeDetails.txt","rb");
    if(fp==NULL)
    {
        printf("can't read file");
        getch();
        exit(1);
    }
        while(fread(&s,sizeof(s),1,fp)==1)
        {
            printf("\nEmployee ID: %d",s.id);
            printf("\nEmployee Name: %s",s.name);
            printf("\nSalary: %d",s.sal);
            printf("\n\n");
        }
fclose(fp);
}
