//print the days and to repeat the input prompt only when the entered day is invalid 
#include<stdio.h>
int main(){
    int day;
    do{
    printf("Enter a days btw 0 to 7:");
    scanf("%d",&day);
   
    switch(day){
        case 1: printf("Monday\n");
               break;
        case 2: printf("Tuesday\n");
               break;
        case 3: printf("Wednesday\n");
               break;
        case 4: printf("Thursday\n");
               break;
        case 5: printf("Friday\n");
               break;
        case 6: printf("Saturday\n");
               break;
        case 7: printf("sunday\n");
               break;
        default: printf("Invalid, Enter valid choice\n");
    }              

    }while(day < 1 || day > 7);
    return 0;
}