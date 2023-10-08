
#include "ft_printf.h"

int ft_putstr(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
	return (i);
}
int ft_putchar(const char c)
{
    write(1, &c, 1);
	return (1);
}
static int	ft_ptrlen(unsigned long int n)
{
	int	len;

	len = 0;
	while (n / 16 != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_putnbr_hexa(long int n, int upper, int format)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	j = 0;
	if (!n && format == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else if (!n && format == 1)
	{
		ft_putstr("0");
		return (1);
	}
	if (format == 0)
	{
		j = 2;
		ft_putstr("0x");
	}

	i = -1;
	len = ft_ptrlen(n);
    res = (char *)ft_calloc(sizeof(char) , (len + 2));
    if (!res)
    {
		return (0);
	}
	while (n != 0)
	{
		res[len] = "0123456789abcdef"[n % 16];
        n = n / 16;
		len--;
		j++;
	}
	while (upper == 1 && res[++i])
		res[i] = ft_toupper(res[i]);
	ft_putstr(res);
	free (res);
	return (j);
}

static unsigned int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len = len * 10;
		n = n / 10;
	}
	return (len);
}

void	ft_putnbru(unsigned int n)
{
	unsigned int	len;
	char			res;
	len = ft_uintlen(n);
	while (len >= 1)
	{
		res = n / len + '0';
		write (1, &res, 1);
		n = n % len;
		len = len / 10;
	}
}
int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

