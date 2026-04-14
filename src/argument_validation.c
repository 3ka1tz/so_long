/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:12:27 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/12 11:17:47 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_file_ber(const char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i - 4] == '.' && \
		filename[i - 3] == 'b' && \
		filename[i - 2] == 'e' && \
		filename[i - 1] == 'r')
		return (1);
	return (write(2, "Error!\nMap file must have .ber extension.\n", 43), 0);
}

static int	is_filename_valid(const char *filename)
{
	int	filename_length;

	filename_length = ft_strlen(filename);
	if (filename_length >= 5 && filename[filename_length - 5] != '/')
		return (1);
	return (write(2, "Error!\nMap file must have a valid name.\n", 41), 0);
}

void	validate_map_file(char **argv)
{
	if (!is_file_ber(argv[1]) || !is_filename_valid(argv[1]))
		exit(0);
}
