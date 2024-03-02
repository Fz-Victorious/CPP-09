/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:46:10 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/26 10:06:28 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string intToString(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

int main(int ac, char **argv)
{
	if (ac < 2)
	{
		std::cout << "Invalid args!" << std::endl;
		return (1);
	}
	std::vector<int> vec;
	std::string substr;
	std::string toStr;
	std::istringstream ss;
	int count_args = 0;
	for (int i = 1; i < ac; i++)
	{
		ss.clear();
		ss.str(argv[i]);
		if (ss.str() == "")
		{
			std::cout << "Error: an empty string" << std::endl;
			return (1);
		}
		if (ss.str().find_first_not_of(' ') == std::string::npos) {
        	std::cout << "Error: argument contains only spaces" << std::endl;
        	return (1);
		}
		while (ss >> substr)
		{
			int value = std::atoi(substr.c_str());
			toStr = intToString(value);
			if (toStr.length() != substr.length() || !isdigit(substr[0]) || value <= 0 || value > 2147483647)
			{
				std::cout << "There is an error in here " << substr << std::endl;
				return (1);
			}
			count_args++;
			vec.push_back(value);
		}
	}
	PmergeMe mergeAlgo(vec);
	std::vector<int> v = mergeAlgo.getSortedVec();
	std::cout << "Before:";
	for (int i = 0; i < static_cast<int> (vec.size()); i++)
	{
		std::cout << " " << vec[i];
	}
	std::cout << "\nAfter: " ;
	for (int a = 0; a < static_cast<int> (v.size()); a++)
	{
		std::cout << " " << v[a];
	}
	double listTime = mergeAlgo.getTimeUsedByList();
	std::cout << "\nTime to process a range of " << count_args << " elements with std::list : " << listTime << " us" << std::endl;
	double vectTime = mergeAlgo.getTimeUsedByVec();
	std::cout << "Time to process a range of " << count_args << " elements with std::vector : " << vectTime << " us" <<std::endl;
	return (0);
}
