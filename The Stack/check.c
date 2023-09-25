//program to calculate the power of a number using pow function
#include<stdio.h>
#include<math.h>

void main()
{
    int number, power, result;
printf("Enter the number and its power");
scanf("%d%d",&number,&power);
result = pow(number,power);
printf("%d",result);
}