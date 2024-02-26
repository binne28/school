#include <bits/stdc++.h>
using namespace std;

//Lop person la cha
class Person{
private:
    string name, gender;
    int age;
public:
    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    void setGender(string g){
        gender = g;
    }

    string getGender(){
        return gender;
    }

    void setAge(int a){
        age = a;
    }

    int getAge(){
        return age;
    }

    virtual void input(){
        cout << "Register" << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Age: ";
        cin >> age;
    }

    virtual void output(){
        cout << "Name: " << name << endl << "Gender: " << gender << endl << "Age: " << endl;
    }
};

//Lop hoc sinh
class Student : public Person{
private: 
    string classes, studenID;
public:
    void setClasses(string cl){
        classes = cl;
    }
    string getClasses(){
        return classes;
    }
    void setStudenID(string id){
        studenID = id;
    }
    string getStudentID(){
        return studenID;
    }
    void input() override{
        Person::input();
        cout << "Student id: ";
        cin >> studenID;
        cout << "Class: ";
        getline(cin, classes);
    }
    
    void output() override{
        Person::output();
        cout << "Student id: " << studenID << endl << "Class: " << classes << endl;
    }
};

//lop nhan vien
class Employee : public Person{
private:
    string employeeID, chucVu;
public:

    void setID(string id){
        employeeID = id;
    }

    string getID(){
        return employeeID;
    }

    void setCV(string cv){
        chucVu = cv;
    }

    string getCV(){
        return chucVu;
    }

    void input() override{
        Person::input();
        cout << "Employee ID: ";
        cin >> employeeID;
        cout << "Position: ";
        getline(cin, chucVu);
    }
    void output() override{
        Person::output();
        cout << "Employee ID: " << getID() << endl << "Position: " << getCV() << endl; 
    }
};


int main(){
    // Student *s = new Student;
    vector<Person*> p;
    // vector<Student*> s;
    int choice;
    do
    {
        cout << "======== BANG THONG TIN ========\n";
        cout << "1. Nhap thong tin\n";
        cout << "2. Hien thi danh sach vua nhap\n";
        cout << "3. Tim kiem theo ma ID\n";
        cout << "4. Tim kiem theo ten\n";
        cout << "0. THOAT CHUONG TRINH\n";
        cout << "NHAP LUA CHO CUA BAN: ";
        cin >> choice;
        system("cls");
        if(choice == 1){
            cin.ignore();
            int loaiChucVu;
            cout << "Chon loai chuc vu (1. Student, 2. Employee): ";
            cin >> loaiChucVu;
            cin.ignore();
            Person* chucVu;
            if(loaiChucVu == 1){
                Student *s = new Student;
                s->input();
                p.push_back(s);
            }else {
                Employee *e = new Employee;
                e->input();
                p.push_back(e);
            }
        }
        else if(choice == 2){
            if(p.empty()){
                cout << "Khong co thong tin trong danh sach\n";
            }else{
                for(auto &x : p){
                    x->output();
                }
            }
        }else if(choice == 3){
            cin.ignore();
            string id;
            cout << "Nhap id muon tim kiem: ";
            cin >> id;
            bool tim = false;
            for(auto &x:p){
                if(Student *s = dynamic_cast<Student*>(x)){
                    if(s->getStudentID() == id){
                        s->output();
                        tim = true;
                    }
                }else if(Employee *e = dynamic_cast<Employee*>(x)){
                    if(e->getID() == id){
                        e->output();
                        tim = true;
                    }
                }
            }
            if(tim == false){
                cout << "Khong tim thay id\n";
            }
        }else if(choice == 4){
            cin.ignore();
            string name;
            cout << "Nhap ten muon tim kiem: ";
            getline(cin, name);
            bool tim = false;
            for(auto &person : p){
                if(Student *s = dynamic_cast<Student*> (person)){
                    if(s->getName() == name){
                        s->output();
                        tim = true;
                    }
                }else if(Employee *e = dynamic_cast<Employee*>(person)){
                    if(e->getName() == name){
                        e->output();
                        tim = true;
                    }
                }
            }
            if(tim == false){
                cout << "Khong tim thay ten\n";
            }
        }
    } while (choice != 0);
    
}