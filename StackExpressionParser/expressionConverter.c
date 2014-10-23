#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linkstack.h"

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int priority(char c)
{
	int ret = 0;

	if ((c == '+') || (c == '-'))
	{
		ret = 1;
	}

	if ((c == '*') || (c == '/'))
	{
		ret = 2;
	}

	return ret;
}

void output(char c, char *out)
{
	if (c != '\0')
	{
		char tmp[256] = { 0 };
		sprintf(tmp, "%c", c);
		strcat(out, tmp);
	}
}

int express(int left, int right, char op)
{
	int ret = 0;

	switch (op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}

int value(char c)
{
	return (c - '0');
}

char toChar(int a)
{
	return (char)(((int)'0') + a);
}
extern void transform(const char* exp, char *out)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			output(exp[i], out);
		}
		else if (isOperator(exp[i]))
		{
			while (LinkStack_Top(stack) != NULL && priority(exp[i]) <= priority(*((char *)LinkStack_Top(stack))))
			{
				output(*((char *)LinkStack_Pop(stack)), out);
			}

			LinkStack_Push(stack, (void*)&exp[i]);
		}
		else if (isLeft(exp[i]))
		{
			LinkStack_Push(stack, (void*)&exp[i]);
		}
		else if (isRight(exp[i]))
		{
			//char c = '\0';
			while (LinkStack_Top(stack) && !isLeft(*((char *)LinkStack_Top(stack))))
			{
				output(*((char *)LinkStack_Pop(stack)), out);
			}

			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	while ((LinkStack_Size(stack) > 0) && (exp[i] == '\0'))
	{
		output(*((char *)LinkStack_Pop(stack)), out);
	}

	LinkStack_Destroy(stack);
}

extern int compute(const char *exp)
{
	LinkStack *stack = LinkStack_Create();
	int ret = 0;
	int i = 0;
	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			LinkStack_Push(stack, (void *)&exp[i]);
		}
		else if (isOperator(exp[i]))
		{
			int right = value(*((char *)LinkStack_Pop(stack)));
			int left = value(*((char *)LinkStack_Pop(stack)));
			int result = express(left, right, exp[i]);
			char cresult = toChar(result);
			LinkStack_Push(stack, (void *)&cresult);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}
		i++;
	}
	if ((LinkStack_Size(stack) == 1) && (exp[i] == '\0'))
	{
		ret = value(*((char *)LinkStack_Pop(stack)));
	}
	else
	{
		printf("Invalid expression!");
	}

	LinkStack_Destroy(stack);

	return ret;

}
