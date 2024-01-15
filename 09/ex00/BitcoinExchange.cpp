/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:16:01 by sunko             #+#    #+#             */
/*   Updated: 2024/01/16 00:27:36 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <map>

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
}

BitcoinExchange::~BitcoinExchange()
{
	mInputDataFile.close();
	mDatabaseFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
	: mInputData(rhs.mInputData),
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

bool	BitcoinExchange::isValidDate(int year, int month, int day)
{
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "error" << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::searchDatabase(std::time_t timestamp, const std::string& date, double value)
{
	std::map<std::time_t, double>::iterator iter;

	iter = mDatabase.find(timestamp);
	if (iter != mDatabase.end())
		std::cout << date << " => " << value << " = " << iter->second * value << std::endl;
	else
	{
		iter = mDatabase.upper_bound(timestamp);
		if (iter != mDatabase.begin())
			--iter;
		else
			throw std::runtime_error("Error: not found date");
		std::cout << date << " => " << value << " = " << iter->second * value << std::endl;
	}
}

// getline
// date parse => serach date => calculate value
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
				throw std::runtime_error("Error: input.txt file format");
			std::string date(line.begin(), delim_iter);
			std::tm tm = {};
			std::istringstream dateIss(date);
			dateIss >> std::get_time(&tm, "%Y-%m-%d");
			if (dateIss.fail() || !isValidDate(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday))
			{
				std::ostringstream errorMsg;
				errorMsg << "Error: bad input => " << date;
				std::runtime_error error(errorMsg.str());
				throw error;
			}
			std::string valueString(delim_iter + 1, line.end());
			std::istringstream valueIss(valueString);
			double value = 0;
			valueIss >> value;
			if (valueIss.fail())
			{
				std::ostringstream errorMsg;
				errorMsg << "Error: bad input => " << valueString;
				std::runtime_error error(errorMsg.str());
				throw error;
			}
			else if (value < 0)
				throw std::runtime_error("Error: not a positive number.");
			else if (value > 1000)
				throw std::runtime_error("Error: to large number.");
			std::time_t timestamp = std::mktime(&tm);
			searchDatabase(timestamp, date, value);
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
	std::getline(mDatabaseFile, line);

	while (std::getline(mDatabaseFile, line))
	{
		try
		{
			std::string::iterator comma_iter = std::find(line.begin(), line.end(), ',');
			if (comma_iter == line.end())
				throw std::runtime_error("Error: data.csv format error");
			std::string date(line.begin(), comma_iter);
			std::istringstream dateIss(date);
			std::tm tm = {};
			dateIss >> std::get_time(&tm, "%Y-%m-%d");
			std::time_t timestamp = std::mktime(&tm);
			std::string exchageRateString(comma_iter + 1, line.end());
			std::istringstream valueIss(exchageRateString);
			double exchageRate = 0;
			valueIss >> exchageRate;
			if (valueIss.fail())
				throw std::runtime_error("Error: data.csv format error");
			mDatabase.insert(std::pair<std::time_t, double>(timestamp, exchageRate));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

std::time_t	BitcoinExchange::getTimeStamp(const std::string& date)
{
	std::istringstream iss(date);
	std::tm tm = {};
	iss >> std::get_time(&tm, "%Y-%m-%d");
	return (std::mktime(&tm));
}

