#include <unistd.h>   // Підключає системну бібліотеку UNIX, зокрема функцію sleep()
#include <fstream>    // Підключає бібліотеку для роботи з файлами
#include <iostream>   // Підключає бібліотеку для вводу/виводу
using namespace std;  // Використовує простір імен std

int write_stream_ext() {                        // Оголошення функції write_stream_ext
  ofstream myfile;                              // Створює об’єкт для запису у файл
  myfile.open("example_stream.txt");            // Відкриває файл для запису (перезаписує існуючий)
  for (int i = 0; i < 60; i++) {                // Цикл від 0 до 59 (усього 60 ітерацій)
    myfile << i << "Writing this to a file\n";  // Записує номер ітерації та текст у файл
  }
  // Intentional segmentation fault to crash the program
  // int *ptr = nullptr;                        // Створює нульовий вказівник
  // *ptr = 10;                                 // Спроба запису у пам’ять за адресою nullptr (призведе до аварії)

  myfile.flush();                               // Примусово записує буфер у файл
  myfile << "Writing this to a file\n";         // Додає ще один рядок у файл
  sleep(60);  // Pauses the program for 60 seconds // Призупиняє виконання програми на 60 секунд
  myfile.close();                               // Закриває файл після завершення роботи
  return 0;                                     // Повертає код успішного виконання (0)
}

int main() { return write_stream_ext(); };      // Точка входу в програму: викликає функцію write_stream_ext
