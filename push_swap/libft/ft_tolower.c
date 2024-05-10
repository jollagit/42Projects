/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:36:32 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 19:44:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int i)
{
	if (i >= 65 && i <= 90)
		return (i + 32);
	else
		return (i);
}

/*int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("il mio carattere nuovo: %d", ft_tolower(argv[1][0]));
		printf("\n l'originale: %d", tolower(argv[1][0]));
	}
	return (0);
}*/

/*DESCRIPTION: If c is an uppercase letter, tolower()
returns its lowercase equivalent, if a lowercase
representation exists in the current locale.
Otherwise, it returns  c.
If c is an uppercase letter, tolower() returns its
lowercase equivalent, if a lowercase representation
exists in the current locale.
Otherwise, it returns  c.*/