#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define size 100

int stack[size];
int top = -1;

char variables[size];
int values[size];
int count = 0;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int getValue(char ch)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (variables[i] == ch)
            return values[i];
    }

    variables[count] = ch;
    printf("Enter value of %c: ", ch);
    scanf("%d", &values[count]);

    count++;

    return values[count - 1];
}

int main()
{
    char exp[size];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf(" %[^\n]", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isspace((unsigned char)exp[i]))
            continue;

        if (isalpha((unsigned char)exp[i]))
        {
            push(getValue(exp[i]));
        }
        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                case '^':
                    result = (int)pow(a, b);
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
