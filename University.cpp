#include "University.h"
#include <ctime>
void University::Menu()
{
    char choice;
    int option;
    while (true)
    {
      system("clear");
    std::cout << std::endl;
    std::cout << "What do you wanna do? " << std::endl
              <<" (_[-C-]_)  Create" << std::endl
              <<" (_[-F-]_)  Find" << std::endl
              <<" (_[-D-]_)  Delete" << std::endl
              <<" (_[-S-]_)  Show all information "  << std::endl
              <<" (_[-U-]_)  Update data "  << std::endl
              <<" (_[-Q-]_)  Quit" << std::endl
              <<"I'm choice: "; std::cin >> choice;
   

    switch (choice)
    {
    case 'C' :
        std::cout << std::endl;
        Create();
        break;
    case 'F':
    std::cout << "Entry student number: ";
    std::cin >> option; 
       Find(option);
        break;
    case 'S':
        Show();
        break;
    case 'D':
        std::cout << "Entry number of student: " ;
        std::cin >> option;
        Delete(option);
      break; 
    case 'Q':
        exit(0);
        break;
    default:
        std::cout << "-- Invalid argument" << std::endl << std::endl;
        break;
    }
 }
}

void University::Create()
{
    // Тут создаются сами студенты
  if (Student *student = new Student())
  {
    // Заполняем поля объекта нужной нам инфой
    // За вывод и ввод у нас отвечает перегрузка операторов, кот. реализованна в стьютенд
     std::cout << "++ New student has been created! " << std::endl;
     std::cin >> *student;
      students.insert(std::pair<int, Student * >{student->group, student});
    
    // P.S Не понял для чего мы использовали список, когда расспределяли города поездов
    // Поэтому его не реализовал ...
  }
  else
  {
      std::cout << "-- Sorry train has didn't created! " << std::endl
                << " Try to create your train later! " << std::endl
                <<"Recommend : You can create this train in main menu!" << std::endl;
      std::cout << std::endl << "Press any key for exit ... ";
      std::cin.get();
        getc(stdin);
  }
}

void University::Find(int num)
{
   if (students[num])
   {
      std::cout << " ++ I was found your student! " << std::endl;
      Student *student = students[num];
      std::cout << *student;
      
      std::cout << std::endl << "Press any key for exit ... ";
      std::cin.get();
     getc(stdin);
   }
   else
   {
       std::cout << "-- Student with " << num << " number has not be found!" << std::endl;
      std::cout << std::endl << "Press any key for exit ... ";
    std::cin.get();
     getc(stdin);
   }

}

void University::Delete(int value)
{
  int j=0;
  if(students[value])
  { 
    Student *student = students[value];
    std::cout << "Currently value: " << std::endl << *student << std::endl;
      students.erase(value);
           delete student;
         student = nullptr;

   for (auto i : students) // Перебор 
    {
        std::cout << ++j<< "." << *i.second << " " << std::endl; // Вывод содержимого на экран.
    }
        std::cout << std::endl 
                  << "All " << j << " student be found! " << std::endl
                  << "++ Ready" << std::endl
                  << std::endl << "Press any key for exit ... ";
                     std::cin.get();
        getc(stdin);
    }
}

//void University::Update(int value)
//{
   /// 
//}

void University::Show()
{
    int j=0;
    for (auto i : students) // Перебор 
    {
         
        std::cout << ++j<< "." << *i.second << " " << std::endl; // Вывод содержимого на экран.
    }
        std::cout << std::endl 
                  << "All " << j << " student be found! " << std::endl; 
    
    std::cout << std::endl << "Press any key for exit ... ";
    std::cin.get();
     getc(stdin);
}