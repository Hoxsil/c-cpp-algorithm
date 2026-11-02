#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100
        || (a + b <= c) || (a + c <= b) || (b + c <= a))
        printf("error");
    else if (a == b && b == c)
        printf("equilateral");
    else if (a == b || a == c || b == c)
        printf("isosceles");
    else
        printf("general");
    return 0;
}
