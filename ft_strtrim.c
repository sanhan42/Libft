/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhan <sanhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:25:23 by sanhan            #+#    #+#             */
/*   Updated: 2020/03/02 16:38:21 by sanhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inSet(char s, char const *set)
{
	int i;

	i = 0;
	while(set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static char	*finish(char *rtn, int i)
{
	rtn[i] = '\0';
	return (rtn);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (end < 0)
		return (0);
	while (s1[start] && inSet(s1[start], set))
		start++;
	if (start == end)
	{
		if(!(rtn = (char *)malloc(sizeof(char) * 1)))
			return (0);
		return (finish(rtn, 0));
	}
	while (end > start && inSet(s1[end], set))
		end--;
	if (!(rtn = (char *)malloc(sizeof(char) * ((end - start + 1) + 1))))
		return (0);
	i = 0;
	while (start <= end)
		rtn[i++] = s1[start++];
	return (finish(rtn, i));
}
