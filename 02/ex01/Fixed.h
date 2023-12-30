/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:23:49 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 01:29:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					mRawBits;
		static const int	mNumOfFractionBit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copyFixed);
		Fixed(const int iRawBits);
		Fixed(const float fRawBits);
		Fixed&					operator=(const Fixed& copyFixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		getNumOfFractionBit(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
