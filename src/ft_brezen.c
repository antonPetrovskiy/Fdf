/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:16:37 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/31 21:16:38 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_brezen(t_fdf *fdf, t_draw *draw, int i, int j)
{
	draw->signx = draw->x1 >= draw->x0 ? 1 : -1;
	draw->signy = draw->y1 >= draw->y0 ? 1 : -1;
	mlx_pixel_put(fdf->mlx, fdf->win, draw->x1 - fdf->center_x, draw->y1 -
		fdf->center_y, fdf->cor[i][j]->color);
	while (draw->x0 != draw->x1 || draw->y0 != draw->y1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, draw->x0 - fdf->center_x, draw->y0 -
			fdf->center_y, fdf->cor[i][j]->color);
		draw->error2 = draw->error * 2;
		if (draw->error2 > -draw->deltay)
		{
			draw->error -= draw->deltay;
			draw->x0 += draw->signx;
		}
		if (draw->error2 < draw->deltax)
		{
			draw->error += draw->deltax;
			draw->y0 += draw->signy;
		}
	}
}
