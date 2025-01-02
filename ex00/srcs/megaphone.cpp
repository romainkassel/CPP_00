/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:40 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 07:26:07 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int argc, char **argv )
{
	char	c;
	int		i;
	int		j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				c = std::toupper(argv[i][j]);
				std::cout << c;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}     
	return (0);
}