/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:34 by sunko             #+#    #+#             */
/*   Updated: 2023/12/25 02:26:51 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.h"

class PhoneBook
{
	private:
		Contact 		mContacts[8];
		int				mValid[8];
	public:
		PhoneBook();
		void			Add(const Contact &new_contact, const int cnt);
		void			Display(PhoneBook &phoneBook);
		void			SearchIdx(PhoneBook &phoneBook, const int idx);
		bool			IsValid(const int idx);
		void			SetValid(const int idx, const int value);
		void			SetContact(const int idx, const Contact &contact);
		int				GetValid(const int idx) const;
		const Contact	GetContact(const int idx) const;
		void			DisplayInfoRow(void) const;
		void			DisplayContactRow(Contact contact, const int idx) const;
};

#endif
