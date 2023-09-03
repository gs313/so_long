/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeanderror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:09:51 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/03 11:18:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_sizeanderror(t_info *game, char **argv)
{
    int fd;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
    if(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
    {
        perror("Error\n");
        exit(EXIT_FAILURE);
    } 
    game->map.width = 0; //need a function here
    game->map.height = 0; //need a function here                          
}