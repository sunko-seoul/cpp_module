/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SmartPointer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:14:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 22:44:45 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMART_POINTER_H
# define SMART_POINTER_H

# include "AMateria.h"

class SmartPointer
{
	private:
		AMateria	*mMateriaPtr;
		SmartPointer();
		SmartPointer&	operator=(const SmartPointer& src);
		SmartPointer(const SmartPointer& src);
	public:
		SmartPointer(AMateria* materiaPtr);
		~SmartPointer();
};

#endif
