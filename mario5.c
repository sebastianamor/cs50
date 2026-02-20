#include <cs50.h>
#include <stdio.h>

void print_row(int espacios, int Bloques);

int main(void)
{
    int altura;
    do
    {
        altura = get_int("bloques: ");
    }
    while (altura < 1);

    for (int i = 0; i < altura; i++)
    {
       
        int espacios = altura - i - 1;  
        int bloques = i + 1;           
        print_row(espacios, bloques);
    }
}

void print_row(int espacios, int bloques)
{

    for (int i = 0; i < espacios; i++)
    {
        printf(" ");
    }
    
   
    for (int i = 0; i < bloques; i++)
    {
        printf("#");
    }
    printf("\n");
}