#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

int isleft(char c)
{
	int ret = 0;
	switch (c)
	{
	case '<':
	case '(':
	case '[':
	case '{':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int isright(char c)
{
	int ret = 0;

	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int ismatch(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int grammarAnalyze(const char* line)
{
	int ret = 0;
	if (line == NULL)
		return -1;
	int i = 0;
	LinkStack *stack = NULL;
	stack = LinkStack_Create();
	if (stack == NULL)
		return -2;
	while (*(line + i) != '\0')
	{
		if (isalpha(line[i]))
		{
			i++;
			continue;
		}
		else if (isleft(line[i]))
		{
			LinkStack_Push(stack, (void *)&line[i]);
		}
		else if (isright(line[i]))
		{
			char *tmp;
			tmp = (char *)LinkStack_Pop(stack);
			if (tmp == NULL || !ismatch(*tmp, line[i]))
			{
				break;
			}
		}

		i++;
	}
	if (LinkStack_Size(stack) == 0 && line[i] == '\0')
	{
		ret = 1;
	}
	LinkList_Destroy(stack);
	return ret;
}