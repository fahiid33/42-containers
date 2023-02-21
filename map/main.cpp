/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:37:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/22 00:07:02 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
int main()
{
    ft::map <std::string, int>fmap;
    ft::map <std::string, int>fmap1(fmap);
    std::map <std::string, int>map;
    // insert some values:
    map["a"] = 10;
    map["b"] = 30;
    map["c"] = 50;
    map["d"] = 70;
    map["e"] = 90;
    
    std::cout << "========ft=========" <<std::endl;
    std::cout << fmap.empty()<<" | "<< fmap1.empty() << " | "<<fmap.size() << " | " << std::endl;
    ft::map <std::string, int>::iterator it = fmap.begin();
    ft::map <std::string, int>::iterator ite = fmap.end();
    // print content:
    std::cout << "elements in ft_map with iterators :" << std::endl;
    for (it = fmap.begin(); it != fmap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << "========std=========" <<std::endl;
    std::cout << map.empty()<<" | "<< map.empty() << " | "<<map.size() << " | " << std::endl;
    // print content:
    std::cout << "elements in map with iterators :" << std::endl;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    
    // ft::bidirectional_iterator operator++
    
    //operator++ demonstration
    //     8
    //   /   \        //
    //  4    12
    //      /  \     //
    //     10  14

    //Let's create a bidirectional iterator pointing to the root node (8)
    // and call ++ on it. The first step checks if the current node (8) 
    //has a right child. It does, so the current node is set to 
    //12 and then the left most path is followed until the leftmost child
    // (10) is found.The iterator now points to 10. Let's call ++ again.
    // This time, the current node (10)does not have a right child, so 
    //the current node is set to its parent (12)and then we keep moving 
    //up the tree until a node is found that is not the right child of 
    //its parent.This node is 12, which is the next largest element in the
    // container. The iterator now points to 12.
}