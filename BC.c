#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char c;
    int sc[4];
    int pg[4];
    int repeat;
    int same;
    int attempts = 0;

    printf("Bulls and Cows\n");
    printf("How to play ?\n1. Computer generates secret 4-digit code.\n2. Player guesses secret 4-digit code.\n3. Computer responds with two counts :\nBulls : Digits in secret code and in right place.\nCows : Digits in secret code but not in right place.\n4. Player keeps guessing until they get 4 Bulls to end the game.\n5. Player gets number of attempts after the game ends.\n");

    printf("Enter a single character from keyboard to start the game :-> ");
    scanf("%c", &c);
    printf("Game starts\n");

    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        do
        {
            sc[i] = rand() % 10;
            repeat = 0;
            for (int j = 0; j < i; j++)
            {
                if (sc[i] == sc[j])
                {
                    repeat++;
                    break;
                }
            }
        } while (repeat);
    }
    printf("The computer has generated a secret 4-digit code. Guess it :\n");

    while (1)
    {
        int bulls = 0;

        printf("Enter guess :\n");
        for (int i = 0; i < 4; i++)
        {
            do
            {
                if (same)
                {
                    printf("Do not enter same digits.\n");
                }
                same = 0;
                printf("Digit %d :-> ", (i + 1));
                scanf("%d", &pg[i]);
                for (int j = 0; j < i; j++)
                {
                    if (pg[i] == pg[j])
                    {
                        same++;
                        break;
                    }
                }
            } while (same);
        }

        attempts++;

        printf("Bulls : ");
        for (int i = 0; i < 4; i++)
        {
            if (pg[i] == sc[i])
            {
                printf("%d", pg[i]);
                bulls++;
            }
        }
        printf("\n");

        printf("Cows  : ");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (pg[i] != sc[i] && pg[i] == sc[j])
                {
                    printf("%d", pg[i]);
                }
            }
        }
        printf("\n");

        if (bulls == 4)
        {
            printf("Successfully guessed the 4-digit secret code : ");
            for(int i=0;i<4;i++){
                printf("%d", pg[i]);
            }
            printf("\n");
            break;
        }
    }
    printf("Game ends\n");
    printf("Your number of attempts : %d\n", attempts);
    return 0;
}