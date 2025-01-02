/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAPB.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:40 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 08:42:59 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main( void )
{
	std::string	buff;
    PhoneBook	repository;

	while (1)
	{
		std::cout << std::endl;
		std::cout << "Which command would you like to run?" << std::endl;
		std::cout << "You have the choice between ADD, SEARCH and EXIT." << std::endl;
		std::cout << std::endl;
		std::cout << "Your command: ";
		std::cin >> buff;
		std::cout << std::endl;
		if (buff.compare("ADD") == 0)
			repository.addContact();
		else if (buff.compare("SEARCH") == 0)
		{
			repository.printRepo();
			buff.clear();
		}
		else if (buff.compare("EXIT") == 0 || std::cin.eof())
		{
			if (buff.find('\0') && buff.find("EXIT") == (size_t)-1)
				std::cerr << std::endl << "Program exited: CTRL D is forbidden!" << std::endl << std::endl;
			return (0);
		}
	}
	return (0);
}