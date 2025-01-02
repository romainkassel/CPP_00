/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:49 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 08:34:56 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {


public:

	PhoneBook( void );
	~PhoneBook( void );
	
	void	addContact( void );
	void	printRepo( void );


private:

	Contact	_instance[8];
	
	int		_index;
	int		_maxContactReached;
	
	void	_getContactIndex( void );
	void	_printBorderLine( void );

};

#endif