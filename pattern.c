#include<stdio.h>

int main()
{
	int i, j, n, left, right, k;
	printf("Enter an even number : ");
	scanf("%d", &n);
	if(n & 1)
	{
		printf("Its odd number");
		return 0;
	}
	k = 2 * n + 1;
	left = 0;
	right = k - 1;
	while(left <= right)
	{
		for(j = 0; j < k; j++)
		{
			if(j <= left)
			{
				if(j & 1)
				{
					printf("0 ");
				}
				else
				{
					printf("1 ");
				}
			}
			else if(j >= right)
			{
				if((j - right) & 1)
				{
					printf("0 ");
				}
				else
				{
					printf("1 ");
				}
			}
			else
			{
				printf("  ");
			}
			
		}
		left++;
		right--;
		printf("\n");
	}
	left -= 2;
	right += 2;
	while(left >= 0)
	{
		for(j = 0; j < k; j++)
		{
			if(j <= left)
			{
				if(j & 1)
				{
					printf("0 ");
				}
				else
				{
					printf("1 ");
				}
			}
			else if(j >= right)
			{
				if((j - right) & 1)
				{
					printf("0 ");
				}
				else
				{
					printf("1 ");
				}
			}
			else
			{
				printf("  ");
			}
		}
		left--;
		right++;
		printf("\n");
	}
	return 0;
}