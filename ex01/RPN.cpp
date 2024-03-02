/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:55 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/25 21:56:23 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

RPN::RPN()
{
	//std::cout << "constructor has called " << std::endl;
}

RPN::~RPN()
{
	//std::cout << "destructor has called " << std::endl;
}

RPN& RPN::operator=(const RPN& ob)
{
	if(this != &ob)
		*this = ob;
	return (*this);
}

RPN::RPN(const RPN& ob)
{
	*this = ob;
}

int check(std::string s)
{
	if (s.length() > 1 || (!isdigit(s[0])))
	{
		std::cout << "Error: bad arg!" << std::endl;
		return (1);
	}
	return (0);
}

int isOperator(std::string s)
{
	if (s[0] != '+' && s[0] != '-' && s[0] != '*' && s[0] != '/')
		return (1);
	return (0);
}

void RPN::getResult(std::string arg)
{
	std::stringstream ss(arg);
	std::string substr;
	std::stack<int> myStack;
	int count = 0;
	while (ss >> substr)
	{
		count++;
		if (substr.length() != 1)
		{
			std::cout << "Error: bad arg! " << std::endl;
			return ;
		}
		if (isdigit(substr[0]))
			myStack.push(std::atoi(substr.c_str()));
		else if (!isOperator(substr))
		{
			if (myStack.size() < 2)
			{
				std::cout << "Error: not a reverted polish notation!" << std::endl; 
				return;
			}
			int a = myStack.top();
			myStack.pop();
			int b = myStack.top();
			myStack.pop();
			switch (substr[0])
			{
				case '+':
					myStack.push(b + a);
					break;
				case '-':
					myStack.push(b - a);
					break;
				case '*':
					myStack.push(a * b);
					break;
				case '/':
					if ( a == 0)
					{
						std::cout << "Error: cannot divise by zero " << std::endl;
						return ;
					}
					myStack.push(b / a);
					break;
			}
		}
		else 
		{
			std::cout << "Error " << std::endl;
			return ;
		}
	}
	if (myStack.size() != 1 || count == 1)
	{
		std::cout << "Error: Wrong Expression " << std::endl;
		return ;	
	}
	std::cout << myStack.top() << std::endl;
	myStack.pop();
	return ;
}
