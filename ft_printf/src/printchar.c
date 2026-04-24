#include <unistd.h>

int	printchar(int c)
{
	return (write(1, &c, 1));
}
