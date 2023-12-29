/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:23:49 by sunko             #+#    #+#             */
/*   Updated: 2023/12/30 00:53:43 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int					mRawBits;
		static const int	mNumOfFractionBit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copyFixed);
		Fixed& operator=(const Fixed& copyFixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif
