#include "ft_printf.h"



static void ft_print_args(char const c, va_list args)
{

    if (c == 'c')
        ft_putchar(va_arg(args, int));
    else if (c == 's')
        ft_putstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        ft_putnbr(va_arg(args, int));
    else if (c == 'u')
        ft_putnbru(va_arg(args, unsigned int));
    else if (c == '%')
        ft_putchar('%');
    else if (c == 'p')
    {
        ft_putstr("0x");
        ft_putnbr_hexa((long int)va_arg(args, void *), 0);
    }
    else if (c == 'x')
        ft_putnbr_hexa(va_arg(args, long int), 0);
    else if (c == 'X')
        ft_putnbr_hexa(va_arg(args, long int), 1);

}

int ft_printf(const char *s, ...)
{
    int i;
    va_list args;

    i = 0;
    va_start(args, s);
    while(s[i])
    {
        if (s[i] != '%')
            write(1, &s[i], 1);
        else
        {
            ft_print_args(s[i + 1], args);
            i++;
        }
        i++;
    }
    return (1);
}
