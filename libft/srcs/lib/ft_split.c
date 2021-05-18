/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:10:34 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int		ft_nb_words(const char *s, char c)
{
	int nb_w;
	int i;

	i = -1;
	nb_w = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nb_w++;
	return (nb_w);
}

static int		ft_nb_char(const char *s, char c)
{
	int nb_char;
	int i;

	i = -1;
	nb_char = 0;
	while (s[++i] != c && s[i] != 0)
		nb_char++;
	return (nb_char);
}

static char		**free_tab(char **tab, int nb_w)
{
	int i;

	i = -1;
	while (++i < nb_w)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char		**ft_malloc_fill(const char *s, char c, char **tab, int nb_w)
{
	int i;
	int j;
	int nb_char;

	i = -1;
	while (++i < nb_w)
	{
		while (*s == c)
			s++;
		nb_char = ft_nb_char(s, c);
		if (!(tab[i] = (char*)malloc(sizeof(char) * (nb_char + 1))))
			return (free_tab(tab, nb_w));
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = 0;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_split(char	const *s, char c)
{
	int		nb_w;
	char	**tab;

	if (s == NULL)
		return (NULL);
	nb_w = ft_nb_words(s, c);
	if (!(tab = (char**)malloc((sizeof(char*) * (nb_w + 1)))))
		return (NULL);
	tab = ft_malloc_fill(s, c, tab, nb_w);
	return (tab);
}
