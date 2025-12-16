#include<stdio.h>
#include<stdlib.h>
struct bank{
	char customer_n[20];
	float intrest_rate;	
	int loan_amt,months;
};
float payment_calc(struct bank *b,int n)
{
	if(n==0){
		return b->loan_amt;
	}
	float prevpay=payment_calc(b,n-1);
	float increase=prevpay*b->intrest_rate;
	float monthly_inst=b->loan_amt/b->months;
	return prevpay-monthly_inst+increase;
}
int main()
{
	float monthly_inst,payment;
	struct bank b;
	struct bank *ptr=&b;
	printf("enter customer name: ");
	fgets(b.customer_n,20,stdin);
	printf("enter the intrest rate (eg 0.05 for 5%):");
	scanf("%f",&b.intrest_rate);
	printf("enter the loan amount:");
	scanf("%d",&b.loan_amt);
	printf("enter the number of months:");
	scanf("%d",&b.months);
	int n=b.months;
	payment=payment_calc(ptr,n);
	printf("the payment is :%f",payment);
	return 0;
}


