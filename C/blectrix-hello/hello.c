#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User inputs their name.
    string name = get_string("Please Enter Your Name: \n");
    //System Displaying
    printf("hello, %s\n", name);
}