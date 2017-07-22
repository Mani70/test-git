/*
   I have made little changes in kadane's algorithm, so that it will also work fine, when only -ve numbers are given as input.

   Note: If the given inputs are, -ve numbers only then in that case, same algorithm will find out the maximum of those numbers
         i.e least -ve number.
  
   Key point : If the constraint is given as:   -100 < arr[i] < 100
               then, intialize max_so_far = -101 (i.e always initialize with minimum)
	      
*/	


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
