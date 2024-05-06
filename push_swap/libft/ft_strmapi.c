/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:15:35 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 11:56:10 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*char	ft_tolowerstr(unsigned int i, char s)
{
	if (s >= 65 && s <= 90)
		return (s + 32);
	else
		return (s);
	i++;
}
int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	ft_strlcpy(str, argv[1], (len + 1));
	printf("la stringa diventa: %s", ft_strmapi(str, *ft_tolowerstr));
	return (0);
}*/

/*Description: Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.*/