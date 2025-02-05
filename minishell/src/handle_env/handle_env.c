#include "minishell.h"

char	*ft_getenv(char **env, char *val)
{
	size_t	i;
	char	*var;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], val, ft_strlen(val)) == 0
			&& env[i][ft_strlen(val)] == '=')
		{
			var = ft_substr(env[i], (ft_strlen(val) + 1), ft_strlen(env[i]));
			return (var);
		}
		i++;
	}
	return (NULL);
}

t_environ *init_env(char **envp)
{
	size_t		count;
	t_environ	*env;

	env = malloc(sizeof(t_environ));
	count = 0;
	while (envp[count])
		count++;
	env->var = ft_calloc(count + 1, sizeof(char *));
	count = 0;
	while (envp[count])
	{
		env->var[count] = ft_strdup(envp[count]);
		count++;
	}
	env->var[count] = NULL;
	return (env);
}
