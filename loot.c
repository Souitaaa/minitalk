/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:27:20 by csouita           #+#    #+#             */
/*   Updated: 2024/04/20 02:30:42 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
int ft_atoi(const char *str)
{
    int i;
    int res;
    int signe;

    i = 0;
    signe = 1;
    res = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * signe);
}
size_t ft_count_digits(int number)
{
    int i;
    i = 0;
    while (number)
    {
        number /= 10;
        i++;
    }
    return i;
}
char *ft_itoa(int number)
{
    size_t len;
    char *str;
    long int n;

    n = number;
    len = ft_count_digits(n);
    if (n < 0)
    {
        number *= -1;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    *(str + len) = '\0';
    while (len--)
    {
        *(str + len) = (number % 10) + 48;
        number /= 10;
    }
    if (n < 0)
        *(str) = '-';
    return str;
}
void ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(1, s, i);
}
