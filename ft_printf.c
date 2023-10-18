int	ft_printf(const char *str, ...)
{
    va_list args;
    int     i;
    int     padding;
    int     output_len;
    int     chars_written;
    void    *tmp;
    char    *str_tmp;

    i = 0;
    output_len = 0;
    chars_written = 0;
    va_start(args, str);
    while (*str != '\0')
    {
        while (str[i] != '%' && str[i] != '\0')
            i++;
        chars_written += write(1, str, i);
        str += i;
        if (ft_isdigit(*str))
        {
            while (*str == '0')
                str++; //nel bonus aggiungere una flag
            padding = ft_atoi(str);
            str += ft_nbrlen(padding, 10);
            if (*str == 'c' || *str == '%')
                output_len = 1;
            else if(*str == 's')
            {
                tmp = (void *)va_arg(args, char *);
                output_len = ft_strlen((char *)tmp);
            }
            else if(*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
            {
                tmp = (void *)&va_arg(args, int);
                if (*str == 'd' || *str == 'i')
                    output_len = ft_nbrlen(*((int *)tmp), 10);
                else
                    output_len = ft_nbrlen(*((int *)tmp), 16);
            }
            else if(*str == 'u' || *str == 'x' || *str == 'X')
            {
                tmp = (void *)&va_arg(args, unsigned int);
                output_len = ft_nbrlen(*((unsigned int *)tmp), 10);
            }
            else if(*str == 'p')
            {
                tmp = (void *)&va_arg(args, void *);
                output_len = ft_nbrlen(tmp, 16);
            }
            if (padding > output_len)
            {
                padding -= output_len;
                while (padding-- > 0)
                    chars_written += write(1, " ", 1);
            }
        }
        if (*str == 'c')
            chars_written += write(1, &va_arg(args, char), 1);
        else if (*str == '%')
            chars_written += write(1, "%", 1);
        else if (*str == 's')
            chars_written += write(1, tmp, ft_strlen(tmp));
        else if (*str == 'd' || *str == 'i')
        {
            str_tmp = ft_itoa(*(int *)tmp);
            chars_written += write(1, str_tmp, ft_strlen(str_tmp));
            free(str_tmp);
        }
        else if (*str == 'x' || *str == 'X')
        {
            if (*str == 'x')
                ft_putnbr_base(*(int *)tmp, "0123456789abcdef");
            else if (*str == 'X')
                ft_putnbr_base(*(int *)tmp, "0123456789ABCDEF");
            chars_written += ft_nbrlen(*(int *)tmp, 16);
        }
        else if (*str == 'p')
        {
            chars_written += ft_nbrlen((long long)tmp, 16) + write(1, "0x", 2);
            ft_putnbr_base((long long)tmp, "0123456789abcdef");
        }
        str++;
        i = 0;
    }
    va_end(args);
    return (chars_written);
}
