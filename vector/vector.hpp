/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:35:46 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/15 02:07:46 by fstitou          ###   ########.fr       */
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




namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector 
	{
	public:
	//typedefs:
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		// typedef implementation defined iterator;
		// typedef implementation defined const_iterator;
		// typedef implementation defined size_t;
		// typedef implementation defined difference_type
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		// construct/copy/destroy:
		explicit Vector()
		{
			_size = 0;
			_capacity = 0;
			_buff = NULL;
			_alloc = Allocator();
			// std::cout << "Vector constr called"<< std::endl;
		}
		explicit Vector(const Vector& v)
		{
			_size = v._size;
			_capacity = v._capacity;
			_buff = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(_buff + i, v._buff[i]);
			// std::cout << "Vector copy constrrrr called"<< std::endl;
		}
		explicit Vector(size_t n, const T& value = T(),
		const Allocator& = Allocator())
		{
			this->_alloc = Allocator();
			this->_buff = this->_alloc.allocate(n);
			for(size_t i = 0; i < n; i++)
				this->_alloc.construct(this->_buff + i, value);
			this->_size = n;
			this->_capacity = n;
			// std::cout << "Vector constr size called"<< std::endl;
		}
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
		const Allocator& = Allocator());
		// Vector(const Vector<T,Allocator>& x);
		~Vector()
		{
			for (size_t i = _size; i > 0; --i)
			{
				_alloc.destroy(&_buff[i - 1]);
			}
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
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		// 23.2.4.2 capacity:
		size_t size() const {return this->_size;}
		size_t max_size() const{return std::numeric_limits<std::size_t>::max() / sizeof(T);}
		void resize(size_t sz, T c = T());
		size_t capacity() const {return this->_capacity;}
		bool empty() const {return (_size == 0);}
		void reserve(size_t n){
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
		reference operator[](size_t n)
		{
			// if (n >= _size)
			// 	throw std::out_of_range("Index is out of range");
			return _buff[n];
		}
		const_reference operator[](size_t n) const
		{
			// if (n >= _size)
			// 	throw std::out_of_range("Index is out of range");
			return _buff[n];
		}
		const_reference at(size_t n) const{
			if (n >= _size)
				throw std::out_of_range("Vector::at() - index out of range");
    		return (*this)[n];
		}
		reference at(size_t n){
			if (n >= _size)
				throw std::out_of_range("Vector::at() - index out of range");
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
		// iterator insert(iterator position, const T& x);
		// void insert(iterator position, size_t n, const T& x);
		// template <class InputIterator>
		// void insert(iterator position,
		// InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
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
};

#endif