#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>
#include <unistd.h>

unsigned long ft_time(void)
{
	unsigned long time;
	static unsigned long tm;
	struct timeval ct;
	
	gettimeofday(&ct, NULL);
	time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
	if (!tm)
		tm = time;
	return (time - tm);
}

int main(void)
{
	while(1)
	{
		printf("%lu\n", ft_time());
		usleep(1000);
	}
}