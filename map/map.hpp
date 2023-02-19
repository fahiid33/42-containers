/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:35:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/19 23:36:23 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <utility>
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterators_traits.hpp"
#include "../iterators/Bidirectional_iterators.hpp"
#include <type_traits>

namespace ft 
{
template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
    class map 
    {
        // types
       public :
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type; // to change (ft::)
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef ft::VectorIterator<value_type>					iterator;
        typedef ft::VectorIterator<const value_type>			const_iterator;  // to change (ft::mapiter..)
        typedef typename allocator_type::size_type					size_type; 
        typedef typename iterator_traits<typename map<Key, T, Compare, Allocator>::iterator>::difference_type difference_type;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        // typedef std::reverse_iterator<iterator> reverse_iterator;
        // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        class value_compare : public std::binary_function<value_type,value_type,bool> 
        {
            friend class map;
            protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
            public:
                bool operator()(const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
        };
        // 23.3.1.1 construct/copy/destroy:
       explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : root(nullptr), tree_size(0), _comp(comp), _alloc(alloc){
            std::cout << "map def constr called\n";
        }
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
        const Compare& comp = Compare(), const Allocator& = Allocator());
        map(const map<Key,T,Compare,Allocator>& x)  {
            *this = x ;
            std::cout << "map copy costr called\n";
        }
        ~map(){
            std::cout << "map destr called\n";
        }
        map<Key,T,Compare,Allocator>&
        operator=(const map<Key,T,Compare,Allocator>& x){
            std::cout << "map copy assi called\n";
            if (this != &x)
            {
                this->root = x.root;
                this->tree_size = x.tree_size;
                this->_alloc = x._alloc;
                this->_comp = x._comp;
            }
            return *this;
        }
        // iterators:
        // iterator begin();
        // const_iterator begin() const;
        // iterator end();
        // const_iterator end() const;
        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;
        // reverse_iterator rend();
        // const_reverse_iterator rend() const;
        // capacity:
        bool empty() const {return (tree_size == 0);}
        size_type size() const {return (tree_size);}
        size_type max_size() const{
            return std::min<size_type>(std::allocator_traits<Allocator>::max_size(_alloc),
                                   std::numeric_limits<difference_type>::max());
        }
        // element access:
        T& operator[](const key_type& x);
        // modifiers:
        // std::pair<iterator, bool> insert(const value_type& x);// to change (ft::)
        // iterator insert(iterator position, const value_type& x);
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
        // void erase(iterator position);
        size_type erase(const key_type& x);
        // void erase(iterator first, iterator last);
        void swap(map<Key,T,Compare,Allocator>&);
        void clear();
        // observers:
        key_compare key_comp() const;
        value_compare value_comp() const;
        // map operations:
        // iterator find(const key_type& x);
        // const_iterator find(const key_type& x) const;
        size_type count(const key_type& x) const;
        // iterator lower_bound(const key_type& x);
        // const_iterator lower_bound(const key_type& x) const;
        // iterator upper_bound(const key_type& x);
        // const_iterator upper_bound(const key_type& x) const;
        // pair<iterator,iterator>
        // equal_range(const key_type& x);
        // pair<const_iterator,const_iterator>
        // equal_range(const key_type& x) const;
        private:
        struct Node 
        {
            value_type data;
            Node* left;
            Node* right;
            int height;

            Node(const value_type& d) : data(d), left(nullptr), right(nullptr), height(1) {}
        };

        Node* root;
        size_type tree_size;
        key_compare _comp;
        Allocator _alloc;
    };
    ///========non member functions=======/////
    ////====map operators overloads=====//////
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator< (const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator> (const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key,T,Compare,Allocator>& x,
    const map<Key,T,Compare,Allocator>& y);
    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x,
    map<Key,T,Compare,Allocator>& y);
};


#endif