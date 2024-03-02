/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:14:20 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/24 20:10:19 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	//std::cout<< "default cons has called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string datafile)
{
	//std::cout << datafile << " constructor has called" << std::endl;

	std::ifstream bitcoinFile(datafile.c_str());
	if (bitcoinFile.fail())
		throw std::runtime_error("No data file ");
	std::string line;
	std::getline(bitcoinFile, line);
	while (std::getline(bitcoinFile, line))
	{
		std::istringstream s(line);
		std::string date;
		double price;
		std::getline(s, date, ',');
		s >> price;
		this->bitcoinFileData[date] = price; 
	}
	bitcoinFile.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->bitcoinFileData = other.bitcoinFileData;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->bitcoinFileData = other.bitcoinFileData;
}

double BitcoinExchange::exchangeRate(std::string date)
{
	std::map<std::string, double>::iterator it = bitcoinFileData.find(date);
	if (it == bitcoinFileData.end())
	{
		std::map<std::string, double>::iterator low_it = bitcoinFileData.lower_bound(date);
		if (low_it == bitcoinFileData.begin())
			throw std::runtime_error("Bitcoin wasn't created yet");
		else
			--low_it;
		return low_it->second;
	}
	return it->second;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "destrcutor has called" << std::endl;
}
