/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:50:31 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/20 12:27:56 by fstitou          ###   ########.fr       */
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
    template < class T, typename  Compare = std::less<typename T::first_type>,
     class Alloc = std::allocator<T> >  // works with any type that has a nested 
                                        // first_type comparable with Compare type
    class AvlTree
    {
        public :
        typedef Node<T, Alloc> Node_T;
        typedef Alloc Allocator_type;
        typedef typename T::first_type key_type; // type of the key
        typedef typename T::second_type val_type; // type of the value
        typedef typename Alloc::template rebind<Node_T>::other Node_allocator;
        Node_T *root;

        private :
        Node_allocator _Alloc_node;
        Compare _comp;
        size_t _size;
        Allocator_type _alloc_Val;

        public :
        AvlTree() : root(NULL), _size(0) {}
        AvlTree(const AvlTree & src)
        {
            this->root = src.root;
            this->_size = src._size;
            *this = src;
        }
        ~AvlTree() {};
        
        AvlTree &operator=(const AvlTree & rhs)
        {
            if (this != &rhs)
            {
                this->root = rhs.root;
                this->_size = rhs._size;
                this->_alloc_Val = rhs._alloc_Val;
                this->_Alloc_node = rhs._Alloc_node;
            }
            return *this;
        }
        Node_T *findmin() const {return findmin(root);}
        Node_T *findmin(Node_T *node) const
        {
            if (node)
            {
                while (node->left != NULL)
                    node = node->left;
            }
            return node;
        }
        Node_T *findmax() const {return findmax(root);}
        Node_T *findmax(Node_T *node) const
        {
            if (node)
            {
                while (node->right != NULL)
                    node = node->right;
            }
            return node;
        }
        
        
    };
    
}


#endif