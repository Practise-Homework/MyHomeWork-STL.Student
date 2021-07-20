#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <istream> 

class Student
{
  public:
  int group;
  std::string name;
  std::string surname;

   friend std::ostream& operator<<(std::ostream& out , const Student&);
   friend std::istream& operator>>(std::istream& in , Student&);

};
    std::ostream& operator<<(std::ostream& out , const Student&);
    std::istream& operator>>(std::istream& in , Student&);