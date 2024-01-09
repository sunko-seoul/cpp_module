/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:30:48 by sunko             #+#    #+#             */
/*   Updated: 2024/01/09 16:09:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

# include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string s);
		std::string	trimWhiteSpace(const std::string& s);
		int			detectType(std::string s);
		bool		tryParseChar(const std::string& s);
		bool		tryParseInt(const std::string&s, long long& result);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		~ScalarConverter();
};

#endif
