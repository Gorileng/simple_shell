#include "shell.h"

/**
<<<<<<< HEAD
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
=======
 * _myexit - exits shell
 * @info: the structure that contains the potential argument that maintain
 * constant function of the prototype.
 * Return: exit status
 * (0) if info.argv[0] != "exit"
 */

>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
int _myexit(info_t *info)
{
	int exitcheck;

<<<<<<< HEAD
	if (info->argv[1]) /* If there is an exit arguement */
=======
	if (info->argv[1]) /* If there's an exit argument */
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
<<<<<<< HEAD
			print_error(info, "Illegal number: ");
=======
			print_error(info, "It is Illegal number: ");
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
<<<<<<< HEAD
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
=======
 * _mycd - current directory of the process alters.
 * @info: the structure that contains the potential arguments that maintain
 * constant function of the prototype.
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
 * Return: Always 0
 */
int _mycd(info_t *info)
{
<<<<<<< HEAD
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
=======
	char *w, *dir, buffer[1024];
	int chdir_ret;

	w = getcwd(buffer, 1024);
	if (!w)
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
<<<<<<< HEAD
			_puts(s);
=======
			_puts(w);
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
<<<<<<< HEAD
		print_error(info, "can't cd to ");
=======
		print_error(info, "cannot cd to ");
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
<<<<<<< HEAD
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
=======
 * _myhelp - current directory of the process alters
 * @info: the structure that contains the potential arguments that maintain
 * constant function of the prototype.
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

<<<<<<< HEAD

=======
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
