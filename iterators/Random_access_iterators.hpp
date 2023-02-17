/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterators.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:55:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/17 00:10:50 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATORS_HPP
#define RANDOM_ACCESS_ITERATORS_HPP

#include <cstddef>
#include <iterator>
#include "iterators_traits.hpp"

namespace ft
{
    template <typename T>
    class VectorIterator
    {
        public:
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type	    difference_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type		    value_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer			    pointer;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

            VectorIterator() : _ptr(nullptr) {}
            VectorIterator(pointer ptr) : _ptr(ptr) {}
            VectorIterator(const VectorIterator& other) : _ptr(other.base()) {}

            VectorIterator& operator=(const VectorIterator& other)
            {
                _ptr = other._ptr;
                return *this;
            }

            reference operator*() const { return *_ptr; }
            pointer operator->() const { return _ptr; }
            reference operator[](difference_type n) const { return *(_ptr + n); }

            VectorIterator& operator++()
            {
                ++_ptr;
                return *this;
            }

            VectorIterator operator++(int)
            {
                VectorIterator old(*this);
                ++_ptr;
                return old;
            }

            VectorIterator& operator--()
            {
                --_ptr;
                return *this;
            }

            VectorIterator operator--(int)
            {
                VectorIterator old(*this);
                --_ptr;
                return old;
            }

            VectorIterator operator+(difference_type n) const { return VectorIterator(_ptr + n); }
            VectorIterator operator-(difference_type n) const { return VectorIterator(_ptr - n); }
            friend VectorIterator operator+(difference_type lhs, const VectorIterator& rhs) {return VectorIterator(lhs+rhs._ptr);};
            friend VectorIterator operator-(difference_type lhs, const VectorIterator& rhs) {return VectorIterator(lhs-rhs._ptr);};

            difference_type operator-(const VectorIterator& other) const { return _ptr - other._ptr; }

            VectorIterator& operator+=(difference_type n)
            {
                _ptr += n;
                return *this;
            }

            VectorIterator& operator-=(difference_type n)
            {
                _ptr -= n;
                return *this;
            }

            // bool operator==(const VectorIterator& other) const { return _ptr == other._ptr; }
            // bool operator!=(const VectorIterator& other) const { return _ptr != other._ptr; }

            bool operator==(VectorIterator const& a) const
            {
                if (this->_ptr == a.base())
                    return true;
                else
                    return false;
            }
            bool operator!=(VectorIterator const& a) const 
            {
                if (this->_ptr == a.base())
                    return false;
                else
                    return true;
            }
            
            bool operator<(const VectorIterator& other) const { return _ptr < other._ptr; }
            bool operator>(const VectorIterator& other) const { return _ptr > other._ptr; }
            bool operator<=(const VectorIterator& other) const { return _ptr <= other._ptr; }
            bool operator>=(const VectorIterator& other) const { return _ptr >= other._ptr; }

            pointer base() const { return _ptr; }
            
            operator VectorIterator<const T>() const {
                return VectorIterator<const T>(_ptr);
            }

    private:
        pointer _ptr;
    };
}



#endif