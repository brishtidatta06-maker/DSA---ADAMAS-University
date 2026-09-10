#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push character into stack */
void push(char ch)
{
    stack[++top] = ch;
}

/* Pop character from stack */
char pop()
{
    return stack[top--];
}

/* Return precedence of operator */
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

/* Check whether character is an operand */
int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;

    return 0;
}

/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

/* Evaluate postfix expression */
int evaluatePostfix(char postfix[])
{
    int valueStack[MAX];
    int valueTop = -1;
    int i = 0;
    int a, b, result;
    char ch;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];

        if (isOperand(ch))
        {
            valueStack[++valueTop] = ch - '0';
        }
        else
        {
            b = valueStack[valueTop--];
            a = valueStack[valueTop--];

            if (ch == '+')
                result = a + b;
            else if (ch == '-')
                result = a - b;
            else if (ch == '*')
                result = a * b;
            else if (ch == '/')
                result = a / b;

            valueStack[++valueTop] = result;
        }

        i++;
    }

    return valueStack[valueTop];
}
int main()

{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}