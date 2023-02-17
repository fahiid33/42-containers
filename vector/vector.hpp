/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:35:46 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/17 11:26:46 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "../iterators/Random_access_iterators.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/utilities.hpp"



namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector 
	{
	public:
	//typedefs:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef ft::VectorIterator<value_type>					iterator;
        typedef ft::VectorIterator<const value_type>			const_iterator;
		typedef typename allocator_type::size_type					size_type;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// construct/copy/destroy:
		explicit Vector()
		{
			_size = 0;
			_capacity = 0;
			_buff = NULL;
			_alloc = Allocator();
		}
		explicit Vector(const Vector& v)
		{
			_size = v._size;
			_capacity = v._capacity;
			_buff = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(_buff + i, v._buff[i]);
		}
		explicit Vector(size_t n, const T& value = T(),
		const Allocator& = Allocator())
		{
			if (n > this->max_size())
				throw std::length_error("vector");
			this->_alloc = Allocator();
			this->_buff = this->_alloc.allocate(n);
			for(size_t i = 0; i < n; i++)
				this->_alloc.construct(this->_buff + i, value);
			this->_size = n;
			this->_capacity = n;
		}
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
				,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			_size = 0;
			_capacity = 0;
			_buff = NULL;
			_alloc = alloc;
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
		};
		~Vector()
		{
			this->clear();
			_alloc.deallocate(_buff, _capacity);
		}
		Vector<T,Allocator>& operator=(const Vector<T,Allocator>& x){
			if (this != &x)
			{
				_alloc = x._alloc;
				_capacity = x._capacity;
				_size = x._size;
				if (_buff)
				{
					_alloc.deallocate(_buff, _capacity);
				}
				_buff = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(&_buff[i], x._buff[i]);
				}
			}
    		return *this;
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_t n, const T& u){
			Vector<T, Allocator> temp(n, u);
			this->swap(temp);
		}
		allocator_type get_allocator() const {return Allocator();}
		//iterators:
		iterator begin() {return iterator(&_buff[0]) ;}
		const_iterator begin() const {return const_iterator(&_buff[0]) ;}
		iterator end() {return iterator(&_buff[_size]) ;}
		const_iterator end() const  {return const_iterator(&_buff[_size]) ;}
		reverse_iterator rbegin() {return reverse_iterator(this->end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(this->end());}
		reverse_iterator rend() {return reverse_iterator(this->begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());}
		// 23.2.4.2 capacity:
		size_t size() const {return this->_size;}
		size_t max_size() const{return std::numeric_limits<std::size_t>::max() / sizeof(T);}
		void resize(size_t sz, const T& val = value_type()){
			if (sz <= _size) 
			{
				while (sz < _size) 
				{
					_alloc.destroy(&_buff[_size - 1]);
					_size--;
				}
			} 
			else 
			{
				if (sz > _capacity) 
				{
					reserve(_capacity ? _capacity * 2 : 1);
				}
				for (size_t i = _size; i < sz; i++) {
					_alloc.construct(_buff + i, val);
				}
			}
			_size = sz;
		}
		size_t capacity() const {return this->_capacity;}
		bool empty() const {return (_size == 0);}
		void reserve(size_t n){
			if (n > this->max_size())
				throw std::length_error("vector");
			if (n <= _capacity) 
				return;
			T* newData = _alloc.allocate(n);
			for (size_t i = 0; i < _size; ++i)
				_alloc.construct(newData + i, _buff[i]);
			for (size_t i = 0; i < _size; ++i)
				_alloc.destroy(_buff + i);
			_alloc.deallocate(_buff, _capacity);
			_buff = newData;
			_capacity = n;
		}
		// element access:
		reference operator[](size_t n) {return _buff[n];}
		const_reference operator[](size_t n) const {return _buff[n];}
		const_reference at(size_t n) const{
			if (n >= _size)
				throw std::out_of_range("vector");
    		return (*this)[n];
		}
		reference at(size_t n){
			if (n >= _size)
				throw std::out_of_range("vector");
    		return (*this)[n];
		}
		reference front() {return _buff[0];}
		const_reference front() const {return _buff[0];}
		reference back() {return _buff[_size - 1];}
		const_reference back() const {return _buff[_size - 1];}
		//  modifiers:
		void push_back(const T& val){
			if (_size == _capacity)
				reserve(_capacity ? _capacity * 2 : 1);
			_alloc.construct(_buff + _size, val);
			++_size;
		}
		void pop_back(){
			if (_size > 0)
			{
				_alloc.destroy(&_buff[_size - 1]);
				--_size;
			}
		}
		iterator insert(iterator position, const T& x){
			size_t len = 0;
            if (position.base())
                len = std::distance(begin(),position);
			if (_size >= _capacity)
				reserve(_capacity ? _capacity * 2 : 1);
			for (size_t i = _size ; i > len ; i--)
			{
				_buff[i] = _buff[i - 1];
			}
			_buff[len] = x;
			++_size;
			return &_buff[len];
		}
		void insert(iterator position, size_t n, const T& x){
			size_type index = 0;
			if (position.base())
				index = std::distance(begin(), position);
			if (_size + n > _capacity)
			{
				reserve(n > _size ? n + _size : _capacity * 2);
			}
			for (size_type i = _size; i > index; i--){
				_alloc.construct(&_buff[i + n - 1], _buff[i - 1]);
			}
			for (size_type i = index; i < index + n; i++)
				_alloc.construct(&_buff[i], x);
			_size += n;
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			size_type index = 0;
			if (position.base())
				index = std::distance(begin(), position);
			size_type n = std::distance(first, last);
			if (_size + n > _capacity)
			{
				reserve(n > _size ? n + _size : _capacity * 2);
			}
			for (size_type i = _size; i > index; i--){
				_alloc.construct(&_buff[i + n - 1], _buff[i - 1]);
			}
			for (size_type i = index; i < index + n; i++)
				_alloc.construct(&_buff[i], *first++);
			_size += n;
		}
		iterator erase(iterator first, iterator last){
			size_t n = last - first;
			for (size_t i = first - _buff; i < _size - n; i++)
			{
				_alloc.construct(_buff + i, _buff[i + n]);
				_alloc.destroy(_buff + i + n);
			}
			_size -= n;
			return first;
		}
		iterator erase (iterator position)
		{
			pointer here = &(*position);
			if(position + 1 != (this->_buff + _size))
			{
				this->_alloc.destroy(here);
				for (long i = 0; i < (this->_buff + _size) - here - 1; i++)
				{
					this->_alloc.construct(here + i, *(here + i + 1));
				}		
			}
			pop_back();
			return(iterator(here));
		}
		void swap(Vector<T,Allocator>& rhs){
			if (this != &rhs)
			{
				 size_t tmp_size = _size;
				_size = rhs._size;
				rhs._size = tmp_size;

				size_t tmp_capacity = _capacity;
				_capacity = rhs._capacity;
				rhs._capacity = tmp_capacity;

				pointer tmp_buff = _buff;
				_buff = rhs._buff;
				rhs._buff = tmp_buff;
			}
		}
		void clear(){
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(&_buff[i]);
			_size = 0;
		}
	private:
		Allocator _alloc;
		size_t _size;
		size_t _capacity;
		pointer _buff;
	};
//////////////////// non-member function overloads ////////////////////////////
////////////////--vector comparison operators--////////////////////

template <class T, class Alloc>
bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
	
template <class T, class Alloc>
bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}
template <class T, class Alloc>
bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
		return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
{
	x.swap(y);
}
};


#endif


