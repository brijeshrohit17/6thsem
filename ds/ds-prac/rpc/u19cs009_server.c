/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "u19cs009.h"

void word(int n, int p)
{
	if(p==1 || p==3)
	{
		if(n == 1)
		printf("One ");
		else if(n == 2)
		printf("Two ");
		else if(n == 3)
		printf("Three ");
		else if(n == 4)
		printf("Four ");
		else if(n == 5)
		printf("Five ");
		else if(n == 6)
		printf("Six ");
		else if(n == 7)
		printf("Seven ");
		else if(n == 8)
		printf("Eight ");
		else if(n == 9)
		printf("Nine ");
		
		if(p == 3)
		printf(" Hundred and ");
	}
	else if(p == 2)
	{
		if(n == 2)
		printf("Twenty ");
		else if(n == 3)
		printf("Thirty ");
		else if(n == 4)
		printf("Fourty ");
		else if(n == 5)
		printf("Fifty ");
		else if(n == 6)
		printf("Sixty ");
		else if(n == 7)
		printf("Seventy ");
		else if(n == 8)
		printf("Eighty ");
		else if(n == 9)
		printf("Ninety ");
	}
}


output *
exec_1_svc(input *argp, struct svc_req *rqstp)
{
	static output  result;

	printf("Server Called!!\n");	
	int n = argp->num;
	int dig1=0, dig2=0, dig3=0;
	if(n > 99)
	{
		int dig1 = n/100;
		word(dig1,3);
		n = n-100*dig1;
		if(n < 20){
			if(n==11)
			printf("Eleven ");
			else if(n == 12)
			printf("Twelve ");
			else if(n == 13)
			printf("Thirteen ");
			else if(n == 14)
			printf("Fourteen ");
			else if(n == 15)
			printf("Fifteen ");
			else if(n == 16)
			printf("Sixteen ");
			else if(n == 17)
			printf("Seventeen ");
			else if(n == 18)
			printf("Eighteen ");
			else if(n == 19)
			printf("Nineteen ");
			return &result;
		}
		else{
			int dig2 = n/10;
			word(dig2,2);
			n = n=10*dig2;
			int dig3 = n;
			word(dig3,1);
			return &result;
		}
	}
	else if(n > 9)
	{
		n = n-100*dig1;
		if(n < 20){
			if(n==11)
			printf("Eleven ");
			else if(n == 12)
			printf("Twelve ");
			else if(n == 13)
			printf("Thirteen ");
			else if(n == 14)
			printf("Fourteen ");
			else if(n == 15)
			printf("Fifteen ");
			else if(n == 16)
			printf("Sixteen ");
			else if(n == 17)
			printf("Seventeen ");
			else if(n == 18)
			printf("Eighteen ");
			else if(n == 19)
			printf("Nineteen ");
			return &result;
		}
		else{
			int dig2 = n/10;
			word(dig2,2);
			n = n=10*dig2;
			int dig3 = n;
			word(dig3,1);
			return &result;
		}
	}
	else if(n < 9)
		word(n,1);

	return &result;
}
