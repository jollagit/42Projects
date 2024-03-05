/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:00:41 by gvigano           #+#    #+#             */
/*   Updated: 2024/03/05 16:37:51 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	t;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	t = 0;
	if (s1)
		while (s1[++i] != '\0')
			ptr[i] = s1[i];
	while (s2[t] != '\0')
		ptr[i++] = s2[t++];
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*funzione ft_strjoin (che non avevo strutturato bene)
USATA PER CONCATENARE IL CONTENUTO LETTO DA FD CON QUELLO ESISTENTE:
 @ ) Se s1 e' NULL alloco la memoria per una stringa vuota
cosi che se s1 e' inizialmente NULL si comporta comunque
come una stringa vuota.
 @ ) Dopo controllo se s1 o s2 sono NULL, se una delle due
e' NULL restituisco NULL per indicare un errore.
 @ ) alla fine libero la memoria allocata per l'originale s1
(visto che e' stata dinamicamente allocata) per evitare 
perdite di memoria.
*/