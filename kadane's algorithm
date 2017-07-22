#include<stdio.h>

int find_max_sum(int *arr , int n)
{
	int i , max_ending_here , max_so_far;
	
	max_so_far = -101;
	
	max_ending_here = 0;
	
	for(i=0;i<n;i++)
	{
		max_ending_here = max_ending_here + arr[i];
	
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	
		if(max_ending_here < 0)
			max_ending_here = 0;
			
	}
	
	return max_so_far;
}

int main()
{
	int t , n , i , sum , arr[100];
	
	scanf("%d",&t);
	
	while(t--)
	{
	
		scanf("%d",&n);
	
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
			
		sum = find_max_sum(arr,n);
		
		printf("%d\n",sum);
	}
		
	return 0;	
}
