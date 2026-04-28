#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	int	og_len = 0;
	int	ft_len = 0;

	char c = 'a';
	const char *s = "Hello, World!";
	const char *p = s;
	int n = -42;
	unsigned int un = 42;

	ft_printf("\n");

	// Test 0: Text
	printf("   printf: ");
	og_len = printf("Initial test");
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("Initial test");
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 1: Character
	printf("   printf: ");
	og_len = printf("%c", c);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%c", c);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 2: String
	printf("   printf: ");
	og_len = printf("%s", s);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%s", s);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 3: Pointer
	printf("   printf: ");
	og_len = printf("%p", p);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%p", p);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 4: Integer
	printf("   printf: ");
	og_len = printf("%i", n);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%i", n);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 5: Unsigned integer
	printf("   printf: ");
	og_len = printf("%u", un);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%u", un);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 6: Lowercase hexadecimal
	printf("   printf: ");
	og_len = printf("%x", un);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%x", un);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 7: Uppercase hexadecimal
	printf("   printf: ");
	og_len = printf("%X", un);
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%X", un);
	ft_printf(" (returned %d)\n\n", ft_len);

	// Test 8: Percentage character
	printf("   printf: ");
	og_len = printf("%%");
	printf(" (returned %d)\n", og_len);
	ft_printf("ft_printf: ");
	ft_len = ft_printf("%%", un);
	ft_printf(" (returned %d)\n\n", ft_len);
}
