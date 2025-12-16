#include <stdio.h>

int max_tip_opt(int tips[], int n_stops, int curr_s) {
    if(curr_s >= n_stops) {
        return 0;
    }
    
    int opt_a=tips[curr_s] + max_tip_opt(tips,n_stops,curr_s+2);
    
    int opt_b=max_tip_opt(tips,n_stops,curr_s+1);
    
    return (opt_a > opt_b) ? opt_a : opt_b;
}

int main() {
    int t_arr[]={10, 5, 20, 15, 8, 25}; 
    int n=sizeof(t_arr)/sizeof(t_arr[0]);
    int m_tip;
    
    printf("Sample Tips Available (in $): ");
    int i;
    for(i=0;i<n;i++){
        printf("%d ", t_arr[i]);
    }
    printf("\n");
    
    m_tip=max_tip_opt(t_arr,n,0);
    
    printf("\n--- Tip Optimization Result ---\n");
    printf("Total Number of Stops: %d\n", n);
    printf("Maximum Total Tip Collected: $%d\n", m_tip);
           
    return 0;
}
