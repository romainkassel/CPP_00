/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:49 by rkassel           #+#    #+#             */
/*   Updated: 2024/09/17 15:23:36 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string Contact::getContactFieldData(std::string field_name)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << field_name << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << std::endl << std::endl << "Program exited: CTRL D is forbidden!" << std::endl << std::endl;
			exit(1);
		}
		else if (input.empty())
			std::cout << "A saved contact can’t have empty fields." << std::endl;
	}
	return (input);
}

void	Contact::fillContact()
{
	std::cin.ignore(1, '\n');
	this->_firstName = this->getContactFieldData("First name");
	this->_lastName = this->getContactFieldData("Last name");
	this->_nickname = this->getContactFieldData("Nickname");
	this->_phoneNumber = this->getContactFieldData("Phone number");
	this->_darkestSecret = this->getContactFieldData("Darkest secret");
	return ;
}

void	Contact::printContact()
{
	std::cout << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	return ;
}

void	Contact::printDataFields()
{
	this->printDataField(_firstName);
	this->printDataField(_lastName);
	this->printDataField(_nickname);
}

void	Contact::printDataField(std::string data_field)
{
	int	data_field_len;
	int	i;
	
	data_field_len = data_field.size();
	i = 0;
	if (data_field_len < 10)
	{
		while (i < (10 - data_field_len))
		{
			std::cout << " ";
			i++;
		}
		i = 0;
		while (data_field[i])
		{
			std::cout << data_field[i];
			i++;
		}
	}
	else if (data_field_len > 10)
	{
		while (i < 9)
		{
			std::cout << data_field[i];
			i++;
		}
		std::cout << ".";
	}
	else
	{
		while (data_field[i])
		{
			std::cout << data_field[i];
			i++;
		}
	}
	std::cout << " | ";
	return ;
}

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}