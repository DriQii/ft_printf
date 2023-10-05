#include <libft.h>
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    char *str;

    va_start(args, s);
    str = va_arg(args, char *);
    printf("%s\n", s);
    printf("%s\n", str);

    return (1);
}

int main(void)
{
    ft_printf("salut", "ca va fdzfgs");
}
