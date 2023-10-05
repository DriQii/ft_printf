#include <libft.h>
#include "ft_printf.h"

void ft_putstr(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

void ft_putchar(const char c)
{
    write(1, &c, 1);
}

static int ft_check_format(char const c)
{
    if (c == 'c')
        return (1);
    else if (c == 's')
        return (2);
    else if (c == 'd')
        return (3);
    return (0);
}

static void ft_print_args(int format, va_list args)
{
    if (format == 1)
        ft_putchar(va_arg(args, int));
    else if(format == 2)
        ft_putstr(va_arg(args, char *));
    else if(format == 3)
        ft_putnbr(va_arg(args, int));
}

int ft_printf(const char *s, ...)
{
    int i;
    int format;
    va_list args;

    i = 0;
    format = 0;
    va_start(args, s);
    while(s[i])
    {
        if (s[i] != '%')
            write(1, &s[i], 1);
        else
        {
            format = ft_check_format(s[i + 1]);
            ft_print_args(format, args);
            i++;
        }
        i++;
    }
    return (1);
}

int main(void)
{
    char str[] = "Hello World";
    int i = 3;
    ft_printf("%s, %d, %d", str, i, ft_strlen(str));
}
