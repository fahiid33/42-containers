/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:37:42 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/21 23:49:52 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include <iostream>
int main()
{
    {
        ft::stack<std::string>a;
        a.push("first in");
        a.push("last in");
        std::cout << "========ft========" << std::endl;
        std::cout << "stack size = "<<a.size() << " | " << "is empty = " <<a.empty() << std::endl;
        std::cout << "top elements of the stack : "<<a.top() << std::endl;
        a.pop();
        std::cout << "after pop top element : \n";
        std::cout << "stack size = "<<a.size() << std::endl;
        std::cout << "top elements of the stack : "<<a.top() << std::endl;
    }
    {
        std::stack<std::string>a;
        a.push("first in");
        a.push("last in");
        std::cout << "========ft========" << std::endl;
        std::cout << "stack size = "<<a.size() << " | " << "is empty = " <<a.empty() << std::endl;
        std::cout << "top elements of the stack : "<<a.top() << std::endl;
        a.pop();
        std::cout << "after pop top element : \n";
        std::cout << "stack size = "<<a.size() << std::endl;
        std::cout << "top elements of the stack : "<<a.top() << std::endl;
    }

}