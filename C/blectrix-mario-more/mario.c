#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declarering the value that will be entered by the user
    int n;

    // Get the height input
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Desired pyramid height
    for (int i = 0; i < n; i++)
    {
        // Setting up columns to print out
        for (int j = 0; j < n + i + 3; j++)
        {
            if (j == n || j == n + 1 || i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}