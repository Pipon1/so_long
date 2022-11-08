/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:00:40 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/11 13:25:29 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stddef.h>

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!need[i])
		return ((char *)hay);
	if (!len)
		return (NULL);
	while (i < len && hay[i])
	{
		j = 0;
		while (i + j < len & hay[i + j] == need[j] && need[j])
			j++;
		if (!need[j])
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	(void) ac;
	size_t	n;

	n = 10;
	printf("test origi : %s\n", strnstr(av[1], av[2], n));
	printf("test mine : %s\n", ft_strnstr(av[1], av[2], n));
}*/
