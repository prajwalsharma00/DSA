#include <string.h>
#include <stdbool.h>
#include <stdio.h>
struct Stack
{
    char a[1];
};

bool isValid(char *s)
{
    struct Stack stack[strlen(s)];
    int index = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            stack[index].a[0] = '(';
            index++;
        }
        else if (s[i] == '{')
        {
            stack[index].a[0] = '{';
            index++;
        }
        else if (s[i] == '[')
        {
            stack[index].a[0] = '[';
            index++;
        }
        else
        {
            if (index == 0)
            {
                return false;
            }
            if (s[i] == ')')
            {
                if (stack[index - 1].a[0] == '(')
                {
                    index--;
                }
                else
                {
                    return false;
                }
            }
            if (s[i] == '}')
            {
                if (stack[index - 1].a[0] == '{')
                {
                    index--;
                }
                else
                {
                    return false;
                }
            }
            if (s[i] == ']')
            {
                if (stack[index - 1].a[0] == '[')
                {
                    index--;
                }
                else
                {
                    return false;
                }
            }
        }
        i++;
    }
    if (index == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    printf("{{}} is valid parenthesis : %s", isValid("{{}}") ? "true" : "false");
}