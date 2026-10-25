#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 100

char stack[size];
int top = -1;

void push(char x)
{
    if (top == size - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int isOperator(char x)
{
    return (x == '+' || x == '-' ||
            x == '*' || x == '/' || x == '^');
}

int pde(char x)
{
    if (x == '^')
        return 3;

    if (x == '*' || x == '/')
        return 2;

    if (x == '+' || x == '-')
        return 1;

    return 0;
}

char estack[size][size];
int etop = -1;

void pushExp(char str[])
{
    if (etop == size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    strcpy(estack[++etop], str);
}

void popExp(char str[])
{
    if (etop == -1)
        strcpy(str, "");
    else
        strcpy(str, estack[etop--]);
}

void intopre(char infix[], char prefix[])
{
    char rev[size], postfix[size];
    char temp;
    int i, j = 0;

    for (i = (int)strlen(infix) - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            rev[j++] = ')';
        else if (infix[i] == ')')
            rev[j++] = '(';
        else
            rev[j++] = infix[i];
    }

    rev[j] = '\0';
    top = -1;
    j = 0;

    for (i = 0; rev[i] != '\0'; i++)
    {
        temp = rev[i];

        if (isalnum((unsigned char)temp))
        {
            postfix[j++] = temp;
        }
        else if (temp == '(')
        {
            push(temp);
        }
        else if (temp == ')')
        {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();

            if (!isEmpty())
                pop();
        }
        else if (isOperator(temp))
        {
            while (!isEmpty() &&
                   peek() != '(' &&
                   (pde(peek()) > pde(temp) ||
                   (pde(peek()) == pde(temp) && temp != '^')))
            {
                postfix[j++] = pop();
            }

            push(temp);
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';

    j = 0;

    for (i = (int)strlen(postfix) - 1; i >= 0; i--)
        prefix[j++] = postfix[i];

    prefix[j] = '\0';
}

void pretoin(char prefix[], char infix[])
{
    int i;
    char op1[size], op2[size], temp[size];

    etop = -1;

    for (i = (int)strlen(prefix) - 1; i >= 0; i--)
    {
        if (isalnum((unsigned char)prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';
            pushExp(temp);
        }
        else if (isOperator(prefix[i]))
        {
            popExp(op1);
            popExp(op2);

            sprintf(temp, "(%s%c%s)",
                    op1, prefix[i], op2);

            pushExp(temp);
        }
    }

    popExp(infix);
}

void posttoin(char postfix[], char infix[])
{
    int i;
    char op1[size], op2[size], temp[size];

    etop = -1;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';
            pushExp(temp);
        }
        else if (isOperator(postfix[i]))
        {
            popExp(op2);
            popExp(op1);

            sprintf(temp, "(%s%c%s)",
                    op1, postfix[i], op2);

            pushExp(temp);
        }
    }

    popExp(infix);
}

int main()
{
    int choice;
    char expression[size];
    char result[size];

    printf("\nExpression Conversion Using Stack\n");
    printf("1. Infix to Prefix\n");
    printf("2. Prefix to Infix\n");
    printf("3. Postfix to Infix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter Infix Expression: ");
            scanf("%99s", expression);

            intopre(expression, result);

            printf("Prefix Expression: %s\n", result);
            break;

        case 2:
            printf("Enter Prefix Expression: ");
            scanf("%99s", expression);

            pretoin(expression, result);

            printf("Infix Expression: %s\n", result);
            break;

        case 3:
            printf("Enter Postfix Expression: ");
            scanf("%99s", expression);

            posttoin(expression, result);

            printf("Infix Expression: %s\n", result);
            break;

        default:
            printf("Invalid Choice\n");
    }

    return 0;
}
