#include <fstream>  
#include <iostream> 
#include <string>
#include <algorithm>    
using namespace std;

struct Information{
	string name;
	string surname;
	string department;
	int salary;
};

bool compareSurnames(Information a, Information b){
  return a.surname<b.surname;
}
bool compareSalaries(Information a, Information b){
  return a.salary>b.salary;
}


void read_stream() {                     
  ifstream myfile("test.txt");  
  if (myfile.is_open()) {                   
    string line;                        
    string word;
    int count = 0;
    while (getline(myfile, line)) {         
        count++;
        cout << line << endl;         
    }
    cout<<count<<endl;
    Information *array = new Information[count];
    myfile.clear();
    myfile.seekg(0);
    for(int i=0;i<count;i++){
        myfile>>word;
        array[i].name=word;
        myfile>>word;
        array[i].surname=word;
        myfile>>word;
        array[i].department=word;
        myfile>>word;
        array[i].salary=stoi(word);
    }
    for(int i=0;i<count;i++){
        cout<<array[i].name<<" "<<array[i].surname<<" "<<array[i].department<<" "<<array[i].salary<<" "<<endl;
    }
    myfile.clear();
    myfile.seekg(0);

  sort(array,array+count,compareSurnames);
  ofstream outfile1("testsorted1.txt");
  for(int i=0;i<count;i++){
    outfile1<<array[i].name<<" "<<array[i].surname<<" "<<array[i].department<<" "<<array[i].salary<<endl;
      }
  outfile1.close();

  sort(array,array+count,compareSalaries);
  int maxIndex=0;
  for(int i=0;i<count;i++){
    if(array[i].salary>array[maxIndex].salary){
      maxIndex=i;
    }
  }
  int totalSalary=0;
  for(int i=0;i<count;i++){
    totalSalary=totalSalary+array[i].salary;
  }

  ofstream outfile2("testsorted2.txt");
  for(int i=0;i<count;i++){
      outfile2<<array[i].name<<" "<<array[i].surname<<" "<<array[i].department<<" "<<array[i].salary<<endl;
      }
      outfile2<<"Найбільша заробітна плата - "<<array[maxIndex].salary<<endl<<"Спільна заробітна плата - "<<totalSalary<<endl;
  outfile2.close();

    myfile.close();                            
  } else {                                     
    cout << "Unable to open file" << endl;
  }
}

int main() { 
    read_stream(); 
}
