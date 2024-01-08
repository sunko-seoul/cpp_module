/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:59:34 by sunko             #+#    #+#             */
/*   Updated: 2024/01/08 11:18:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <cstdlib>
# include "Data.h"

class Serializer
{
	private:
		int	mData;
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer&	operator=(const Serializer& rhs);
		~Serializer();
	public:
		static uintptr_t	serializer(Data* ptr);
		static Data*		deserializer(uintptr_t raw);
};

#endif
