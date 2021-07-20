#pragma once
#include "Student.h"
#include <string>
#include  <map>


class University
{
  private:
  std::map<int , Student *> students; 
  public: 
   void Menu();
   void Create(); 
   //void Update(int);
   void Delete(int);
   void Show();
   void Find(int); 
};