#include <stdio.h>
#include <math.h>
#include <time.h>

int prime(int num)
{
	int sqr = (int)ceil(sqrt(num));
	for (int div = 5; div < (sqr+1); div += 6)
	{
		if(num%div==0 || num%(div+2)==0)
		{
			return 0;
		}
	}
	return 1;
}

int mainLoop()
{
	int calcTo;
	calcTo = 10000000;
	printf("calcTo: %i\n",calcTo);
	int primesFound = 2;
	int currentNum = 1;

	while (primesFound < calcTo) {
		currentNum += 4;
		primesFound += prime(currentNum);

		if (primesFound >= calcTo)
		{
			return currentNum;
		}

		currentNum += 2;
		primesFound += prime(currentNum);
	}

	return currentNum;
}

int main() {
	
	clock_t start, end;
	double time_used;

	start = clock();
	int ans = mainLoop();
	end = clock();

	time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

	printf("Your #: %i\nTime: %fsec",ans, time_used);

	return 0;
}