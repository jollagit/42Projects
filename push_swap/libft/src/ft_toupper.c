/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:26:42 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/30 19:46:14 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int i)
{
	if (i >= 97 && i <= 122)
		return (i - 32);
	else
		return (i);
}

/*int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("il mio carattere nuovo: %d", ft_toupper(argv[1][0]));
		printf("\n l'originale: %d", toupper(argv[1][0]));
	}
	return (0);
}*/

/*DESCRIPTION: If  c  is  a lowercase letter, toupper()
returns its uppercase equivalent,if an uppercase
representation exists in the current locale. 
Otherwise, it returns c.
RETURN VALUE: The value returned is that of the converted
letter, or c if the conversion was not possible.*/
