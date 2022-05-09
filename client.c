#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define TAB_SIZE 8

void    ft_init_tab_zeroes(int *tab)
{
    int i;

    i = 0;
    while (i < TAB_SIZE)
    {
        tab[i] = 0;
        i++;
    }
}

int ft_atoi(char *s)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (s[i] && (s[i] <= '9' && s[i] >= '0'))
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return (num);
}

void     ft_convert_to_binary(int *tab, unsigned char c)
{
    int ascii;
    int i;

    i = TAB_SIZE - 1;
    ascii = (int ) c;
    while (i >= 0)
    {
        if (ascii >= 1)
            tab[i] = ascii % 2;
        else
            tab[i] = ascii / 2;
        ascii /= 2;
        i--;
    }
}

void    ft_send_signals(int pid, int *tab)
{
    int i;

    i = 0;
    while (i < TAB_SIZE)
    {
        if (tab[i] == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(30);
        i++;
    }
    ft_init_tab_zeroes(tab);
}

int main(int ac, char **av)
{
    int tab[TAB_SIZE];
    int i;
    int j;
    int pid;

    if (ac == 3)
    {
        i = 0;
        pid = ft_atoi(av[1]);
        printf("pid: %d", pid);
        while (av[2][i])
        {
            ft_convert_to_binary(tab, av[2][i]);
            ft_send_signals(pid, tab);
            i++;
        }
    }
}