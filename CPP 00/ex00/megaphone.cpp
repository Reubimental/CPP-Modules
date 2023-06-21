/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:15:29 by rkabzins          #+#    #+#             */
/*   Updated: 2023/03/07 13:15:30 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	word_index;
	int	letter_index;

	word_index = -1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv[++word_index])
	{
		letter_index = -1;
		while (word_index > 0 && argv[word_index][++letter_index])
			std::cout << (char)std::toupper(argv[word_index][letter_index]);
	}
	std::cout << std::endl;
}