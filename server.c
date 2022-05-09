#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#ifndef TAB_SIZE
# define TAB_SIZE 8
# endif
int tab[TAB_SIZE];

void    ft_init_tab_zeroes()
{
    int i;

    i = 0;
    while (i < TAB_SIZE)
    {
        tab[i] = 0;
        i++;
    }
}
int    ft_convert_to_decimal()
{
    int num;
    int n;
    int num_powerof_n;
    int i;

    i = 0;
    num = 0;
    while (i < TAB_SIZE)
    {
        n = 0;
        num_powerof_n = 1;
        if (tab[i] == 1)
        {
            while (n < (TAB_SIZE - i) - 1)
            {
                num_powerof_n *= 2;
                n++;
            }
            num += num_powerof_n;
        }
        i++;
    }
    return (num);
}

void    ft_print_character()
{
    int             ascii;
    unsigned char    c;

    ascii = ft_convert_to_decimal();
    c = (unsigned char ) ascii;
    write (1, &c, 1);
    ft_init_tab_zeroes();
}

/*void    ft_handle_sigusr1(int sig)
{
    int i;
    int j;

    i = 0;
    while (i < TAB_SIZE)
    {
        if (tab[i] == -1)
            break ;
        i++;
    }
    if (i > 7)
    {
        ft_init_tab_zeroes();
        i = 0;
    }
    if (i == 7)
    {
        tab[i] = 0;
        ft_print_character();
        tab[0] = -1;
    }
    else
    {
        tab[i + 1] = -1;
        while (i > 0)
        {
            j = i - 1;
            tab[i] = tab[j];
            i--;
        }
        tab[0] = 0;
    }
}

void    ft_handle_sigusr2(int sig)
{
    int i;
    int j;

    i = 0;
    while (i < TAB_SIZE)
    {
        if (tab[i] == -1)
            break ;
        i++;
    }
    if (i > 7)
    {
        ft_init_tab_zeroes();
        i = 0;
    }
    if (i == 7)
    {
        tab[i] = 1;
        ft_print_character();
        tab[0] = -1;
    }
    else
    {
        tab[i + 1] = -1;
        while (i > 0)
        {
            j = i - 1;
            tab[i] = tab[j];
            i--;
        }
        tab[0] = 1;
    }
}*/


void ft_handle_sigusr1_test()
{
    int i;

    i = 0;
    while (i < TAB_SIZE)
    {
        if (tab[i] == -1)
            break ;
        i++;
    }
    if (i == 7)
    {
        tab[i] = 0;
        ft_print_character();
        tab[0] = -1;
    }
    else
    {
        tab[i] = 0;
        tab[i + 1] = -1;
    }
}

void    ft_handle_sigusr2_test()
{
    int i;

    i = 0;
    while (i < TAB_SIZE)
    {
        if (tab[i] == -1)
            break ;
        i++;
    }
    if (i == 7)
    {
        tab[i] = 1;
        ft_print_character();
        tab[0] = -1;
    }
    else
    {
        tab[i] = 1;
        tab[i + 1] = -1;
    }
}

int main(void)
{
    struct sigaction sig1;
    struct sigaction sig2;

    sig1.sa_flags = SA_RESTART;
    sig1.sa_handler = ft_handle_sigusr1_test;
    sig2.sa_flags = SA_RESTART;
    sig2.sa_handler = ft_handle_sigusr2_test;
    sigaction(SIGUSR1, &sig1, NULL);
    sigaction(SIGUSR2, &sig2, NULL);
    ft_init_tab_zeroes();
    tab[0] = -1;
    printf("MY PROCESS ID IS: %d \n", getpid());
    while (1)
        pause();
}