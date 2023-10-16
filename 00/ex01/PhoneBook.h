/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:34 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 14:51:52 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.h"

class PhoneBook
{
	private:
		Contact contact[8];
		int		valid[8];
	public:
		PhoneBook(/* args */);
		~PhoneBook();
		PhoneBook(const PhoneBook &other);
		PhoneBook& operator=(const PhoneBook &other);
		void	Add(Contact &new_contact, int cnt);
		void	Display(void);
		void	Search_idx(int idx);
		bool	isValid(int idx);
};

#endif
