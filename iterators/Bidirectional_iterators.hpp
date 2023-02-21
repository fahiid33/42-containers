/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_iterators.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:36:25 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/22 00:10:15 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATORS_HPP
#define BIDIRECTIONAL_ITERATORS_HPP


#include "../map/AvlTree.hpp"
#include <iterator>
namespace ft
{
    template <typename Value_type, typename Node_T>
    class Bidirectional_iterator
    {
        public :
        // types
        typedef Value_type value_type; // type of the elements
        typedef std::ptrdiff_t difference_type; // type to represent the difference between two iterators
        typedef std::bidirectional_iterator_tag iterator_category; // iterator category
        typedef Value_type* pointer; // type of a pointer to an element
        typedef Value_type& reference; // type of a reference to an element
        // Constructors
        Bidirectional_iterator() : _node(NULL), _root(NULL) {}
        Bidirectional_iterator(Node_T node, Node_T root) : _node(node), _root(root) {}
        Bidirectional_iterator(const Bidirectional_iterator& other) : _node(other.getNode()), _root(other.getRoot()) {}
        // constructor for const_iterator and non const_iterator
        template <typename Other_Value_type, typename Other_Node_T>
        Bidirectional_iterator(const Bidirectional_iterator<Other_Value_type, Other_Node_T>& other) : _node(other.getNode()), _root(other.getRoot()) {}
        ~Bidirectional_iterator() {}
        Bidirectional_iterator& operator=(const Bidirectional_iterator& other)
        {
            _node = other.getNode();
            _root = other.getRoot();
            return *this;
        }
        // getters
        Node_T getNode() const {return _node;}
        Node_T getRoot() const {return _root;}
        
        // operators
        reference operator*() const {return _node->data;}
        pointer operator->() const {return &(_node->data);}
        Bidirectional_iterator& operator++()                       
        {
            if (_node->right != NULL) // check if the current node (8) has a right child                            //     8
            {                                                                                                       //   /   \        //
                _node = _node->right; // the current node is set to 12                                             //   4    12
                while (_node->left != NULL)//the left most path is followed until the leftmost child (10) is found  //      /  \     //
                    _node = _node->left;                                                                            //     10  14
            }
            else                        //Let's call ++ again This time, the current node (10)does not have a right child
            {
                Node_T tmp = _node;
                _node = _node->parent; // the current node is set to its parent (12)
                while (_node != NULL && tmp == _node->right) // keep moving up the tree until a node is found that is not the right child of its parent
                {
                    tmp = _node;
                    _node = _node->parent;
                }
            }
            return *this;
        }
        Bidirectional_iterator& operator++(int)
        {
            Bidirectional_iterator tmp(*this);
            operator++();
            return tmp;
        }
        Bidirectional_iterator& operator--()
        {
            if (_node->left != NULL)
            {
                _node = _node->left;
                while (_node->right != NULL)
                    _node = _node->right;
            }
            else
            {
                Node_T* tmp = _node;
                _node = _node->parent;
                while (_node != NULL && tmp == _node->left)
                {
                    tmp = _node;
                    _node = _node->parent;
                }
            }
            return *this;
        }
        
        Bidirectional_iterator& operator--(int)
        {
            Bidirectional_iterator tmp(*this);
            operator--();
            return tmp;
        }

        bool operator==(const Bidirectional_iterator& other) const
        {
            return (_node == other.getNode() && _root == other.getRoot());
        }

        bool operator!=(const Bidirectional_iterator& other) const
        {
            return (_node != other.getNode() || _root != other.getRoot());
        }   
                                                
        private :
        Node_T _node;
        Node_T _root;
    };
    
};

#endif