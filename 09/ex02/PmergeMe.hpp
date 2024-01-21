/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:24 by sunko             #+#    #+#             */
/*   Updated: 2024/01/21 15:14:14 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int> mVec;
		std::deque<int> mQue;
		PmergeMe();
	public:
		~PmergeMe();
		PmergeMe(const std::vector<int>& vec, const std::deque<int>& list);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe&	operator=(const PmergeMe& rhs);
		int					findMappingB(std::vector<std::pair<int, int> >& storeVec, int val);
		int					findMappingB(std::deque<std::pair<int, int> >& storeVec, int val);
		std::vector<int>	mergeInsertionSort(std::vector<int> v, size_t size);
		std::deque<int>		mergeInsertionSort(std::deque<int> deque, size_t size);
		void				sortVector(void);
		void				sortDeque(void);
		const static size_t Diff[];
		const static size_t Jacob[];
};



#endif
