/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:37:12 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/17 05:47:46 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include <cstddef>
#include "iterators_traits.hpp"

namespace ft
{
    template <typename T>
    class reverse_iterator
    {
        public:
            typedef iterator                                                    iterator_type;
            typedef	typename iterator_traits<iterator>::difference_type    difference_type;
            typedef typename iterator_traits<iterator>::value_type         value_type;
            typedef typename iterator_traits<iterator>::pointer            pointer;
            typedef typename iterator_traits<iterator>::reference          reference;
            typedef	typename iterator_traits<iterator>::iterator_category	iterator_category;
            
            reverse_iterator () : _curr(nullptr) {}
            reverse_iterator (iterator_type x) : _curr(x) {} 
            reverse_iterator (const reverse_iterator &x) : _curr(x._curr) {}
            template<typename Iter>  	reverse_iterator (const reverse_iterator< Iter > &x) {*this = x;}
            iterator_type 	base () const {return _curr;}
            reference 	operator * () const 
            pointer 	operator-> () const 
            reverse_iterator & 	operator++ () 
            reverse_iterator 	operator++ (int) 
            reverse_iterator & 	operator-- () 
            reverse_iterator 	operator-- (int) 
            reverse_iterator 	operator+ (difference_type n) const 
            reverse_iterator & 	operator+= (difference_type n) 
            reverse_iterator 	operator- (difference_type n) const 
            reverse_iterator & 	operator-= (difference_type n) 
            reference 	operator[] (difference_type n) const 
            template<typename Iter>  	bool 	operator== (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	bool 	operator!= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	bool 	operator< (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	bool 	operator<= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	bool 	operator> (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	bool 	operator>= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
            template<typename Iter>  	reverse_iterator<Iter> 	operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &x)
            template<typename Iter>  	typename reverse_iterator<Iter>::difference_type 	operator- (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
        private:
            iterator_type 	_curr;
    }
}

#endif