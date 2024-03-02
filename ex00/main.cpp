/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:14:41 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/24 20:01:36 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int checkDate(std::string date)
{
	if(date.length() != 11 || date[4] != '-' || date[7]!= '-' || date[10] != ' ')
		return (1);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			i++;
		if (date[i] < '0' || date[i] > '9')
			return (1);
	}
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	int month = std::stoi(monthStr.c_str());
	int day = std::stoi(dayStr.c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (1);
	return (0);
}

int countCharsDouble(double value)
{
	std::ostringstream oss;
	oss << value;
	std::string valueStr = oss.str();
	return valueStr.length();
}

int checkChars(std::string str)
{
	std::size_t found = str.find('.');
	for (int i = 0; i < static_cast<int> (str.length()); i++)
	{
		if (i == (int) found)
			continue;
		else if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}

int checkValue(std::string valueStr, double value)
{
	int i;

	i = 1;
	if (valueStr.empty())
	{
		std::cout << "Error: there is no value." << std::endl;
		return (1);
	}
	int counter = count(valueStr.begin(), valueStr.end(), '.');
	if (valueStr[1] == '-')
		i++;
	std::string s = valueStr.substr(i, valueStr.length() - i);
	if (valueStr[0] != ' ' || (counter != 0 && counter != 1) || checkChars(s))
	{
		std::cout << "Error: bad value " << std::endl;
		return (1);
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	else if (value > 1000)
	{
		std::cout << "Error: Too large number." << std::endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cerr << "Error: Bad arguments !" << std::endl;
		return (1);
	}
	try{
		BitcoinExchange exchange("data.csv");
		std::ifstream inputFile(argv[1]);
		if (inputFile.fail())
		{
			std::cerr << "Error: Cannot open the input file " << std::endl;
			return (1);
		}
		std::string line;
		std::getline(inputFile, line);
		if (line.empty() || line != "date | value")
		{
			std::cout << "Wrong format!" << std::endl;
			return (1);
		}
		while (std::getline(inputFile, line))
		{
			std::string date;
			std::string valueStr;
			std::istringstream ob(line);
			std::getline(ob, date, '|');
			std::getline(ob, valueStr);
			if (valueStr.empty() && date.empty())
			{
				std::cout << "empty line" << std::endl;
				continue;
			}
			if (checkDate(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			double value = atof(valueStr.c_str());
			if (checkValue(valueStr, value))
				continue;
			{
				try{
					double price = exchange.exchangeRate(date);
					double result = price * value;
					std::cout << date << " => " << value << " = " << result << std::endl;
				}
				catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
