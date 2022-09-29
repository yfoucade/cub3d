/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sanity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:02:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/29 15:14:22 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

void    ft_check_illegal_chars(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < game->matrix.rows)
    {
        while (x < game->matrix.cols)
        {
            if (ft_get_matrix(&game->matrix, y, x) == -128)
            {
                game->errors |= ERR_ILL_CHR;
                return ;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

// TODO : Check that map is properly closed (no holes)
void    ft_check_closed_map(t_game *game)
{
    (void) game;
}

void    ft_matrix_sanity(t_game *game)
{
    ft_check_illegal_chars(game);
    ft_check_closed_map(game);
}