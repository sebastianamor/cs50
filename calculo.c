#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    int cents;
    do
    {
        cents = get_int("Cambio de: ");
    }
    while (cents < 0);

    int coins = 0;
    int remaining = cents;

    int quarters = remaining / 25;
    coins += quarters;
    remaining = remaining % 25;

    int dimes = remaining / 10;
    coins += dimes;
    remaining = remaining % 10;

    int nickels = remaining / 5;
    coins += nickels;
    remaining = remaining % 5;

    int pennies = remaining;
    coins += pennies;

    printf("%i\n", coins);
}
