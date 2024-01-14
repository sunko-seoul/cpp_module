/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:57:47 by sunko             #+#    #+#             */
/*   Updated: 2024/01/15 00:06:10 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN()
	: mStack(), mExpr(), mResult(0)
{}

RPN::RPN(const std::string& expr)
	: mStack(), mExpr(expr), mResult(0)
{}

RPN::RPN(const RPN& rhs)
	: mStack(rhs.mStack), mExpr(rhs.mExpr), mResult(0)
{}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		return (*this);
	mStack = rhs.mStack;
	mExpr = rhs.mExpr;
	mResult = 0;
	return (*this);
}

RPN::~RPN()
{}

void	RPN::calculateExpr(void)
{
	for (std::string::size_type i = 0; i < mExpr.length(); ++i)
	{
		switch (mExpr[i])
		{
			case '+':
				calculatePlus();
				break;
			case '-':
				calculateMinus();
				break;
			case '*':
				calculateMultiply();
				break;
			case '/':
				calculateDivide();
				break;
			case ' ':
				break;
			default:
				if (!std::isdigit(mExpr[i]))
					throw std::invalid_argument("Error : invalid argument");
				mStack.push(mExpr[i] - '0');
				/* calculateDecimal */
				break;
		}
	}
	if (mStack.size() != 1)
		throw std::invalid_argument("Error : invalid reverse polish notation");
	std::cout << mStack.top() << std::endl;
}

void	RPN::calculatePlus(void)
{
	if (mStack.size() < 2)
		throw std::invalid_argument("Error : invalid reverse polish notation");
	int num1= mStack.top();
	mStack.pop();
	int num2 = mStack.top();
	mStack.pop();
	mResult = num2 + num1;
	mStack.push(mResult);
}

void	RPN::calculateMinus(void)
{
	if (mStack.size() < 2)
		throw std::invalid_argument("Error : invalid reverse polish notation");
	int num1= mStack.top();
	mStack.pop();
	int num2 = mStack.top();
	mStack.pop();
	mResult = num2 - num1;
	mStack.push(mResult);
}

void	RPN::calculateMultiply(void)
{
	if (mStack.size() < 2)
		throw std::invalid_argument("Error : invalid reverse polish notation");
	int num1= mStack.top();
	mStack.pop();
	int num2 = mStack.top();
	mStack.pop();
	mResult = num2 * num1;
	mStack.push(mResult);
}

void	RPN::calculateDivide(void)
{
	if (mStack.size() < 2)
		throw std::invalid_argument("Error : invalid reverse polish notation");
	int num1= mStack.top();
	if (num1 == 0)
		throw std::runtime_error("Error : not divide zero");
	mStack.pop();
	int num2 = mStack.top();
	mStack.pop();
	mResult = num2 / num1;
	mStack.push(mResult);
}
