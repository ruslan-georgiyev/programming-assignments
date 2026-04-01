#include <fstream>   // Підключає бібліотеку для роботи з файлами
#include <iostream>  // Підключає бібліотеку для вводу/виводу
#include <string>    // Підключає бібліотеку для роботи з рядками (std::string)
using namespace std; // Використовує простір імен std, щоб не писати std:: перед кожним об’єктом

int word_counter() {                        // Оголошення функції word_counter
  ifstream file("example_stream.txt");      // Відкриває файл для читання
  if (!file) {                              // Перевіряє, чи файл успішно відкрився
    cerr << "File could not be opened\n";   // Виводить повідомлення про помилку у стандартний потік помилок
    return 1;                               // Повертає код помилки (1)
  }

  int wordCount = 0;                        // Лічильник кількості слів, початкове значення 0
  string word;                              // Змінна для збереження кожного слова

  while (file >> word) {                    // Читає слова з файлу, розділені пробілами/розділовими знаками
    ++wordCount;
    cout<<word<<" ";                            // Збільшує лічильник на 1 для кожного слова
  }
  file.close();                             // Закриває файл після завершення читання
  cout << "Number of words in the file: "   // Виводить результат у консоль
       << wordCount << '\n';

  return 0;                                 // Повертає код успішного виконання (0)
}
int main(){
    cout<<word_counter()<<endl;
    return 0;
}
