/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:50:54 by fabou-za          #+#    #+#             */
/*   Updated: 2023/05/26 10:05:47 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int>& vec):m_vec(vec), m_sortedVec(vec)
{
	//std::cout << "The constructor has called" << std::endl;
	std::list<int> listSeq(vec.begin(), vec.end());
	m_sortedList = listSeq;
	clock_t start = clock();
	mergeSortAlgo(m_sortedVec);
	clock_t end = clock();
	m_timeUsedByVec = static_cast <double> (end - start) / (double) CLOCKS_PER_SEC * 1000000;
	clock_t start2 = clock();
	mergeSortAlgo(m_sortedList);
	clock_t end2 = clock();
	m_timeUsedByList = static_cast <double> (end2 - start2) / (double) CLOCKS_PER_SEC * 1000000;
}

PmergeMe::PmergeMe(const PmergeMe& ob)
{
	*this = ob;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ob)
{
	if (this != &ob)
	{
		*this = ob;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	//std::cout << "The destructor has called" << std::endl;
}

void PmergeMe::insertionSortVec(std::vector<int>& vect)
{
    int n = vect.size();

    for (int i = 1; i < n; ++i)
    {
        int key = vect[i];
        int j = i - 1;

        while (j >= 0 && vect[j] > key)
        {
            vect[j + 1] = vect[j];
            --j;
        }

        vect[j + 1] = key;
    }
}

void PmergeMe::insertionSortLis(std::list<int>& lis) {

	int p = 0;
	int r = lis.size();
    for (int i = 0; i < r; i++)
	{
		int tempVal = *std::next(lis.begin(), i + 1);
        int j = i + 1;
        while (j > p && *std::next(lis.begin(), j - 1) > tempVal) 
		{
            *std::next(lis.begin(), j) = *std::next(lis.begin(), j - 1);
            j--;
		}
        *std::next(lis.begin(), j) = tempVal;
    }
}

void PmergeMe::mergeSortAlgo(std::vector<int>& vect)
{
	if (vect.size() <= 1)
		return ;

	const int threshold = 13;
    if (vect.size() <= threshold)
    {
        insertionSortVec(vect);
        return;
    }
	int middle = vect.size() / 2;
	std::vector<int> left(vect.begin(), vect.begin() + middle);
	std::vector<int> right(vect.begin() + middle, vect.end());
	mergeSortAlgo(left);
	mergeSortAlgo(right);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < static_cast<int> (left.size()) && j < static_cast<int> (right.size()))
	{
		if (left[i] < right[j])
			vect[k++] = left[i++];
		else
			vect[k++] = right[j++];
	}
	while (i < static_cast<int> (left.size()))
		vect[k++] = left[i++];
	while(j < static_cast<int> (right.size()))
		vect[k++] = right[j++];
}

void PmergeMe::mergeSortAlgo(std::list<int>& list)
{
	if (list.size() <= 1)
		return ;
	const int threshold = 13;
    if (list.size() <= threshold)
    {
        insertionSortLis(list);
        return;
    }
	std::list<int> left, right;
	int middle = list.size() / 2;
	for (std::list<int>::iterator it = list.begin();it != list.end(); ++it)
	{
		if (std::distance(list.begin(), it) < middle)
				left.push_back(*it);
		else
			right.push_back(*it);
	}
	mergeSortAlgo(left);
	mergeSortAlgo(right);
	list.clear();
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			list.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			list.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end())
	{
		list.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end())
	{
		list.push_back(*itRight);
		++itRight;
	}
}
std::vector<int> PmergeMe::getSortedVec(){return m_sortedVec;}
std::list<int> PmergeMe::getSortedList(){return m_sortedList;}
double PmergeMe::getTimeUsedByList() {return m_timeUsedByList;}
double PmergeMe::getTimeUsedByVec() {return m_timeUsedByVec;}
