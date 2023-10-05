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

void ft_print_hexa(void *ptr)
{
    uintptr_t temp = (uintptr_t) ptr;
    ft_putnbr(temp);
}

static void ft_print_args(char const c, va_list args)
{
    if (c == 'c')
        ft_putchar(va_arg(args, int));
    else if (c == 's')
        ft_putstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        ft_putnbr(va_arg(args, int));
    else if (c == '%')
        ft_putchar('%');
    else if (c == 'p')
        ft_print_hexa(va_arg(args, void *));
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

int main(void)
{
    //char str[] = "Hello World";
    int i = 3;
    ft_printf("%p\n", &i);
    printf("%p\n", &i);
}
