#include <stdio.h>
#include <string.h>

typedef struct {
    char p_name[50];
    int p_age;
} Person;

typedef struct {
    Person p_data;
    int t_credits;
    double p_c_fee;
    int sub_credits[10]; 
} Student;

double calc_t_fee(Student s_data, int s_idx) {
    if(s_idx == 0) {
        return 0.0;
    }
    
    double cur_s_fee=s_data.p_c_fee * s_data.sub_credits[s_idx - 1];
    return cur_s_fee + calc_t_fee(s_data,s_idx - 1);
}

int main() {
    Student s_d;
    int i;
    double t_fee;
    
    printf("Enter Student Name: ");
    scanf("%s", s_d.p_data.p_name);
    printf("Enter Student Age: ");
    scanf("%d", &s_d.p_data.p_age);
    printf("Enter Per-Credit Fee: ");
    scanf("%lf", &s_d.p_c_fee);
    printf("Enter Number of Subjects: ");
    scanf("%d", &s_d.t_credits);
    
    for(i=0;i<s_d.t_credits;i++) {
        printf("Enter credits for Subject %d: ", i+1);
        scanf("%d", &s_d.sub_credits[i]);
    }
    
    t_fee=calc_t_fee(s_d,s_d.t_credits);
    
    printf("\n--- Semester Fee Calculation ---\n");
    printf("Student: %s (Age: %d)\n", s_d.p_data.p_name, s_d.p_data.p_age);
    printf("Total Subjects: %d\n", s_d.t_credits);
    printf("Per-Credit Fee: %.2lf\n", s_d.p_c_fee);
    printf("Total Semester Fee: $%.2lf\n", t_fee);
           
    return 0;
}
