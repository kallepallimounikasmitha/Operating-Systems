#include<stdio.h>
int result[1000] = {0};

int fact_dp(int n){
    if (n >= 0) 
    {
        result[0] = 1;
        for (int i = 1; i <= n; ++i) 
        {
            result[i] = i * result[i - 1];
        }
        return result[n];
    }
}

int main()
{
    int n;
    
    
        
        scanf("%d",&n);
        if (n == 0)
            {
                printf("Error");
            }
        printf("%d",fact_dp(n));
    
    return 0;
}
