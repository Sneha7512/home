#include<stdio.h>
#include<cs50.h>
#include<math.h>

long findlength(long number);
long checksum1(long number,long digits);
long checksum2(long number, long digits);
void validity(long number,long digits, long total);


int main(void)
{   long number;                           //get the credit Card number from user
    do{
         number=get_long("Number:");
      }
       while( number < 1);

       long digits=findlength(number);
       //printf("%li\n",digits);
       long a = checksum1(number,digits);
       long b= checksum2(number,digits);
       long total= a + b ;
       //printf("%li\n",total);
       validity(number,digits,total);
}


long findlength(long number)
{

    long length=0;

    while(number!=0)                       //loop to find the number of digits in the credit card number
    {
        number=number/10;
        length++;
    }
    return length;
}


long checksum1(long number, long digits)
{
    long sum1=0;

    for(int i=0;i<digits;i++)                      //first condition for checksum
        {
            long last= number % 10;
            sum1= sum1 + last;
            number= number / 100;
        }
    return sum1;
}


long checksum2(long number,long digits)
{
   long sum2 = 0;
   number=number/10;                           //second condition for checksum

    for(int i=0;i<digits;i++)
        {
            long last=number % 10;
            long timestwo = 2 * last;
            sum2=sum2 + (timestwo % 10)+ (timestwo/10);
            number=number/100;
        }
    return sum2;
}


void validity(long number,long digits, long total)                      //checking the type of card
{
    if ( total % 10 == 0)
        {
             if (digits == 16)
                 {
                     if (number / 1000000000000000 == 4)
                         {
                             printf("VISA\n");
                         }

             else if (number / 100000000000000 >= 51 && number/ 100000000000000 <= 55)
                  {
                     printf("MASTERCARD\n");
                  }

             else
                  {
                    printf("INVALID\n");
                  }
                }

             else if (digits == 15)
                 {
                    if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
                        {
                              printf("AMEX\n");
                         }
                    else
                       {
                         printf("INVALID\n");
                       }
                 }

             else if (digits== 13)
                  {
                    if (number/ 1000000000000 == 4)
                         {
                             printf("VISA\n");
                         }

                     else
                         {
                              printf("INVALID\n");
                         }
                  }
             else
             {
                 printf("INVALID\n");
             }

        }

else
    {
        printf("INVALID\n");
    }
}


