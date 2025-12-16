#include <stdio.h>
#include <string.h>

typedef struct {
    char c_name[50];
    int day;
    double b_temp;
    double c_fact;
} W_Data;

double predictTemp(W_Data w_d, int n_days) {
    if(n_days == 0) {
        return w_d.b_temp;
    }
    
    double temp_prev=predictTemp(w_d, n_days-1);
    
    return temp_prev - w_d.c_fact;
}

int main() {
    W_Data f_cast;
    int days_p;
    double p_temp;
    
    printf("Enter City Name: ");
    scanf("%s", f_cast.c_name);
    printf("Enter Base Temperature (Day 0): ");
    scanf("%lf", &f_cast.b_temp);
    printf("Enter Cooling Factor (k): ");
    scanf("%lf", &f_cast.c_fact);
    printf("Enter Number of Days to Predict (N): ");
    scanf("%d", &days_p);
    
    p_temp=predictTemp(f_cast,days_p);
    
    printf("\n--- Weather Prediction Result ---\n");
    printf("City: %s\n", f_cast.c_name);
    printf("Base Temperature (Day 0): %.2lf C\n", f_cast.b_temp);
    printf("Cooling Factor: %.2lf\n", f_cast.c_fact);
    printf("Predicted Temperature after %d days (T(%d)): %.2lf C\n", 
           days_p, days_p, p_temp);
           
    return 0;
}
