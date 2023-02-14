/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:38:26 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/14 03:42:20 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main()
{
    ft::Vector <int> v;
    const ft::Vector <int> cv(static_cast<size_t>(4), 10);
    const std::vector <int> c_sv((4), 10);
    std::vector <int> sv;
    ft::Vector <int> v2(static_cast<size_t>(4), 16); 
    std::vector <int> sv2((4), 16);    
    ft::Vector <int> v3(v2);
    std::vector <int> sv3(sv2);
    

    std::cout << "-----capacity methods-----" << std::endl;
    std::cout << "my "<< v2.size() << " | "<<v3.size()<< " | "
    << " | " <<v3.capacity()<< " | "<< v3.empty()<<std::endl;
    std::cout << "sys "<< sv2.size() << " | " << sv3.size()<< " | "
    << " | " <<sv3.capacity()<< " | "<< sv3.empty()<<std::endl;
    std::cout << "-----reserve method----" << std::endl;
    v3.reserve(4);
    std::cout << "my "<<v3.capacity() << " | " << v3.size() << std::endl;
    sv3.reserve(4);
    std::cout << "sys "<<sv3.capacity() << " | " << sv3.size() << std::endl;
    std::cout << "-----modifiers----" << std::endl;
    v.push_back(5);
    v.push_back(12);
    v.push_back(22);
    v.push_back(2);
    v.push_back(8);

    sv.push_back(5);
    sv.push_back(12);
    sv.push_back(22);
    sv.push_back(2);
    sv.push_back(8);

    std::cout << "my "<<v.capacity() << " | " << v.size() << std::endl;
    std::cout << "sys "<<sv.capacity() << " | " << sv.size() << std::endl;
    std::cout << "-----element access----" << std::endl;
    for (size_t i = 0; i < cv.size(); i++)
        std::cout << "my : "<< cv[i] << std::endl;
    for (size_t i = 0; i < sv3.size(); i++)
        std::cout << "sys : "<< c_sv[i] << std::endl;
    std::cout << "v3[8] :" << cv[10] << std::endl;
    std::cout << "sv3[8] :" << c_sv[10] << std::endl;

    // v3.push_back(12);

}