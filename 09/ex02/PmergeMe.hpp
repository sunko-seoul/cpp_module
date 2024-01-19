/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:24 by sunko             #+#    #+#             */
/*   Updated: 2024/01/19 15:17:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<std::pair<size_t, size_t> > mVec;
		std::list<std::pair<size_t, size_t> > mList;
		PmergeMe();
	public:
		~PmergeMe();
		PmergeMe(const std::vector<std::pair<size_t, size_t> >& vec, const std::list<std::pair<size_t, size_t> >& list);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe&	operator=(const PmergeMe& rhs);
		std::vector<std::pair<size_t, size_t> > mergeInsertionSort(std::vector<std::pair<size_t, size_t> > v, size_t size);
		std::list<std::pair<size_t, size_t> > mergeInsertionSort(std::list<std::pair<size_t, size_t> > list, size_t size);
		static size_t t[];
};



#endif
