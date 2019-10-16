#include <stdio.h>
#include <conio.h>
#include <string.h>


void main()
{
    FILE *fptr;
    int id=1;
    char name[20];
    char number[20];
    char visiting_to[20];
    char purpose_of_visiting[20];
    char file_name[100];
    int options=0;
    while(id!=0){
        printf("\t Welcome");
        printf("\n\t To");
        printf("\n\t Visitor Management System \n\n\n");
        printf("\n\t 1. Check-in");
        printf("\n\t 2. Check-out\n");
        scanf("%d", &options);
        if(options==1){
                     snprintf(file_name, sizeof file_name, "%s%d%s", "data/visitor_", id, ".txt");
                     fptr = fopen(file_name, "w");
                     if (fptr == NULL)
                     {
                        printf("File does not exists \n");
                        return;
                     }
                     printf("Enter the name \n");
                     scanf("%s", name);
                     fprintf(fptr, "Name    = %s\n", name);
                     printf("Enter the Phone number \n");
                     scanf("%s", number);
                     fprintf(fptr, "Phone number    = %s\n", number);
                     fclose(fptr);
                     id++;
                     system("cls");
        }
        else if(options==2){
                int logId=0;
                printf("\n\t Please enter your id.\n");
                scanf("%d", &logId);
                char file_new_name[100];
                snprintf(file_name, sizeof file_name, "%s%d%s", "data/visitor_", logId, ".txt");
                snprintf(file_new_name, sizeof file_new_name, "%s%d%s", "data/visitor_", logId, "_log_out.txt");
                if (rename(file_name, file_new_name) == 0)
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t log-out successful.\n\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t Failed log-out!!!\n\n\n");
                }
         }
         else if (options==1971){

         }
         else{
                    system("cls");
                    printf("\n\t\t\t\t\t\t Please enter a valid option no.!!!\n\n\n");
         }
    }
}
