/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:49 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 08:45:02 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::_getContactIndex()
{
	std::string	index;
	int			max_index;
	int			converted_index;

	if (this->_maxContactReached == 1)
		max_index = 7;
	else
		max_index = this->_index - 1;
	while (index.size() > 1 || index[0] < '0' || index[0] > ((char)max_index + 48))
	{
		std::cout << std::endl;
		std::cout << "Enter an index between 0 and " << max_index << ": ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cerr << std::endl << std::endl << "Program exited: CTRL D is forbidden!" << std::endl << std::endl;
			exit(1);
		}
		else if (index.size() > 1 || index[0] < '0' || index[0] > ((char)max_index + 48))
			std::cout << std::endl << "Wrong index." << std::endl;
	}
	converted_index = (int)index[0] - 48;

	this->_instance[converted_index].printContact();
	return ;
}

void	PhoneBook::addContact()
{
	Contact		instance;
	
	instance.fillContact();
	this->_instance[this->_index] = instance;
	this->_index++;
	if (this->_index == 8)
	{
		this->_index = 0;
		this->_maxContactReached = 1;
	}
	std::cout << std::endl;
	std::cout << "The contact has been successfully added to the phonebook." << std::endl;
	std::cout << "You can run SEARCH to see it." << std::endl;
	return ;
}

void	PhoneBook::_printBorderLine()
{
	int	i;
	
	i = 0;
	while (i < 53)
	{
		std::cout << "-";
		i++;
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::printRepo()
{
	int	i;

	this->_printBorderLine();
	std::cout << "| " << "     Index" << " | " << "First name" << " | " << " Last name" << " | " << "  Nickname" << " |" << std::endl;
	this->_printBorderLine();
	i = 0;
	while ((this->_maxContactReached == 0 && i < this->_index) || (this->_maxContactReached == 1 && i < 8))
	{
		std::cout << "| ";
		std::cout << "         " << i;
		std::cout << " | ";
		this->_instance[i].printDataFields();
		std::cout << std::endl;
		i++;
	}
	if (this->_index == 0 && this->_maxContactReached == 0)
	{
		std::cout << "The phonebook is empty, no contact has been saved yet." << std::endl;
		std::cout << "Run ADD to add the first contact." << std::endl;
	}
	this->_printBorderLine();
	if (this->_index > 0 || (this->_index == 0 && this->_maxContactReached == 1))
		this->_getContactIndex();
	return ;
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_maxContactReached = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}