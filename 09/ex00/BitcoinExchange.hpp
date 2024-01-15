/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:10:30 by sunko             #+#    #+#             */
/*   Updated: 2024/01/15 16:04:12 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <fstream>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	mInputData;
		std::map<std::string, double>	mDatabase;
		std::string						mInputDataFilePath;
		std::string						mDatabaseFilePath;
		std::ifstream					mInputDataFile;
		std::ifstream					mDatabaseFile;
		BitcoinExchange();
	public:
		BitcoinExchange(const std::string& lhs, const std::string& rhs);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		void	parseInputData();
		void	parseDatabase();
};

#endif
