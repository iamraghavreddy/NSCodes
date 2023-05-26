//Name: Kaushik Shroff
//Batch: K-8
//Roll No: 32418
//Experiment No: 1
//Code for displaying *
#include<stdio.h>
#include<conio.h>
int main()
{
	int i=0;
    char password[55];
    char passin[55]="admin";
    printf("Password:\n");
    int p=0;
    do{
        password[p]=getch();
        if(password[p]!='\r'){
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r');
    printf("\n");
    password[p-1]='\0';
    for(i=0;i<6;i++)
    {
    	if(passin[i]!=password[i])
    	break;
	}
	if(i==6)
    {
    	printf("Correct password\n");
	}	
    else
    {
    	printf("Wrong password\n");
	}
    getch();
}
