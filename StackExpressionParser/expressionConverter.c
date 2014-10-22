#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
int isNumber(char c)
{
	return ('0' <= c) && ('9' >= c);
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
		ret = 1;

	if ((c == '*') || (c == '/'))
		ret = 2;

	return ret;
}

int expConverter(const char *expression, char *output)
{
	int i = 0;
	LinkStack *stack = LinkStack_Create();
	while (expression[i] != '\0')
	{
		if (isNumber(expression[i]))
		{
			sprintf(output, "%c", expression[i]);
		} else if ()
	}
}