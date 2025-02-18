#include <string.h>
#include <stdbool.h>

bool isValid(char *s)
{
    char stack[strlen(s)];
    int index = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            stack[index] = s[i];
            index++;
            break;

        case ')':
        case '}':
        case ']':
            if (index == 0)
            {
                return false;
            }
            if (s[i] == ')')
            {
                if (stack[index - 1] != '(')
                {
                    return false;
                }
                index--;
            }

            if (s[i] == '}')
            {
                if (stack[index - 1] != '{')
                {
                    return false;
                }
                index--;
            }
            if (s[i] == ']')
            {
                if (stack[index - 1] != '[')
                {
                    return false;
                }
                index--;
            }
            break;
        default:
            break;
        }
        i++;
    }
    if (index == 0)
    {
        return true;
    }
    return false;
}