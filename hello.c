#include <stdio.h>

int main()
{

    char name;
    printf("Input your name,sir:\n");

    if (!scanf("%s", &name))
    {
        printf("\nIncorrect input! Try again please");
        rewind(stdin);
    }

    printf("\nHello %s, nice to see you, sir!", name);

    return 0;
}