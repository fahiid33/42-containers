/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:37:12 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/17 11:24:09 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{
    template <class iterator>
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
            template <class Iter>
            reverse_iterator& operator= (const reverse_iterator<Iter>& rev_it)
            {
                _curr = rev_it.base();
                return (*this); 
            }
            iterator_type 	base () const {return _curr;}
            reference 	operator * () const {return *(_curr - 1);}
            pointer 	operator-> () const  {return &(operator*());}
            reverse_iterator & 	operator++ () {
                _curr--;
                return *this;
            }
            reverse_iterator 	operator++ (int) {
                reverse_iterator tmp = *this;
                _curr--;
                return tmp;
            }
            reverse_iterator & 	operator-- () {
                _curr++;
                return *this;
            }
            reverse_iterator 	operator-- (int) {
                reverse_iterator tmp = *this;
                _curr++;
                return tmp;
            }
            reverse_iterator 	operator+ (difference_type n) const {
                reverse_iterator tmp = *this;
                tmp._curr -= n;
                return tmp;
            }
            reverse_iterator & 	operator+= (difference_type n) {
                _curr -= n;
                return *this;
            }
            reverse_iterator 	operator- (difference_type n) const {
                reverse_iterator tmp = *this;
                tmp._curr += n;
                return tmp;
            }
            reverse_iterator & 	operator-= (difference_type n) {
                _curr += n;
                return *this;
            }
            reference 	operator[] (difference_type n) const {
                return *(*this + n);
            }
        private:
            iterator_type 	_curr;
    };
        template<typename Iter>  	bool 	operator== (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return x.base() == y.base();
        }
        template<typename Iter>  	bool 	operator!= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y) {
            return x.base() != y.base();
        }
        template<typename Iter>  	bool 	operator< (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return x.base() > y.base();
        }
        template<typename Iter>  	bool 	operator<= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return x.base() >= y.base();
        }
        template<typename Iter>  	bool 	operator> (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return x.base() < y.base();
        }
        template<typename Iter>  	bool 	operator>= (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return x.base() <= y.base();
        }
        template<typename Iter>  	reverse_iterator<Iter> 	operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &x){
            return x + n;
        }
        template<typename Iter>  	typename reverse_iterator<Iter>::difference_type 	operator- (const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){
            return y.base() - x.base();
        }
};



#endif