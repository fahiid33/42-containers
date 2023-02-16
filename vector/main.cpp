/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:38:26 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/16 03:58:43 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../iterators/Random_access_iterators.hpp"
#include <vector>

int main()
{
    ft::Vector<int>::iterator it;
    ft::Vector<int>v;
    v.push_back(5);
    v.push_back(12);
    v.push_back(13);
    v.push_back(1);
    it = v.begin();
    it++;
    it--;
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    
//     ft::Vector <int> ve;
//   ft::Vector <int> v;
//     std::vector <int> sve;
//     const ft::Vector <int> cv(static_cast<size_t>(4), 10);
//     const std::vector <int> c_sv((4), 10);
//     std::vector <int> sv;
//     ft::Vector <int> v2(static_cast<size_t>(4), 16); 
//     std::vector <int> sv2((4), 16);    
//     ft::Vector <int> v3;
//     std::vector <int> sv3;
    

//     std::cout << "-----capacity methods-----" << std::endl;
//     std::cout << "my "<< v2.size() << " | "<<v3.size()<< " | "
//     << " | " <<v3.capacity()<< " | "<< v3.empty()<<std::endl;
//     std::cout << "sys "<< sv2.size() << " | " << sv3.size()<< " | "
//     << " | " <<sv3.capacity()<< " | "<< sv3.empty()<<std::endl;
//     std::cout << "-----reserve method----" << std::endl;
//     v3.reserve(4);
//     std::cout << "my "<<v3.capacity() << " | " << v3.size() << std::endl;
//     sv3.reserve(4);
//     std::cout << "sys "<<sv3.capacity() << " | " << sv3.size() << std::endl;
//     std::cout << "-----modifiers----" << std::endl;
//     v.push_back(5);
//     v.push_back(12);
//     v.push_back(22);
//     v.push_back(2);
//     v.push_back(8);

//     sv.push_back(5);
//     sv.push_back(12);
//     sv.push_back(22);
//     sv.push_back(2);
//     sv.push_back(8);

    // std::cout << "my "<<v.capacity() << " | " << v.size() << std::endl;
    // std::cout << "sys "<<sv.capacity() << " | " << sv.size() << std::endl;
    // std::cout << "-----element access----" << std::endl;
    // for (size_t i = 0; i < cv.size(); i++)
    //     std::cout << "const my : "<< cv[i] << std::endl;
    // for (size_t i = 0; i < c_sv.size(); i++)
    //     std::cout << "const sys : "<< c_sv[i] << std::endl;
    // for (size_t i = 0; i < v.size(); i++)
    //     std::cout << "my : "<< v[i] << std::endl;
    // for (size_t i = 0; i < sv.size(); i++)
    //     std::cout << "sys : "<< sv[i] << std::endl;
    // std::cout << "const v[10] :" << cv[10] << std::endl;
    // std::cout << "const sys v[10] :" << c_sv[10] << std::endl;
    //  std::cout << "v[10] :" << v[10] << std::endl;
    // std::cout << "sys_v[10] :" << sv[10] << std::endl;
    // try
    // {
    //     sv.at(2) = 33;
    //     v.at(2) = 33;
    //     std::cout << "sys at(2) "<<sv.at(2) << std::endl;
    //     std::cout << "my at(2) "<<v.at(2) << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // std::cout << "front v : " << v.front() << std::endl;
    // std::cout << "front sys_v : " << sv.front() << std::endl;
    // std::cout << "front const v : " << cv.front() << std::endl;
    // std::cout << "front const sys v : " << c_sv.front() << std::endl;
    // std::cout << "back v : " << v.back() << std::endl;
    // std::cout << "back sys_v : " << sv.back() << std::endl;
    // std::cout << "back const v : " << cv.back() << std::endl;
    // std::cout << "back const sys v : " << c_sv.back() << std::endl;
    
    // v.pop_back();
    // sv.pop_back();
    // v.pop_back();
    // sv.pop_back();
    // v.pop_back();
    // sv.pop_back();
    // for (size_t i = 0; i < v.size(); i++)
    //     std::cout << "after pop my : "<< v[i] << std::endl;
    // for (size_t i = 0; i < sv.size(); i++)
    //     std::cout << "after pop sys : "<< sv[i] << std::endl;
    // v3.push_back(5);
    // v3.push_back(12);
    // v3.push_back(22);
    // v3.push_back(2);
    // v3.push_back(8);

    // sv3.push_back(5);
    // sv3.push_back(12);
    // sv3.push_back(22);
    // sv3.push_back(2);
    // sv3.push_back(8);
    // std::cout << "-------------------------------------" <<std::endl;
    // std::cout << "-----------resize-----------------" <<std::endl;

    // std::cout << "before my "<<v3.capacity() << " | " << v3.size() << std::endl;
    // std::cout << "before sys "<<sv3.capacity() << " | " << sv3.size() << std::endl;

    // v3.resize(2, 11);
    // sv3.resize(2, 11);

    // std::cout << "my "<<v3.capacity() << " | " << v3.size() << std::endl;
    // std::cout << "sys "<<sv3.capacity() << " | " << sv3.size() << std::endl;

    // for (size_t i = 0; i < v3.size(); i++)
    //     std::cout << "my : "<< v3[i] << std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // for (size_t i = 0; i < sv3.size(); i++)
    //      std::cout << "sys : "<< sv3[i] << std::endl;
    
    // std::cout << "my : "<< v3.size() << " | "<<v3.capacity() << " | " << v3[0]<<std::endl;
    // std::cout << "sys : "<< sv3.size() << " | "<<sv3.capacity() << " | " << sv3[0]<<std::endl;
    
    // v3.clear();
    // sv3.clear();
    
    // std::cout << "my : "<< v3.size() << " | "<<v3.capacity() << " | " << v3[0]<<std::endl;
    // std::cout << "sys : "<< sv3.size() << " | "<<sv3.capacity() << " | " << sv3[0]<<std::endl;
    // for (size_t i = 0; i < v3.size(); i++)
    //     std::cout << "befor assign : "<< v3[i] << std::endl;
    // for (size_t i = 0; i < sv3.size(); i++)
    //      std::cout << "befor assign sys : "<< sv3[i] << std::endl;
    // v3.assign(static_cast<size_t>(2), 10);
    // sv3.assign(2, 10);
    // for (size_t i = 0; i < v3.size(); i++)
    //     std::cout << "after assign : "<< v3[i] << std::endl;
    // for (size_t i = 0; i < sv3.size(); i++)
    //      std::cout << "after assign sys : "<< sv3[i] << std::endl;
    //  for (size_t i = 0; i < v2.size(); i++)
    //     std::cout << "befor swap v2: "<< v2[i] << std::endl;
    // for (size_t i = 0; i < sv2.size(); i++)
    //      std::cout << "befor swap sys v2[] : "<< sv2[i] << std::endl;
    // for (size_t i = 0; i < v3.size(); i++)
    //     std::cout << "befor swap v[3]: "<< v3[i] << std::endl;
    // for (size_t i = 0; i < sv3.size(); i++)
    //      std::cout << "befor swap sys v[3]: "<< sv3[i] << std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    //  for (size_t i = 0; i < v2.size(); i++)
    //     std::cout << "after swap v2: "<< v2[i] << std::endl;
    // for (size_t i = 0; i < sv2.size(); i++)
    //      std::cout << "after swap sys v2[] : "<< sv2[i] << std::endl;
    // for (size_t i = 0; i < ve.size(); i++)
    //     std::cout << "after swap v: "<< ve[i] << std::endl;
    // for (size_t i = 0; i < sve.size(); i++)
    //      std::cout << "after swap sys ve: "<< sve[i] << std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // v2.swap(ve);
    // sv2.swap(sve);
    // for (size_t i = 0; i < v2.size(); i++)
    //     std::cout << "after swap v2: "<< v2[i] << std::endl;
    // for (size_t i = 0; i < sv2.size(); i++)
    //      std::cout << "after swap sys v2[] : "<< sv2[i] << std::endl;
    // for (size_t i = 0; i < ve.size(); i++)
    //     std::cout << "after swap v: "<< ve[i] << std::endl;
    // for (size_t i = 0; i < sve.size(); i++)
    //      std::cout << "after swap sys ve: "<< sve[i] << std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // for (size_t i = 0; i < v2.size(); i++)
    //     std::cout << "after oper =  my : "<< v2[i] << std::endl;
    // for (size_t i = 0; i < sv2.size(); i++)
    //     std::cout << "after oper =  sys : "<< sv2[i] << std::endl;
    // std::cout << "-------------------------------------" <<std::endl;
    // v3 = v2;
    // sv3 = sv2;
    //   for (size_t i = 0; i < v3.size(); i++)
    //     std::cout << "aa oper =  my : "<< v3[i] << std::endl;
    // for (size_t i = 0; i < sv3.size(); i++)
    //      std::cout << "aa oper =  sys : "<< sv3[i] << std::endl;
    // system("leaks vector");
    // v3.push_back(12);

}