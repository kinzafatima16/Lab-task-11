#include<stdio.h>
#include<stdlib.h>
struct building{
	int ID;
	float int_height,growth_rate;	 
};
float compute_height(struct building *b,int n)
{
	if(n==0)
	return b->int_height;
	double prevHeight=compute_height(b,n-1);
	double increase=prevHeight*b->growth_rate;
	return prevHeight+increase;
	
}
int main ()
{
	int day;
	float height;
	struct building a;
	struct building *b=&a;
	printf("please enter the ID:");
	scanf("%d",&b->ID);
	printf("please enter the number of day:");
	scanf("%d",&day);
	printf("please enter the initial height of the building:");
	scanf("%f",&b->int_height);
	printf("please enter the growth rate of the building:");
	scanf("%f",&b->growth_rate);
	height=compute_height(b,day);
	printf("estimated height of the building is :%f",height);
	return 0;
}

