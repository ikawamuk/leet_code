#include <stdbool.h>

bool isValid(char* s)
{
	char	stack[10000] = {0};
	int		i = 0;

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			stack[++i] = *s++;
			continue;
		}
		if (*s == ')')
		{
			s++;
			if (stack[i--] != '(')
				return (false);
			continue ;
		}
		if (*s == '}')
		{
			s++;
			if (stack[i--] != '{')
				return (false);
			continue ;
		}
		if (*s == ']')
		{
			s++;
			if (stack[i--] != '[')
				return (false);
			continue ;
		}
		return (false);
	}
	if (i != 0)
		return (false);
	return (true);
}
