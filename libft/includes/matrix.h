/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:22:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/09/28 12:04:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	int	*matrix;
	int	rows;
	int	cols;
}	t_matrix;

/**
 * @brief Sets a value from a matrix using the given coordinates, and returns
 * the new value.
 * 
 * @param matrix The matrix to set the value in.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param val The value to set at the given coordinates.
 * @return int The new value at the given coordinates.
 * (-2147483648 if the coordinates are out of bounds)
*/
int			ft_set_matrix(t_matrix *matrix, int x, int y, int val);

/**
 * @brief Returns a value from a matrix using the given coordinates.
 * 
 * @param matrix The matrix to get the value from.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return int The value at the given coordinates.
 * (-2147483648 if the coordinates are out of bounds)
*/
int			ft_get_matrix(t_matrix *matrix, int x, int y);

/**
 * @brief Initializes a matrix with the given dimensions. Sets all values to 0.
 * 
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @return t_matrix The initialized matrix.
 * (rows and cols are set to -1 if the allocation fails)
*/
t_matrix	ft_init_matrix(int rows, int cols);

/**
 * @brief Initializes a matrix with the given dimensions. Sets all values to n.
 * 
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @param n The value to set all values to.
 * @return t_matrix The initialized matrix.
 */
t_matrix	ft_arbitrary_init_matrix(int rows, int cols, int n);

/**
 * @brief Frees the memory allocated for a matrix.
 * Sets the rows and cols to -1.
 * @param matrix The matrix to free.
 */
void		ft_destroy_matrix(t_matrix matrix);

/**
 * @brief Creates a matrix with the given dimensions.
 * 
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @return t_matrix The created matrix.
 * (rows and cols are set to -1 if the allocation fails)
 */
t_matrix	ft_create_matrix(int rows, int cols);
#endif