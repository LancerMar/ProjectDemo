#include<iostream>
#include<stdio.h>

int main()
{
	unsigned long long int n,sum;
	int cycleTimes;

	n=1;
	sum=0;
	cycleTimes = 100;
	

	while (n<100)
	{
		sum=sum+n;
		n=n+1;
		std::cout<<"step "<<n<<std::endl;
		std::cout<<"sum "<<sum<<"\n"<<std::endl;

	}

	std::cout <<"total sum: "<<sum<<std::endl;

	return 0;
}
