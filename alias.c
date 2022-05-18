#include "holberton.h"

/**
 * alias - assign and retrieve alias
 * @datash: data relevant directory
 *
 * Description: Func allows for the assignment of a value to a var.
 * The value is retrievable by using this func with the alias.
 * Return: void
 */
void alias(data_shell *datash)
{
	sep_list **mt = &(datash->mem);
	char *key = NULL, *value = NULL, *arg = NULL;
	char *arg_cp = NULL, *token = NULL;
	char **av = datash->p_input;
	int j = 1, found = 1, eror = 0;

	if (!av[1])
		print_alias_val(datash, NULL, NULL, 1);

	while ((arg = av[j]))
	{
		arg_cp = _strdup(arg, mt);

		if (arg_cp)
		{
			if (arg_cp[0] == '=')
			{
				key = _strcat(key, "=", mt);
				token = _strtok(arg_cp + 1, EQUAL);
				key = _strcat(key, token, mt);

				value = _strchr(arg + 1, '=');
				if (value)
					value += 1;
			}

			else
			{
				key = _strtok(arg_cp, EQUAL);
				value = _strchr(arg, '=');

				if (value)
					value += 1;
			}
		}
		if (key && value)
		{
			if (!print_alias_val(datash, key, value, -1))
				add_node(&(datash->alias), key, value);
		}
		else if (key)
		{
			found = print_alias_val(datash, key, value, 0);
		}
		if (!found)
		{
			datash->errmsg = invalidalias(datash, j);
			datash->error = 1;
			display_error(datash);
			error = 1;
		}
		j++;
		found = 1;
	}
	datash->error = error;
}
