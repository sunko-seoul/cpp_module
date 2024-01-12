/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:02:03 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 11:25:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<unsigned int> mVec;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& rhs);
		Span&	operator=(const Span& rhs);
		~Span();
		void			addNumber(unsigned int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif
