#include <stdio.h>
#include <string.h>

typedef struct {
    char f_name[100];
    double o_size;
    double r_rate;
} File;

double est_f_size(File f_data, int n_rounds) {
    if(n_rounds == 0) {
        return f_data.o_size;
    }
    
    double prev_size=est_f_size(f_data, n_rounds-1);
    return prev_size * (1.0 - f_data.r_rate);
}

int main() {
    File my_f;
    int k_r;
    double f_size;
    
    printf("Enter Filename: ");
    scanf("%s", my_f.f_name);
    printf("Enter Original Size (MB): ");
    scanf("%lf", &my_f.o_size);
    printf("Enter Reduction Rate (e.g., 0.10 for 10%%): ");
    scanf("%lf", &my_f.r_rate);
    printf("Enter Number of Compression Rounds (k): ");
    scanf("%d", &k_r);
    
    f_size=est_f_size(my_f,k_r);
    
    printf("\n--- Compression Result ---\n");
    printf("File: %s\n", my_f.f_name);
    printf("Original Size: %.2lf MB\n", my_f.o_size);
    printf("Reduction Rate: %.2lf\n", my_f.r_rate);
    printf("Estimated Final Size after %d rounds: %.2lf MB\n", 
           k_r, f_size);
           
    return 0;
}
