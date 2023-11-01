/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:10 by gvigano           #+#    #+#             */
/*   Updated: 2023/11/01 12:01:58 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}
/*void	ft_tolowerstr(unsigned int i, char *s)
{
	while (s[i] != 0)
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		i++;
	}
}
int	main(int argc, char *argv[])
{
	char	str[50];
	size_t	len;
	
	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	ft_strlcpy(str, argv[1], (len + 1));
	ft_striteri(str, *ft_tolowerstr);
	printf("la stringa diventa: %s", str);
	return (0);
}*/

/*Description: Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
Return value: None*/