/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:54:35 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/16 03:30:35 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>
#include <cstddef>

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>

    struct iterator
    {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };
    template <class iterator>
	struct iterator_traits
	{
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;
	};
	template <class T>
	struct iterator_traits<T*>
	{
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									value_type;
			typedef	T*									pointer;
			typedef	T&									reference;
			typedef	std::random_access_iterator_tag		iterator_category;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
			typedef	std::ptrdiff_t						difference_type;
			typedef	 T									value_type;
			typedef	const T*							pointer;
			typedef	const T&							reference;
			typedef	std::random_access_iterator_tag		iterator_category;
	};
}


#endif