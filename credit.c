#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned long long cc;
    
    // user prompt for credit card number
    do
    {
        printf("Number: ");             
        cc = get_long_long();
    }
    while (cc <= 0);

    unsigned long long cc2 = cc;
    unsigned long long cc3 = cc;
    unsigned long long cc4 = cc;
    
    // checksum
    int c = 0;                          
    
    // dividing and modding by 10 to get 2nd last digit
    cc /= 10;                           
    
    // loop will run till cc becomes zero as it is divided.
    while (cc != 0)                     
    {
        
        int z = cc % 10;
        // multiplying digits by 2
        z *= 2;                         
        
        // for loop to produce sum of product's digits
        for (int b = 1; b <= 2; b++)
        {
            int a = z % 10;
            c = c + a;                  
            z /= 10;
        }
        
        // dividing by 100 to get every other digit
        cc /= 100;                      
       
    }
    
    while (cc2 != 0)
    {
        // modding by 10 to get the last digit
        int z = cc2 % 10;                
        
        // adding digits to the previous sum of product's digits
        c = c + z;                       
        
        // dividing by 100 to get every other digit
        cc2 /= 100;                      
    }
    
    bool valid;
    
    // setting a validity flag if checksum is passed
    if (c % 10 == 0)
    {
        valid = 1;                      
    }
    else
    {
        valid = 0;
    }
    
    // if validity flag is 0, invalid is displayed
    if (valid == 0)                     
    {
        printf("INVALID\n");
    }
    
    int digitsn = 0;
    
    // digitsn holds the number of digits in the credit card number
    while (cc3 != 0)
    {
        cc3 /= 10;                      
        digitsn++;
    }
    
    // done to check first two digits of cc number
    int amexid = cc4 / pow(10 , 13);    
    
    if (valid == 1 && digitsn == 15 && (amexid == 34 || amexid == 37))
    {
        printf("AMEX\n");
    }
    
    // done to check first two digits of cc number
    int mastid = cc4 / pow(10 , 14);     
    
    if (valid == 1 && digitsn == 16 && (mastid == 51 || mastid == 52 || mastid == 53 || mastid == 54 || mastid == 55))
    {
        printf("MASTERCARD\n");
    }
    
    // done to check first two digits of cc number
    int visaid = cc4 / pow(10 , 12);    
    int visaid2 = cc4 / pow(10, 15);
    
    if (valid == 1 && ((digitsn == 13 && visaid == 4) || (digitsn == 16 && visaid2 == 4)))
    {
        printf("VISA\n");
    }
}