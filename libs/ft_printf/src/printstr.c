#include <unistd.h>

int	printstr(const char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
		count++;
	return (write(1, s, count));
}
