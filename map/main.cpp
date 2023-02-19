/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:37:24 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/19 04:50:21 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

int main()
{
    ft::map <std::string, int>fmap;
    ft::map <std::string, int>fmap1(fmap);
    std::map <std::string, int>map;
    std::map <std::string, int>map1(map);
    
    std::cout << "========ft=========" <<std::endl;
    std::cout << fmap.empty()<<" | "<< fmap1.empty() << " | "<<fmap.size() << " | ";
    std::cout << fmap.max_size()<< std::endl;
    std::cout << "========std=========" <<std::endl;
    std::cout << map.empty()<<" | "<< map1.empty() << " | "<<map.size() << " | ";
    std::cout << map.max_size()<< std::endl;

    // map1(map);
}