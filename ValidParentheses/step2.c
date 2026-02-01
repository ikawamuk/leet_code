#include <stdbool.h>
#include <string.h>

bool isValid(char* s)
{
	char	stack[strlen(s) + 1];
	size_t	i = 0;

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			stack[++i] = *s++;
			continue;
		}
		if ((*s == ')' && stack[i] != '(')
		|| (*s == ']' && stack[i] != '[')
		|| (*s == '}' && stack[i] != '{'))
			return (false);
		s++;
		i--;
	}
	if (i != 0)
		return (false);
	return (true);
}
