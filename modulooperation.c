#include<stdio.h>

void main()
{
	long long Base, Exponent, Modulus, Result;
	while(1)
	{
		printf("Enter the Base value :");
		scanf("%lld",&Base);
		printf("Enter the Exponent value :");
		scanf("%lld",&Exponent);
		printf("Enter the Modulus value :");
		scanf("%lld",&Modulus);
		
		if(Base<=0)
		{
			printf("Error : Base cannot be negative and Zero please enter the propper values again..!\n");
			
		}
		else if(Exponent<=0)
		{
			printf("Error : Exponent cannot be negative and Zero please enter the propper values again..!\n");
			
		}
		else if(Modulus<=0)
		{
			printf("Error : Modulus cannot be negative and Zero please enter the propper values again..!\n");
			
		}
		else
		{
			break;
		}
	}
	
	Result=1;
	//here i have used the concept of binary exponentisation with the modulo for efficiant handeling of the large values which are created through the exponent function
	Base=Base%Modulus;
	while(Exponent>0)
	{
		if((Exponent%2)==1)
		{
			Result=(Result*Base)%Modulus;
		}
		Base=(Base*Base)%Modulus;
		Exponent=Exponent/2;
		
	}
	
	
	printf("The result is : %lld\n",Result);
}
