/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:22 by sunko             #+#    #+#             */
/*   Updated: 2023/12/25 02:17:04 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mNickName;
		std::string mPhoneNumber;
		std::string mDarkestSecret;
	public:
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickName(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);
		void				SetFirstName(const std::string &str);
		void				SetLastName(const std::string &str);
		void				SetNickName(const std::string &str);
		void				SetPhoneNumber(const std::string &str);
		void				SetDarkestSecret(const std::string &str);
		const std::string	ReadLetter(void);
		const std::string	ReadNumber(void);
		int					IsValidLetter(const std::string &str);
		int					IsValidNumber(const std::string &str);
};



#endif
