/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:35:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/08 00:11:25 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <iostream>
#include <memory>
#include <algorithm>



namespace ft 
{
template <class Key, class T, class Compare = std::less<Key> >
    class map 
    {
        public:
        typedef Key                                      key_type;
        typedef T                                       mapped_type;
        typedef std::pair<const Key, T>                 value_type;
        typedef Compare                                 key_compare;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef value_type*                             pointer;
        typedef const value_type*                       const_pointer;
        class iterator;
        class const_iterator;

        map() : root(nullptr), tree_size(0), comp(0) {}
        explicit map(const Compare& comp);

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        bool empty() const;
        size_t size() const;
        size_t max_size() const;

        mapped_type& operator[](const key_type& key);

        std::pair<iterator, bool> insert(const value_type& val);
        iterator insert(iterator hint, const value_type& val);
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        void erase(iterator position);
        size_t erase(const key_type& key);
        void erase(iterator first, iterator last);
        void clear();

        iterator find(const key_type& key);
        const_iterator find(const key_type& key) const;

        size_t count(const key_type& key) const;

        iterator lower_bound(const key_type& key);
        const_iterator lower_bound(const key_type& key) const;
        iterator upper_bound(const key_type& key);
        const_iterator upper_bound(const key_type& key) const;

        std::pair<iterator, iterator> equal_range(const key_type& key);
        std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;

        key_compare key_comp() const;
        value_compare value_comp() const;
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
        size_t tree_size;
        key_compare comp;
    };
}


#endif