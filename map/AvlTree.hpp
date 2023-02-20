/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:50:31 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/20 03:25:45 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <memory>
#include <iostream>

namespace ft
{
    template <typename T, class Alloc>
    class Node
    {
        public : 
        typedef Alloc Allocator_type;
        Allocator_type _alloc;
        T data;
        Node *parent;
        Node* left;
        Node* right;
        int height;
        Node() : parent(NULL), left(NULL), right(NULL), height(0) {}
        ~Node();
        Node(const T & rhs_data) : data(rhs_data), parent(NULL), left(NULL), right(NULL), height(0) {}
        Node(const Node & src)
        {
            _alloc.construct(&this->data, src.data);
            this->left = src.left;
            this->right = src.right;
            this->parent = src.parent;
            this->height = src.height;
        }
        Node &operator=(const Node & rhs)
        {
            if (this != &rhs)
            {
                _alloc.construct(&this->data, rhs.data);
                this->left = rhs.left;
                this->right = rhs.right;
                this->parent = rhs.parent;
                this->height = rhs.height;
            }
            return *this;
        }
        Node *operator=(const Node * rhs)
        {
            if (this != rhs)
            {
                _alloc.construct(&this->data, rhs->data);
                this->left = rhs->left;
                this->right = rhs->right;
                this->parent = rhs->parent;
                this->height = rhs->height;
            }
            return this;
        }
        
        bool operator==(const Node &rhs){return this->data == rhs.data;}
        bool operator!=(const Node & rhs) {return !(*this == rhs);}

    };
    
    class AvlTree
    {
        
    };
    
}


#endif