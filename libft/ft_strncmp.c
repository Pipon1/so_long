/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:28:07 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/11 13:03:51 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	(void) ac;
	size_t n;

	n = 3;
	printf("les strings a cmp sont : %s et %s\n", av[1], av[2]);
	printf("origi : %d\n", strncmp(av[1], av[2], n));
	printf("mine : %d\n", ft_strncmp(av[1], av[2], n));
	return (1);
}*/
