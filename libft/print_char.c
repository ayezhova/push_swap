#include "libft.h"

void		print_char(char c, int n)
{
	char	str[n + 1];
	int		i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	write(1, str, n);
}