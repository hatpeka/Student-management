#include<iostream>
#include<string>
#include<list>

using namespace std;

class Student {
    private:
        string name;
        int id;
        string phoneNumber;
    public:
        Student(string name, int id, string phoneNumber) {
            this->name = name;
            this->id = id;
            this->phoneNumber = phoneNumber;
        }

        string getName(){
            return name;
        }
        int getID(){
            return id;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }

        string getStudentInfo(){
            return name + "-" + std::to_string(id) + "-" + phoneNumber;
        }

        void setName(string name){
            this->name = name;
        }
        void setID(int id){
            this->id = id;
        }
        void setPhoneNumber(string phoneNumber){
            this->phoneNumber = phoneNumber;
        }

        bool validatePhoneNumber(){
            if(this->phoneNumber.length() != 10){
                return false;
            }
            else{
                return true;
            }
        }
};

class Course {
    private:
        int code;
        string name;
    public:
        Course(int code, string name){
            this->code = code;
            this->name = name;
        }

        int getCode(){
            return code;
        }
        string getName(){
            return name;
        }

        string getCourseInfo(){
            return std::to_string(code) + " " + name;
        }

        void setCode(int code){
            this->code = code;
        }
        void setName(string name){
            this->name = name;
        }

};

class Manager {
    private:
        std::list<Student> studentList;
        std::list<Course> courseList;
    public:
        Manager(){

        }

        void addStudent(){
            string name;
            int id;
            string phoneNumber;
            cout << "Student's name: " << endl;
            cin >> name;
            cout << "Student's id: " << endl;
            cin >> id;
            cout << "Student's phone number: " << endl;
            cin >> phoneNumber;
            Student newStudent = Student(name, id, phoneNumber);
            while(newStudent.validatePhoneNumber() == false){
                cout << "Invalid phone number, try again!";           
                cin >> phoneNumber;
                newStudent.setPhoneNumber(phoneNumber);
            }
            studentList.push_back(newStudent);
        }

        void addCourse(){
            string name;
            int code;
            cout << "Course's code: " << code << endl;
            cin >> code;            
            cout << "Course's name: " << name << endl;
            cin >> name;
            Course newCourse = Course(code, name);
            courseList.push_back(newCourse);
        }

        void showAllStudent(){
            cout << "All students" << endl;
            list<Student> tempList = studentList;
            while(tempList.empty() == false){
                Student student = tempList.front();
                cout << student.getStudentInfo();
                tempList.pop_front();
            }
        }

        void showAllCourse(){
            cout << "Show all courses" << endl;
            list<Course> tempList = courseList;
            while(tempList.empty() == false){
                Course course = tempList.front();
                cout << course.getCourseInfo();
                tempList.pop_front();
            }
        }

        void deleteCourse(int code){
            bool found = false;
            for (auto i=courseList.begin(); i != courseList.end(); ++i){
                if (i->getCode() == code){
                    found = true;
                    courseList.erase(i);
                }
            }
            if (found == true){
                    cout << "Delete sucess!" << endl;
                }
                else{
                    cout << "Code not found!" << endl;
                }
        }

        void deleteStudent(int id){
            bool found = false;
            for (auto i=studentList.begin(); i != studentList.end(); ++i){
                if (i->getID() == id){
                    found = true;
                    studentList.erase(i);
                }
            }
            if (found == true){
                cout << "Delete success!" << endl;
            }
            else{
                cout << "Id not found!" << endl;
            }            
        }

        void editStudent(int id){
            bool found = false;
            string newName;
            int newId;
            string newPhoneNumber;

            for (auto i=studentList.begin(); i != studentList.end(); ++i){
                if (i->getID() == id){
                    found = true;
                    cout << "New student's name: " << endl;           
                    cin >> newName;
                    i->setName(newName);
                    cout << "New student's ID: " << endl;           
                    cin >> newId;
                    i->setID(newId);
                    cout << "New student's phone number: " << endl;           
                    cin >> newPhoneNumber;
                    i->setPhoneNumber(newPhoneNumber);
                    if (i->validatePhoneNumber() == false){
                        cout << "Invalid phone number!" << endl;
                        cin >> newPhoneNumber;
                        i->setPhoneNumber(newPhoneNumber);
                    }
                    cout << "Student's info updated" << endl;                   
                }
            }
            if (found == false){
                cout << "Id not found!" << endl;
            }
        } 
};





int main() {
    Manager manager;
    int choice;
    do{
        cout << "Student management system using C++" << endl;
        cout << "===================================" << endl;
        cout << "[1]. Add a new student" << endl;
        cout << "[2]. Show all students" << endl;
        cout << "[3]. Add a new course" << endl;
        cout << "[4]. Show all courses" << endl;
        cout << "[5]. Edit a student" << endl;
        cout << "[6]. Delete a student" << endl;
        cout << "[7]. Delete a course" << endl;
        cout << "[8]. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.showAllStudent();
            break;
        case 3:
            manager.addCourse();
            break;
        case 4:
            manager.showAllCourse();
            break;
        case 5:
            int id;
            cout << "Id of the student?" << endl;
            cin >> id;
            manager.editStudent(id);
            break;
        case 6:
            int id;
            cout << "Id of the student?" << endl;
            cin >> id;        
            manager.deleteStudent(id);
            break;
        case 7:
            int code;
            cout << "Code of the course?" << endl;
            cin >> code;        
            manager.deleteCourse(code);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }while (choice != 8);
    return 0;
}