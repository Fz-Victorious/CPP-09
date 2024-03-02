/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:42:11 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/25 17:58:52 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(std::vector<int>& vec);
		PmergeMe(const PmergeMe& ob);
		PmergeMe& operator=(const PmergeMe& ob);
		void mergeSortAlgo(std::vector<int>& vec);
		void mergeSortAlgo(std::list<int>& list);
	   	void insertionSortVec(std::vector<int>& vect);
		void insertionSortLis(std::list<int>& list);
		std::vector<int> getSortedVec();
		std::list<int> getSortedList();
		double getTimeUsedByVec();
		double getTimeUsedByList();
		~PmergeMe();
	private:
		std::vector<int> m_vec;
		std::vector<int> m_sortedVec;
		std::list<int> m_sortedList;
		double m_timeUsedByList;
		double m_timeUsedByVec;
};
#endif
