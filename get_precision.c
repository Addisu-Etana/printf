#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @formt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *formt, int *i, va_list list)
{
	int ban_i = *i + 1;

	int precision = -1;

	if (formt[ban_i] != '.')
		return (precision);
	precision = 0;
	for (ban_i += 1; formt[ban_i] != '\0'; ban_i++)
	{
		if (is_digit(formt[ban_i]))
		{
			precision *= 10;
			precision += formt[ban_i] - '0';
		}
		else if (formt[ban_i] == '*')
		{
			ban_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = ban_i - 1;
	return (precision);
}
