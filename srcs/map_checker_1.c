/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:50:41 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:11 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_reader(int fd)
{
	while (ft_lstadd_back(map(), ft_lstnew(get_next_line(fd))))
		;
}

int	map_len(void)
{
	size_t	len;
	size_t	len_temp;
	t_list	*temp;

	temp = (*map());
	len_temp = 0;
	len = ft_strlen(temp->content);
	while (temp != NULL)
	{
		if (temp->next != NULL)
			len_temp = ft_strlen(temp->next->content);
		if (len != len_temp)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	check_top_bot(void)
{
	t_list	*top;
	t_list	*bot;
	int		i;
	char	*content_temp;

	top = (*map());
	bot = ft_lstlast(top);
	i = 0;
	content_temp = top->content;
	if (ft_strncmp(top->content, bot->content, ft_strlen(top->content)) == 0)
	{
		while (content_temp[i] != '\n')
		{
			if (content_temp[i] != '1')
				return (-1);
			i++;
		}
	}
	else
		return (-1);
	return (0);
}

int	check_border(void)
{
	t_list	*temp;
	size_t	len;
	char	*content_temp;

	temp = (*map());
	len = ft_strlen(temp->next->content);
	while (temp->next != NULL)
	{
		content_temp = temp->next->content;
		if (content_temp[0] != '1'
			|| content_temp[len - 2] != '1')
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	check_map_build(void)
{
	t_list	*temp;
	int		i;
	char	*content_temp;

	temp = (*map());
	while (temp != NULL)
	{
		content_temp = temp->content;
		i = 0;
		while (content_temp[i] != '\n')
		{
			if (content_temp[i] != '1' && content_temp[i] != '0'
				&& content_temp[i] != 'C' && content_temp[i] != 'P'
				&& content_temp[i] != 'E' && content_temp[i] != 'X')
				return (-1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}
