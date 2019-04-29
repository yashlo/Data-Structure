#include <stdio.h>
struct student
{
    char name[20],address[20],snm[20];
    int c_marks,cpp_marks,java_marks,total,semester;
    float percentage;
};

// function prototype
void display_result(struct student s[],int n);

int main()
{
    struct student s1[5];
    int i,n;
    printf("Enter Number of Student : ");
    scanf("%d",&n);
    printf("Enter Student Personal Details : \n");
    for(i=0;i<n;i++)
    {
        printf("Enter name:");
        scanf ("%s", s1[i].name);
        printf("Enter Surname : ");
        scanf("%s",s1[i].snm);
        printf("Enter Address : ");
        scanf("%s",s1[i].address);
        printf("Enter Semester : ");
        scanf("%d",&s1[i].semester);
        printf("Enter C Marks : ");
        scanf("%d", &s1[i].c_marks);
        printf("Enter CPP Marks :");
        scanf("%d",&s1[i].cpp_marks);
        printf("Enter Java Marks : ");
        scanf("%d",&s1[i].java_marks);
    }
    display_result(s1,n);   // passing structure as an argument

    return 0;
}
void display_result(struct student s[],int n)
{
    char search[10];
    printf("-----------------------------------------------------------------------\n");
    printf("\t\t\t\\t| STUDENT RESULT | \n");
    printf("-----------------------------------------------------------------------\n");
    int i;
    printf("--------------------------------\t \t \t-------------------------------- \n");
    printf("| STUDENT PERSONAL DETAILS |    \t \t \t  | STUDENT ACEDMIC DETAILS |  \n");
    printf("--------------------------------\t \t \t--------------------------------\n");
    printf("Name\t Surname\t Address\t \t \t C\t CPP\t Java\t Total\t Percentage\n");
    for(i=0;i<n;i++)
    {
        s[i].total=s[i].c_marks+s[i].cpp_marks+s[i].java_marks;
        s[i].percentage=((float)s[i].total/300)*100;
        printf("%s\t %s\t %s\t \t \t \t %d\t %d\t %d\t %d\t %0.2f\t \n",s[i].name,s[i].snm,s[i].address,s[i].c_marks,s[i].cpp_marks,s[i].java_marks,s[i].total,s[i].percentage);
    }
    printf("Enter Search Record : ");
    scanf("%s",search);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,search)== 0)
        {
                printf("--------------------------------\t \t \t-------------------------------- \n");
                printf("| STUDENT PERSONAL DETAILS |    \t \t \t  | STUDENT ACEDMIC DETAILS |  \n");
                printf("--------------------------------\t \t \t--------------------------------\n");
                printf("Name\t Surname\t Address\t \t \t C\t CPP\t Java\t Total\t Percentage\n");
                printf("%s\t %s\t %s\t \t \t \t %d\t %d\t %d\t %d\t %0.2f\t \n",s[i].name,s[i].snm,s[i].address,s[i].c_marks,s[i].cpp_marks,s[i].java_marks,s[i].total,s[i].percentage);
        }
    }
}
