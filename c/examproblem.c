#include <stdio.h>
int main()
{
    int unit;
    float amount, totalAmount, surCharge;


    
    printf("Enter the number of units used: ");
    scanf("%d", &unit);




    
    if(unit <= 200)
    {
        amount = unit * 0.80;
    }
    else if(unit <= 300)
    {
        amount = 100 + ((unit-200) * 0.90);
    }
    else if(unit >= 350)
    {
       amount =  110 + ((unit-150) * 1.00);
    }
    
    if(amount>400){
    	surCharge = amount * 0.15;
	}
    
    totalAmount = amount + 	surCharge;


    printf("Bill = Rs. %.2f", totalAmount);


    return 0;
}