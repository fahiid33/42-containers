/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:35:46 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/07 23:04:14 by fstitou          ###   ########.fr       */
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
			this->_alloc = Allocator();
			this->_buff = this->_alloc.allocate(n);
			for(size_t i = 0; i < n; i++)
				this->_alloc.construct(this->_buff + i, value);
			this->_size = n;
			this->_capacity = n;
		}
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
		const Allocator& = Allocator());
		// Vector(const Vector<T,Allocator>& x);
		~Vector()
		{
			std::cout << "veddd\n";
		}
		Vector<T,Allocator>& operator=(const Vector<T,Allocator>& x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_t n, const T& u);
		allocator_type get_allocator() const;
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
		size_t size() const;
		size_t max_size() const;
		void resize(size_t sz, T c = T());
		size_t capacity() const;
		bool empty() const;
		void reserve(size_t n);
		// element access:
		reference operator[](size_t n);
		const_reference operator[](size_t n) const;
		const_reference at(size_t n) const;
		reference at(size_t n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		//  modifiers:
		void push_back(const T& x);
		void pop_back();
		// iterator insert(iterator position, const T& x);
		// void insert(iterator position, size_t n, const T& x);
		// template <class InputIterator>
		// void insert(iterator position,
		// InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		void swap(Vector<T,Allocator>&);
		void clear();
	private:
		Allocator _alloc;
		size_t _size;
		size_t _capacity;
		pointer _buff;
	};
};

#endif