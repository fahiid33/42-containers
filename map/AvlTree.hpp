/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:50:31 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/20 00:06:48 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP


template <typename T>
class AvlTree
{
    public : 
    AvlTree() : Node(NULL), tree_size(0){}
    ~AvlTree() {}
    AvlTree(const AvlTree  & src) {*this = src}
    AvlTree & operator=(const AvlTree & lhs);
    Node *rr_rotation(Node *);
    Node *ll_rotation(Node *);
    Node *lr_rotation(Node *);
    Node *rl_rotation(Node *);
    Node* balance(Node *);
    Node* insert(Node *, T );
    void display(Node *, T);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    private : 
    struct Node 
    {
        T data;
        Node* left;
        Node* right;
        int height;
    };

        Node* root;
        size_t tree_size;
};

#endif