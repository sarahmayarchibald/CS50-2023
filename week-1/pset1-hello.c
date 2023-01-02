#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user
    string answer = get_string("What's your name? ");
    //return user's input
    printf("hello, %s \n", answer);
}
