/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:22 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 16:46:57 by sunko            ###   ########.fr       */
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
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		Contact(const Contact &other);
		Contact& operator=(const Contact &other);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nick_name(void);
		std::string	get_phone_number(void);
		std::string	get_darkset_secret(void);
		int			set_first_name(void);
		int			set_last_name(void);
		int			set_nick_name(void);
		int			set_phone_number(void);
		int			set_darkest_secret(void);
};

#endif
