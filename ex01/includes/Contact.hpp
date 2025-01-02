/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:49 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 08:35:00 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <bits/stdc++.h>

class	Contact {


public:

	Contact( void );
	~Contact( void );

	void	fillContact( void );
	std::string	getContactFieldData( std::string field_name );
	void	printContact( void );
	void	printDataFields( void );
	void	printDataField( std::string data_field );
	

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif