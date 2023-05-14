#include "shell.h"
/**
* _myhistory - history list will be displayed, by line one command,
               followed
* with line numbers, starting with 0.
* @info: structure contains arguments. used to maintain a
* constant prototype function.
* Return: Always 0
*/
int _myhistory(info_t *info)
{
print_list(info-&gt;history);
return (0);
}
/**
* unset_alias - string sets to alias
* @info: A parameter struct
* @str: alias string
*
* Return: Always 0 success, 1 error
*/
int unset_alias(info_t *info, char *str)
{
char *q, b;
int ret;
q = _strchr(str, &#39;=&#39;);
if (!q)
return (1);
b = *q;
*q = 0;
ret = delete_node_at_index(&amp;(info-&gt;alias),
get_node_index(info-&gt;alias, node_starts_with(info-&gt;alias,

str, -1)));
*q = b;
return (ret);
}
/**
* set_alias - string sets to alias
* @info: A parameter struct
* @str: alias string
*
* Return: Always 0 success, 1 error
*/
int set_alias(info_t *info, char *str)
{
char *q;

q = _strchr(str, &#39;=&#39;);
if (!q)
return (1);
if (!*++q)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&amp;(info-&gt;alias), str, 0) == NULL);
}
/**
* print_alias - alias string to be printed
* @node: node of alias
*
* Return: Always 0 success, 1 error
*/
int print_alias(list_t *node)
{
char *q = NULL, *a = NULL;
if (node)
{
q = _strchr(node-&gt;str, &#39;=&#39;);
for (a = node-&gt;str; a &lt;= q; a++)
_putchar(*a);
_putchar(&#39;\&#39;&#39;);
_puts(q + 1);
_puts(&quot;&#39;\n&quot;);
return (0);
}
return (1);
}
/**
* _myalias - imitate alias builtin (man alias)
* @info: a structure contains arguments. used to maintain a
* constant prototype function.
* Return: Always 0
*/
int _myalias(info_t *info)
{
int i = 0;
char *q = NULL;
list_t *node = NULL;
if (info-&gt;argc == 1)
{
node = info-&gt;alias;
while (node)
{
print_alias(node);

node = node-&gt;next;
}
return (0);
}
for (i = 1; info-&gt;argv[i]; i++)
{
q = _strchr(info-&gt;argv[i], &#39;=&#39;);
if (q)
set_alias(info, info-&gt;argv[i]);
else
print_alias(node_starts_with(info-&gt;alias, info-

&gt;argv[i], &#39;=&#39;));
}
return (0);
}
