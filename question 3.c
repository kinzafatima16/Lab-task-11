#include<stdio.h>
#include<stdlib.h>

struct Patient{
char name[30];
int age;
float healthScore;
};

struct DailyReport{
int day;
float scoreChange;
};

float computeFinalScore(struct Patient *p, struct DailyReport report[], int n){
if(n==0)
return p->healthScore;
float prev=computeFinalScore(p, report, n-1);
return prev+report[n-1].scoreChange;
}

int main(){
struct Patient p;
int N;
printf("Enter patient name: ");
fgets(p.name,30,stdin);
printf("Enter age: ");
scanf("%d",&p.age);
printf("Enter initial health score: ");
scanf("%f",&p.healthScore);
printf("Enter number of days to monitor: ");
scanf("%d",&N);

struct DailyReport report[N];
for(int i=0;i<N;i++){
printf("Enter day number: ");
scanf("%d",&report[i].day);
printf("Enter score change for day %d: ",report[i].day);
scanf("%f",&report[i].scoreChange);
}

struct Patient *ptr=&p;
float finalScore=computeFinalScore(ptr, report, N);
printf("\nFinal health score after %d days: %.2f\n",N,finalScore);

return 0;
}

