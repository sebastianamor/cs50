#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    
    string text = get_string("Text: ");

    int carta = count_letters(text);
    int palabra = count_words(text);
    int sentaencia = count_sentences(text);

    float L = ((float)carta / palabra) * 100;
    
    float S = ((float)sentaencia / palabra) * 100;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    int grade = (int)round(index);

    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int contador = 0;
    
   
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            contador++;
        }
    }
    
    return contador;
}

int count_words(string text)
{
    int contador = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            contador++;
        }
    }
    
    if (strlen(text) > 0)
    {
        contador++;
    }
    
    return contador;
}

int count_sentences(string text)
{
    int contador = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            contador++;
        }
    }
    
    return contador;
}