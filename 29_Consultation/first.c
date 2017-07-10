#include<stdio.h>
int main()
{
        int n;
        scanf("%d", &n);
        
        if(n % 2 == 0)
        {
        int arr[350];
        for(int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }
        int sum = 0;
        int a = n - 1;
        int t[350];
        for(int i = 0; i < n /2 ; i++)
        {
                sum = arr[i] + arr[a];
                t[i] = sum ;
                a--;
                
        }
        for(int q = 0; q < n /2 ; q++)
                        {
                        printf("%d ", t[q]);
                        }
                printf("\n");
        
        }
        else
        {
			int arr[350];
			for(int i = 0; i < n; i++)
			{
					scanf("%d", &arr[i]);
			}
			int sum = 0;
			int a = n - 1;
			int t[350] ;
			for(int i = 0; i < n /2 + 1 ; i++,a--)
			{
					sum = arr[i] + arr[a];
					t[i] = sum ;
			}
			for(int q = 0; q < n /2 + 1 ; q++)
                        {
                        printf("%d ", t[q]);
                        }
                printf("\n");
        }




return 0;
}
