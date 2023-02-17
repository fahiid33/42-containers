/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:38:26 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/17 11:31:23 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../iterators/Random_access_iterators.hpp"
#include <vector>
#include <iostream>


int main()
{
  // {
  //   std::vector<int> myvector (3,100);
  //   std::vector<int>::iterator it;
    
  //   std::cout << "myvector contains:";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
    
  //   it = myvector.begin();
  //   it = myvector.insert ( it , 200 );
  //   std::cout << "\nafter insert ( it , 200 ) : ";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << "\nafter insert (it,2,300) : ";
  //   myvector.insert (it,2,300);
  //   for(it = myvector.begin(); it < myvector.end(); it++)
  //       std::cout << ' ' << *it;
  //   it = myvector.begin();

  //   std::vector<int> anothervector (2,400);
  //   std::cout << "\nanothervector contains: 400 400" ;
  //   myvector.insert (it+2,anothervector.begin(),anothervector.end());

  //   std::cout << "\nafter insert (it+2,anothervector.begin(),anothervector.end()) : ";
  //   for (it=anothervector.begin(); it<anothervector.end(); it++)
  //     std::cout << ' ' << *it;
  //   int myarray [] = { 501,502,503 };
  //   myvector.insert(myvector.begin(), myarray, myarray+3);

  //   std::cout << "\n after insert(myvector.begin(), myarray, myarray+3): ";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  //   myvector.erase(myvector.begin());
  //   std::cout << "after erase(myvector.begin()) : ";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  //   myvector.erase(myvector.begin(), myvector.end() - 2);
  //   std::cout << "after erase(myvector.begin(), myvector.begin() + 2) : ";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // } 
    // ////////////////////////////////////////////////////////////
    // ////////////////////////////////////////////////////////////
  //   std::cout << "-----------myvector tests-------------"<< std::endl;
  // {
  //     ft::Vector<int> myVector (3,100);
  //   ft::Vector<int>::iterator my_it;
    
  //   std::cout << "myVector contains:";
  //   for (my_it=myVector.begin(); my_it<myVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
    
  //   my_it = myVector.begin();
  //   my_it = myVector.insert ( my_it , 200 );
  //   std::cout << "\nafter insert ( my_it , 200 ) : ";
  //   for (my_it=myVector.begin(); my_it<myVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
  //   std::cout << "\nafter insert (my_it,2,300) : ";
  //   myVector.insert (my_it,2,300);
  //   for(my_it = myVector.begin(); my_it < myVector.end(); my_it++)
  //       std::cout << ' ' << *my_it;
  //   my_it = myVector.begin();

  //   ft::Vector<int> anotherVector (2,400);
  //   std::cout << "\nanotherVector contains: 400 400" ;
  //   myVector.insert (my_it+2,anotherVector.begin(),anotherVector.end());

  //   std::cout << "\nafter insert (my_it+2,anotherVector.begin(),anotherVector.end()) : ";
  //   for (my_it=anotherVector.begin(); my_it<anotherVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
  //   int myarray [] = { 501,502,503 };
  //   myVector.insert(myVector.begin(), myarray, myarray+3);

  //   std::cout << "\n after insert(myVector.begin(), myarray, myarray+3): ";
  //   for (my_it=myVector.begin(); my_it<myVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
  //   std::cout << '\n';
  //   myVector.erase(myVector.begin());
  //   std::cout << "after erase(myvector.begin()) : ";
  //   for (my_it=myVector.begin(); my_it<myVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
  //   std::cout << '\n';
  //   myVector.erase(myVector.begin(), myVector.end() - 2);
  //   std::cout << "after erase(myVector.begin(), myVector.begin() + 2) : ";
  //   for (my_it=myVector.begin(); my_it<myVector.end(); my_it++)
  //     std::cout << ' ' << *my_it;
  //   std::cout << '\n';
  // }
  std::cout << "===== ft =====" << std::endl;
    ft::Vector<int> ft_vec;
    ft_vec.push_back(1);
    ft_vec.push_back(2);
    ft_vec.push_back(3);
    ft_vec.push_back(4);
    ft_vec.push_back(5);
    ft_vec.push_back(6);
    ft_vec.push_back(7);

    std::cout << "===== iterator =====" << std::endl;
    for (ft::Vector<int>::iterator it = ft_vec.begin(); it < ft_vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "===== reverse_iterator =====" << std::endl;
    for (ft::Vector<int>::reverse_iterator it = ft_vec.rbegin(); it < ft_vec.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "======================" << std::endl << std::endl;

    std::cout << "===== std =====" << std::endl;
    std::vector<int> std_vec;
    std_vec.push_back(1);
    std_vec.push_back(2);
    std_vec.push_back(3);
    std_vec.push_back(4);
    std_vec.push_back(5);
    std_vec.push_back(6);
    std_vec.push_back(7);

    std::cout << "===== iterator =====" << std::endl;
    for (std::vector<int>::iterator it = std_vec.begin(); it < std_vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "===== reverse_iterator =====" << std::endl;
    for (std::vector<int>::reverse_iterator it = std_vec.rbegin(); it < std_vec.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
  //   ft::Vector<int> my_v;
  //   my_v.push_back(5);
  //   my_v.push_back(12);
  //   my_v.push_back(13);
  //   my_v.push_back(1);
  // // Define a regular iterator for the vector.
  //   ft::Vector<int>::iterator it = my_v.begin();

  //   // Increment the iterator and print the value it points to.
  //   ++it;
  //   std::cout << "Regular iterator value: " << *it << std::endl;

  //   // Define a const iterator for the Vector.
  //   ft::Vector<int>::const_iterator const_it = my_v.cbegin();

  //   // Increment the const iterator and print the value it points to.
  //   ++const_it;
  //   std::cout << "Const iterator value: " << *const_it << std::endl;

  // // Try to modify the value using the const iterator.
  // // This will result in a compiler error.
  //   // *const_it = 10;
  //   std::cout << "-------system------------" << std::endl;
  
  //   std::vector<int> v;
  //   v.push_back(5);
  //   v.push_back(12);
  //   v.push_back(13);
  //   v.push_back(1);

  //   // Define a regular iterator for the vector.
  //   std::vector<int>::iterator its = v.begin();

  //   // Increment the iterator and print the value it points to.
  //   ++its;
  //   std::cout << "Regular iterator value: " << *its << std::endl;

  //   // Define a const iterator for the vector.
  //   std::vector<int>::const_iterator const_its = v.cbegin();

  //   // Increment the const iterator and print the value it points to.
  //   ++const_its;
  //   std::cout << "Const iterator value: " << *const_its << std::endl;

    
//   Try to modify the value using the const iterator.
//   This will result in a compiler error.
    // *const_it = 10;

  
    // ft::Vector<int>::iterator it;
    // ft::Vector<int>::iterator it1;
    // ft::Vector<int>v;
    // ft::Vector<int>v1;
    // v.push_back(5);
    // v.push_back(12);
    // v.push_back(13);
    // v.push_back(1);

    // v1.push_back(1);
    // v1.push_back(3);
    // v1.push_back(16);
    // v1.push_back(10);
    // it = v.begin();
    // it1 = v1.begin();
    // it++;
    // it--;
    // // while (it != v.end())
    // // {
    // //     std::cout << *it << std::endl;
    // //     it++;
    // // }
    // std::cout << "-------------------" << std::endl;
    // it = it1;
    // it1 = v.begin();
    // while (it != v1.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
    // std::cout << "-------------------" << std::endl;
    // while (it1 != v1.end())
    // {
    //     std::cout << *it1 << std::endl;
    //     it1++;
    // }
    // std::cout << "-------system------------" << std::endl;

    // std::vector<int>::iterator its;
    // std::vector<int>::iterator it1s;
    // std::vector<int>vs;
    // std::vector<int>v1s;
    // vs.push_back(5);
    // vs.push_back(12);
    // vs.push_back(13);
    // vs.push_back(1);

    // v1s.push_back(1);
    // v1s.push_back(3);
    // v1s.push_back(16);
    // v1s.push_back(10);
    // its = vs.begin();
    // it1s = v1s.begin();
    // its++;
    // its--;
    // // while (it != v.end())
    // // {
    // //     std::cout << *it << std::endl;
    // //     it++;
    // // }
    // std::cout << "-------------------" << std::endl;
    // its = it1s;
    // it1s = vs.begin();
    // while (its != v1s.end())
    // {
    //     std::cout << *its << std::endl;
    //     its++;
    // }
    // std::cout << "-------------------" << std::endl;
    // while (it1s != v1s.end())
    // {
    //     std::cout << *it1s << std::endl;
    //     it1s++;
    // }
    
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