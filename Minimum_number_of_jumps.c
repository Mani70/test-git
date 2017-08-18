// Time complexity O(n)

#include <stdio.h>
#include<stdbool.h>

// This function will return the minimum number of jumps to reach the end of the array (starting from the first element).

int getminsteps(int *arr,int n)
{
    int i,j,k,maxreach,jump;
    
    jump = i = j = 0;
    
    while(i<n)
    {
        if(!arr[i])
            return -1;
        
        if((k = i + arr[i]) >= n-1)
            return jump+1;
            
        maxreach = k + arr[k];
        
        j = i + 1;
        i = i + arr[i];
        
        
        while(j < k)
        {
            if(arr[j] + j > maxreach)
            {
                maxreach = arr[j] + j;
                i=j;
            }
            j++;
        }
            
        jump++;
    }
}

int main() 
{
	//code
	int i,t,n,arr[100];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    
	    for(i=0;i<n;i++)
	        scanf("%d",&arr[i]);
	        
	    printf("%d\n",getminsteps(arr,n));
	}
	return 0;
}
