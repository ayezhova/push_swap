/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:58:00 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/17 13:27:59 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 48

# include "../includes/push_swap.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
