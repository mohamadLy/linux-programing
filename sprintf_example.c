#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[24];
    int i = 23;

    sprintf(str, "Value of i = %d", i);

    printf("%s\n", str);

    int n = strlen(str);

    printf("Length of str is %d\n", n);

    return 0;
}

