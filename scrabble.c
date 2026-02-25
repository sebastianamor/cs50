#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int PUNTO[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    
    string palabra1 = get_string("Player 1 : ");
    string palabra2 = get_string("Player 2: ");

    
    int record1 = compute_score(palabra1);
    int record2 = compute_score(palabra2);

    
    if (record1 > record2)
    {
        printf("Player 1 wins!\n");
    }
    else if (record2 > record1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    
    
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += PUNTO[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += PUNTO[word[i] - 'a'];
        }
       
    }
    
    return score;
}