/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:54:04 by sunko             #+#    #+#             */
/*   Updated: 2024/01/14 23:55:00 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<int>	mStack;
		std::string		mExpr;
		int				mResult;
		RPN();
	public:
		RPN(const std::string& expr);
		RPN(const RPN& rhs);
		RPN&	operator=(const RPN& rhs);
		~RPN();
		void	calculateExpr(void);
		void	calculatePlus(void);
		void	calculateMinus(void);
		void	calculateMultiply(void);
		void	calculateDivide(void);
};

#endif
