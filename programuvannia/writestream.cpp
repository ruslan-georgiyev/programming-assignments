#include <unistd.h>   // Підключає системну бібліотеку UNIX, зокрема функцію sleep()
#include <fstream>    // Підключає бібліотеку для роботи з файлами
using namespace std;  // Використовує простір імен std

int write_stream() {                          // Оголошення функції write_stream
  ofstream myfile;                            // Створює об’єкт для запису у файл
  myfile.open("example_stream.txt", ios::app); // Відкриває файл у режимі "append" (дописування в кінець)
  myfile << "Writing this to a file\n";       // Записує рядок у файл
  sleep(1);  // Pauses the program for 1 second // Призупиняє виконання програми на 1 секунду
  myfile.close();                             // Закриває файл після завершення запису
  return 0;                                   // Повертає код успішного виконання (0)
}
int main() { return write_stream(); };        // Точка входу в програму: викликає функцію write_stream
