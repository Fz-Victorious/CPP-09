/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:46 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/23 15:50:53 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN &operator=(const RPN& ob);
		RPN(const RPN& other);
		void getResult(std::string s);
		~RPN();
};

#endif
