#pragma once
#include <ostream>
#include <istream>
#include <ctime>
#include "Student.h"

std::ostream& operator<<(std::ostream& out, const Student& className )
{
   out << std::endl <<"-------------"  << std::endl
       << "Group: " << className.group << std::endl
       << "Name of student: " << className.name << std::endl
       << "Surname of student  : " << className.surname << std::endl
       << "++ Ready!" << std::endl;
  out << "-------------"<< std::endl; 
   return out;
}

std::istream& operator>> (std::istream& in , Student& className)
{
  srand(time(NULL));
   className.group = rand() % 1000;
   std::cout << "++ Rand group value ..." << std::endl;

   if (className.group == className.group)
       className.group= className.group++; 

        std::cout << "Entry name of student: ";
           in >> className.name;
        std::cout << "Entry surname of student: ";
           in >> className.surname;
    return in;
}