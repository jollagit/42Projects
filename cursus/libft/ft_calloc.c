/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:16:34 by gvigano           #+#    #+#             */
/*   Updated: 2023/10/27 15:56:48 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*int	main (int argc, char *argv[])
{
	char	*ptr;
	size_t	n_elem;

	if (argc != 3)
		return (0);
	ptr = (int *)ft_calloc(argv[1], argv[2]);
	if (!ptr)
		printf("l'allocazione di memoria e' fallita");
	else 
		printf("l'allocazione e' andata a buon fine:");
	free(ptr);
	return (0);
}*/

/*The  calloc()  function allocates memory for an array of nmemb
  elements of size bytes each and returns a pointer to the allocated
  memory.The memory is set to zero.If nmemb or size is 0, then
  calloc() returns either NULL, or a unique pointer value that
  can later be successfully passed to free().
  If the multiplication of nmemb and size would result  in
  integer  overflow,  then calloc() returns an error.
  calloc() functions return a pointer to the allocated memory.
  On error, these functions return NULL.*/