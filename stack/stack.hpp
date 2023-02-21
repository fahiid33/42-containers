/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:34:56 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/21 23:51:56 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include "../vector/vector.hpp"


namespace ft
{
    template <class T, class Container = ft::Vector<T> >
    class stack 
    {
        public:
        typedef T													value_type;// first template parameter T
        typedef size_t                                              size_type	;
        typedef Container                                           container_type; // underlying container(ft::Vector)
    protected:
        container_type c;
        public:
        explicit stack(const container_type& cntr = container_type()) : c(cntr){}
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type& top() { return c.back(); }
        const value_type& top() const { return c.back(); }
        void push(const value_type& x) { c.push_back(x); }
        void pop() { c.pop_back(); }
    };
    //// non member overloads////
    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y) { return x.c == y.c; }
    
    template <class T, class Container>
    bool operator<(const stack<T, Container>& x, const stack<T, Container>& y) { return x.c < y.c; }
    
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y) { return !(x == y); }
    
    template <class T, class Container>
    bool operator>(const stack<T, Container>& x, const stack<T, Container>& y) { return y < x; }
    
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y) { return !(x < y); }
    
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y) { return !(y < x); }
}



#endif