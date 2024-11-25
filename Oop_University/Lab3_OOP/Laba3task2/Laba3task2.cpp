#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;



class Dean {
private:
    string name;
    int yearAppointed; 

public:
    // Конструктор
    Dean(string name, int yearAppointed) : name(name), yearAppointed(yearAppointed) {}

    
    string getName() const { return name; }
    int getYearAppointed() const { return yearAppointed; }
};


class Student {
protected:
    string name; 
    int id; 

public:
    
    Student(string name, int id) : name(name), id(id) {}

   
    string getName() const { return name; }
    int getId() const { return id; }
};

class MasterStudent : public Student {
private:
    string thesisTopic; 

public:
    
    MasterStudent(string name, int id, string thesisTopic) : Student(name, id), thesisTopic(thesisTopic) {}

    
    string getThesisTopic() const { return thesisTopic; }
};


class Faculty {
private:
    string name; 
    Dean dean; 
    vector<Student*> students; 

public:
    
    Faculty(string name, Dean dean) : name(name), dean(dean) {}

    
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->getId() == id) {
                students.erase(it);
                break;
            }
        }
    }

    
    string getName() const { return name; }
    Dean getDean() const { return dean; }

    
    void showStudents() const {
        cout << "Студенти факультету " << name << ":" << endl;
        for (const auto& student : students) {
            cout << "Ім'я: " << student->getName() << ", ID: " << student->getId() << endl;
        }
    }
};


class University {
private:
    string name;
    string address;
    vector<Faculty*> faculties; 

public:
    
    University(string name, string address) : name(name), address(address) {}

    void addFaculty(Faculty* faculty) {
        faculties.push_back(faculty);
    }

    void removeFaculty(string name) {
        for (auto it = faculties.begin(); it != faculties.end(); ++it) {
            if ((*it)->getName() == name) {
                faculties.erase(it);
                break;
            }
        }
    }

    string getName() const { return name; }
    string getAddress() const { return address; }

   
    void showFaculties() const {
        cout << "Факультети університету " << name << ":" << endl;
        for (const auto& faculty : faculties) {
            cout << "Факультет: " << faculty->getName() << ", Декан: " << faculty->getDean().getName() << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   
    Dean dean("Іван Іванов", 2015);
    Faculty faculty("Інформатика", dean);

    Student student1("Петро Петров", 1);
    Student student2("Марія Іванова", 2);
   
    MasterStudent masterStudent("Олексій Сидоров", 3, "Розробка штучного інтелекту");


   
    faculty.addStudent(&student1);
    faculty.addStudent(&student2);
    faculty.addStudent(&masterStudent);

   
    University university("Центральний національний університет", "вул. Головна, 1");
    university.addFaculty(&faculty);

    
    cout << "Інформація про університет:" << endl;
    cout << "Назва: " << university.getName() << ", Адреса: " << university.getAddress() << endl;
    university.showFaculties();
    faculty.showStudents();

   
    faculty.removeStudent(2);
    cout << "\nПісля видалення студента з ID 2:" << endl;
    faculty.showStudents();

    return 0;
}