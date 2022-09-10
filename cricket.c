/**
 * @file cricket.c
 * @author NIghaban Hassan
 * @brief This is head or tail game with old school hand sign criket
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int luck(int a, int b);
void bowling();
void bating();
int main()
{
    int num, guess;
    int choose;
    srand(time(NULL));
    num = rand() % 2;
    printf("0 input is tail and 1 input is head\n");
    scanf("%i", &guess);
    choose = luck(num, guess); // you will bat or bowl
    if (choose == 1 || choose == 0)
    {
        printf("You are bating\n");
        bating();
    }
    else
    {
        printf("You are bowling\n");
        bowling();
    }
    return 0;
}
int luck(int a, int b)
{
    if (a == 1 && a == b)
    {
        printf("Congratulation it's head\n");
        return 1;
    }
    else if (a == 0 && a == b)
    {
        printf("Congratulation it's tail\n");
        return 0;
    }
    else if (a == 0 && a != b)
    {
        printf("Sorry its tail\n");
        return 2;
    }
    else
    {
        printf("Sorry its head\n");
        return 2;
    }
}
void bating()
{
    int bowling, bat[6];
    int score = 0;
    srand(time(NULL));
    bowling = rand() % 6 + 1;
    for (int i = 0; i < 6; i++)
    {
        scanf("%i", &bat[i]);
        if (bat[i] != bowling)
        {
            score = score + bat[i];
            continue;
        }
        else
        {
            printf("!!!!!out!!!!!\n");
            break;
        }
    }
    printf("your score=%i", score);
}
void bowling()
{
    int bowling[6], bat;
    int score = 0;
    srand(time(NULL));
    bat = rand() % 6 + 1;
    for (int i = 0; i < 6; i++)
    {
        scanf("%i", &bowling[i]);
        if (bowling[i] != bat)
        {
            score = score + bat;
            continue;
        }
        else
        {
            break;
        }
    }
    printf("computer score=%i", score);
}