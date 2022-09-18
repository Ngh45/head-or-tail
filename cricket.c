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
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
int luck(int a, int b);
int bowling(int over);
int bating(int over);
int main()
{
        int num, guess;
        int choose;
        int over, ball;
        int bat, compBat;
        srand(time(NULL));
        num = rand() % 2;
        printf(COLOR_GREEN "0 input is tail and 1 input is head\n");
        scanf("%i", &guess);
        choose = luck(num, guess); // you will bat or bowl
        printf(COLOR_GREEN "How much over?\n");
        scanf("%i", &ball);
        over = ball * 6;
        if (choose == 1 || choose == 0)
        {
                printf("You are bating\n");
                bat = bating(over);
                printf("\nNow your are bowling\n");
                compBat = bowling(over);
                if (bat > compBat)
                {
                        printf("\nYou win by %i runs", bat);
                }
                else
                {
                        printf("\nYou lose by %i runs", bat);
                }
        }
        else
        {
                printf("You are bowling\n");
                compBat = bowling(over);
                printf("\nNow your are bating\n");
                bat = bating(over);
                if (bat > compBat)
                {
                        printf("\nYou win by %i runs", bat);
                }
                else
                {
                        printf("\nYou lose by %i runs", bat);
                }
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
                printf(COLOR_RED "Sorry its tail\n");
                return 2;
        }
        else
        {
                printf(COLOR_RED "Sorry its head\n");
                return 2;
        }
}
int bating(int over)
{
        int bowling, bat[18];
        int run = 0;
        for (int i = 0; i < over; i++)
        {
                srand(time(NULL));
                bowling = rand() % 6 + 1;
                scanf("%i", &bat[i]);
                if (bat[i] != bowling)
                {
                        printf("\t\t\t\t\t%i\n", bowling);
                        run = run + bat[i];
                        continue;
                }
                else
                {
                        printf(COLOR_RED "!!!!!out!!!!!\n");
                        break;
                }
        }
        printf("your run=%i", run);
        return run;
}
int bowling(int over)
{
        int bowling[18], bat;
        int run = 0;
        for (int i = 0; i < over; i++)
        {
                srand(time(NULL));
                bat = rand() % 6 + 1;
                scanf("%i", &bowling[i]);
                if (bowling[i] != bat)
                {
                        printf("\t\t\t\t\t%i\n", bat);
                        run = run + bat;
                        continue;
                }
                else
                {
                        printf(COLOR_RED "!!!!!Computer is out!!!!!\n");
                        break;
                }
        }
        printf("computer run=%i", run);
        return run;
}
