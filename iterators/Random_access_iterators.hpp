/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterators.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:55:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/16 00:52:57 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATORS_HPP
#define RANDOM_ACCESS_ITERATORS_HPP

#include <cstddef>

namespace ft
{
    template <typename T>
    class VectorIterator
    {
        public:
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;

            VectorIterator() : _ptr(nullptr) {}
            VectorIterator(pointer ptr) : _ptr(ptr) {}
            VectorIterator(const VectorIterator& other) : _ptr(other._ptr) {}

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

            bool operator==(const VectorIterator& other) const { return _ptr == other._ptr; }
            bool operator!=(const VectorIterator& other) const { return _ptr != other._ptr; }
            bool operator<(const VectorIterator& other) const { return _ptr < other._ptr; }
            bool operator>(const VectorIterator& other) const { return _ptr > other._ptr; }
            bool operator<=(const VectorIterator& other) const { return _ptr <= other._ptr; }
            bool operator>=(const VectorIterator& other) const { return _ptr >= other._ptr; }

            pointer base() const { return _ptr; }

    private:
        pointer _ptr;
    };
}



#endif