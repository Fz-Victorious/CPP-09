/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:15:43 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/19 19:52:29 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **arg)
{
	if (ac != 2)
	{
		std::cout << "Error: Bad args! " << std::endl;
		return (1);
	}
	RPN reversePolishN;
	reversePolishN.getResult(arg[1]);
}
