/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:16:01 by sunko             #+#    #+#             */
/*   Updated: 2024/01/15 16:13:47 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string& lhs, const std::string& rhs)
	: mInputData(),
	  mDatabase(),
	  mInputDataFilePath(lhs),
	  mDatabaseFilePath(rhs),
	  mInputDataFile(lhs),
	  mDatabaseFile(rhs)
{
	if (!mInputDataFile.is_open() || !mDatabaseFile.is_open())
		throw std::ios_base::failure("file open failure");
	this->parseInputData();
	this->parseDatabase();
}

BitcoinExchange::~BitcoinExchange()
{
	mInputDataFile.close();
	mDatabaseFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
	: mInputData(rhs.mDatabase),
	  mDatabase(rhs.mDatabase),
	  mInputDataFilePath(rhs.mInputDataFilePath),
	  mDatabaseFilePath(rhs.mDatabaseFilePath),
	  mInputDataFile(rhs.mInputDataFilePath),
	  mDatabaseFile(rhs.mDatabaseFilePath)
{
	if (!mInputDataFile.is_open() || !mDatabaseFile.is_open())
		throw std::ios_base::failure("file open failure");
	mInputDataFile.copyfmt(rhs.mInputDataFile);
	mDatabaseFile.copyfmt(rhs.mDatabaseFile);
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return (*this);
	mInputData = rhs.mInputData;
	mDatabase = rhs.mDatabase;
	mInputDataFilePath = rhs.mInputDataFilePath;
	mDatabaseFilePath = rhs.mDatabaseFilePath;

	if (mInputDataFile.is_open())
		mInputDataFile.close();
	if (mDatabaseFile.is_open())
		mDatabaseFile.close();

	mInputDataFile.open(mInputDataFilePath);
	mDatabaseFile.open(mDatabaseFilePath);
	if (!mInputDataFile.is_open() || !mDatabaseFile.is_open())
		throw std::ios_base::failure("file open failure");

	mInputDataFile.copyfmt(rhs.mInputDataFile);
	mDatabaseFile.copyfmt(rhs.mDatabaseFile);
	return (*this);
}

void	BitcoinExchange::parseInputData(void)
{
	std::string	line;
	std::getline(mInputDataFile, line);

	while (std::getline(mInputDataFile, line))
	{
		try
		{
			std::string::iterator delim_iter = std::find(line.begin(), line.end(), '|');
			if (delim_iter == line.end())
				throw std::runtime_error("input.txt format error");
			std::string date(line.begin(), delim_iter);
			std::string valueString(delim_iter + 1, line.end());
			std::istringstream iss(valueString);
			double value = 0;
			iss >> value;
			if (iss.fail())
				throw std::runtime_error("input.txt format error");
			mInputData.insert(std::pair<std::string, double>(date, value));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	BitcoinExchange::parseDatabase(void)
{
	std::string	line;
	std::getline(mDatabaseFile, line); // date,exchange_rate(format)

	while (std::getline(mDatabaseFile, line))
	{
		try
		{
			std::string::iterator comma_iter = std::find(line.begin(), line.end(), ',');
			if (comma_iter == line.end())
				throw std::runtime_error("data.csv format error");
			std::string date(line.begin(), comma_iter);
			std::string exchageRateString(comma_iter + 1, line.end());
			std::istringstream iss(exchageRateString);
			double exchageRate = 0;
			iss >> exchageRate;
			if (iss.fail())
				throw std::runtime_error("data.csv format error");
			mDatabase.insert(std::pair<std::string, double>(date, exchageRate));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

