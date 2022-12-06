#include <iostream> //this is for input output stream
#include <map>      //to include map datastructure
#include <fstream>  //for using file stream
#include <string>   //to use the getline function
#include<stdlib.h>
using namespace std;
class Student // this is the student class
{
public:
    string id, name, program, email, phone, attendance, cgpa;
    Student(string id, string name, string program, string email, string phone, string attendance, string cgpa) // this is the constructor for the class
    {
        this->id = id;
        this->name = name;
        this->program = program;
        this->email = email;
        this->phone = phone;
        this->attendance = attendance;
        this->cgpa = cgpa;
    }
    void namegetter(string id, map<string, Student *> student)
    {
        cout << "The name of the student is " << student[id]->name << endl;
    }
    void programgetter(string id, map<string, Student *> student)
    {
        cout << "The programm of the student is " << student[id]->program << endl;
    }
    void emailgetter(string id, map<string, Student *> student)
    {
        cout << "The email of the student is " << student[id]->email << endl;
    }
    void phonegetter(string id, map<string, Student *> student)
    {
        cout << "The phone of the student is " << student[id]->phone << endl;
    }
    void attendancegetter(string id, map<string, Student *> student)
    {
        cout << "The attendance of the student is " << student[id]->attendance << endl;
    }
    void cgpagetter(string id, map<string, Student *> student)
    {
        cout << "The cgpa of the student is " << student[id]->cgpa << endl;
    }

    void idsetter(Student *st, string Id) // setter function for the class
    {
        st->id = Id;
        cout << "The id of the student is set to" << st->id << endl;
    }
    void namesetter(Student *st, string Name)
    {
        st->name = Name;
        cout << "The name of the student is set to" << st->name << endl;
    }
    void programsetter(Student *st, string Program)
    {
        st->program = Program;
        cout << "The program of the student is set to" << st->program << endl;
    }
    void emailsetter(Student *st, string Email)
    {
        st->email = Email;
        cout << "The email of the student is set to" << st->email << endl;
    }
    void phonesetter(Student *st, string Phone)
    {
        st->phone = phone;
        cout << "The phone of the student is set to" << st->phone << endl;
    }
    void attendancesetter(Student *st, string Attendance)
    {
        st->attendance = Attendance;
        cout << "The attendance of the student is set to" << st->attendance << endl;
    }
    void cgpasetter(Student *st, string Cgpa)
    {
        st->cgpa = Cgpa;
        cout << "The cgpa of the student is set to" << st->cgpa << endl;
    }
};
void UpdateToFile(map<string, Student *> student) // to update the details of the students to the userdetails text file
{
    ofstream MyFile("userdetails.txt"); // to store user details in file
    for (auto it : student)
    {
        MyFile << "Student ID: " << it.first << endl;
        MyFile << "Student Name: " << it.second->name << endl;
        MyFile << "Student Program: " << it.second->program << endl;
        MyFile << "Student Email: " << it.second->email << endl;
        MyFile << "Student Phone: " << it.second->phone << endl;
        MyFile << "Student Attendance: " << it.second->attendance << endl;
        MyFile << "Student CGPA: " << it.second->cgpa << endl;
        MyFile << "______________________________________________________" << endl;
    }
    MyFile.close();
}
void LoginSuccessFull(map<string, Student *> &student) // Looks after what happens after Login
{
    while (true)
    {
        int choice;
        cout << "______________________________________________________" << endl;
        cout << "|                                                     |" << endl;
        cout << "|                    Menu                             |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "|                                                     |" << endl;
        cout << "| 1. List All Students                                |" << endl;
        cout << "| 2. List All Students by  program                    |" << endl;
        cout << "| 3. Add New Student                                  |" << endl;
        cout << "| 4. Search a Student                                 |" << endl;
        cout << "| 5. Modify the data of a  Student                    |" << endl;
        cout << "| 6. Delete a Student                                 |" << endl;
        cout << "|_____________________________________________________|\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "List of all students" << endl;
            cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
            // prints all the details of the student
            for (auto it : student)
            {
                cout << it.first << "\t" << it.second->name << "\t" << it.second->program << "\t" << it.second->email << "\t" << it.second->phone << "\t" << it.second->attendance << "\t" << it.second->cgpa << endl;
            }
        }
        else if (choice == 2)
        {
            string program;
            cout << "Enter the program: ";
            cin >> program;
            cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
            for (auto it : student)
            {
                if (it.second->program == program) // checks for the program
                {
                    cout << it.first << "\t" << it.second->name << "\t" << it.second->program << "\t" << it.second->email << "\t" << it.second->phone << "\t" << it.second->attendance << "\t" << it.second->cgpa << endl;
                }
            }
        }
        else if (choice == 3) // accepts the details from user for modification
        {
            string id, name, program, email, phone, attendance, cgpa;
            cout << "Enter the student id: ";
            cin >> id;
            cout << "Enter the student name: ";
            cin >> name;
            cout << "Enter the student program: ";
            cin >> program;
            cout << "Enter the student email: ";
            cin >> email;
            cout << "Enter the student phone: ";
            cin >> phone;
            cout << "Enter the student attendance: ";
            cin >> attendance;
            cout << "Enter the student cgpa: ";
            cin >> cgpa;
            Student *st = new Student(id, name, program, email, phone, attendance, cgpa);
            student[id] = st;
            cout << "Student added successfully" << endl;
        }
        else if (choice == 4) // to find the student
        {
            string id;
            cout << "Enter the student id: ";
            cin >> id;
            if (student.find(id) != student.end())
            {
                cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
                cout << student[id]->id << " " << student[id]->name << " " << student[id]->program << " " << student[id]->email << " " << student[id]->phone << " " << student[id]->attendance << " " << student[id]->cgpa << endl;
            }
            else
            {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 5) // to modify the student parameters
        {
            string id;
            int choice = 0;
            cout << "Enter the student id: ";
            cin >> id;
            if (student.find(id) != student.end())
            {

                cout << "______________________________________________________" << endl;
                cout << "|                                                     |" << endl;
                cout << "|                    Menu                             |" << endl;
                cout << "|_____________________________________________________|" << endl;
                cout << "|                                                     |" << endl;
                cout << "| 1. Modify Program                                   |" << endl;
                cout << "| 2. Modify Email                                     |" << endl;
                cout << "| 3. Modify Phone number                              |" << endl;
                cout << "| 4. Modify Attendance                                |" << endl;
                cout << "| 5. Modify CGPA                                      |" << endl;
                cout << "| 6. Delete a Student                                 |" << endl;
                cout << "|_____________________________________________________|\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    string program;
                    cout << "Enter the new program: ";
                    cin >> program;
                    student[id]->programsetter(student[id], program);
                }
                else if (choice == 2)
                {
                    string email;
                    cout << "Enter the new email: ";
                    cin >> email;
                    student[id]->emailsetter(student[id], email);
                }
                else if (choice == 3)
                {
                    string phone;
                    cout << "Enter the new phone: ";
                    cin >> phone;
                    student[id]->phonesetter(student[id], phone);
                }
                else if (choice == 4)
                {
                    string attendance;
                    cout << "Enter the new attendance: ";
                    cin >> attendance;
                    student[id]->attendancesetter(student[id], attendance);
                }
                else if (choice == 5)
                {
                    string cgpa;
                    cout << "Enter the new cgpa: ";
                    cin >> cgpa;
                    student[id]->cgpasetter(student[id], cgpa);
                }
                else if (choice == 6) // deletion of student
                {
                    
                        student.erase(id);
                        cout << "Student deleted successfully" << endl;
                }
                else
                {
                    cout << "Invalid choice" << endl;
                }

                if (choice != 6) // we can use this to print the modified row,
                // but if it is the option 6,the key would be deleted so it cannot be used
                {
                    cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
                    cout << student[id]->id << "\t" << student[id]->name << "\t" << student[id]->program << "\t" << student[id]->email << "\t" << student[id]->phone << "\t" << student[id]->attendance << "\t" << student[id]->cgpa << endl;
                }
            }
            else{
                cout<<"The id is not found!"<<endl;
            }
        }
        else if (choice == 6)
        {
            string id;
            cout << "Enter the student id: ";
            cin >> id;
            try//try statement is used because if there is no object for the id
            //the code will throw error,so to avoid that we first check with the .at function then we will delete
            //with .erase()
            {
                student.at(id);
                student.erase(id);
                cout << "Student deleted successfully" << endl;
            }
            catch (const exception &e)//if there is no object for that id this will show
            {
                cout << "The id entered could not been found!" << endl;
            }
        }
        else
        {
            cout << "invalid choice!" << endl;
        }
        UpdateToFile(student); // finally update the details to the file
        string yesorno;
        cout << "Do you want to have any other options to perform(please enter y or Y to continue): ";
        cin >> yesorno;
        if (yesorno == "y" | yesorno == "Y") // please enter y or Y to continue
        {
            continue;
        }
        else
        {
            cout << "Program terminated" << endl;
            break;
        }
    }
}

int main()
{
    map<string, Student *> student;                                            // map that stores key as the id of the student value as the object of the corresponding id
    Student st("1", "Mike", "CS", "abc@seneca.co", "123456789", "100", "3.5"); // mock data
    Student st2("2", "John", "CS", "test@senceca.co", "987654321", "100", "3.5");
    Student st3("3", "Mary", "CS", "sample@seneca.co", "123456789", "100", "3.5");
    student.insert(pair<string, Student *>("1", &st)); // inserting mock data
    student.insert(pair<string, Student *>("2", &st2));
    student.insert(pair<string, Student *>("3", &st3));
    UpdateToFile(student);

    // cout<<"getting the values for student of id 1"<<endl;
    // st.namegetter("1",student);//calling the getter function
    // st.programgetter("1",student);//calling the getter function
    // st.emailgetter("1",student);//calling the getter function
    // st.phonegetter("1",student);//calling the getter function
    // st.attendancegetter("1",student);//calling the getter function
    // st.cgpagetter("1",student);//calling the getter function

    // cout<<"setting the values of the first student object"<<endl;
    // st.programsetter(&st,"CS");//calling the setter function
    // st.emailsetter(&st,"thisisthenew");//calling the setter function
    // st.phonesetter(&st,"123456789");//calling the setter function
    // st.attendancesetter(&st,"100");//calling the setter function
    // st.cgpasetter(&st,"3.5");//calling the setter function
    // st.namesetter(&st,"Mike");//calling the setter function

    // this is for showing the student database menu
    int choice;
    string username;
    string password;
    cout << "____________________________________" << endl;
    cout << "|                                   |" << endl;
    cout << "|        Student Database           |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "| 1- Existing user.                 |" << endl;
    cout << "| 2- New user.                      |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "Please Enter your choice: ";
    cin >> choice;
    if (choice == 2)
    {
        cout << "Please enter your User Name without anyspaces: ";
        cin >> username;
        cout << "Please enter your password without anyspaces: ";
        cin >> password;
        // ios::app is used so that we can append data it to the end of file
        ofstream MyUser("username_and_password.txt", ios::app); // to store user details in file
        MyUser << username << " " << password << endl;
        MyUser.close();
        cout << "Your account has been created successfully." << endl;
        LoginSuccessFull(student); // proceeds after login
    }
    else if (choice == 1)
    {
        cout << "Please enter your User Name without anyspaces: ";
        cin >> username;
        cout << "Please enter your password without anyspaces: ";
        cin >> password;
        ifstream MyFile("username_and_password.txt");
        string line;
        while (getline(MyFile, line))
        {
            if (line == username + " " + password)
            {
                cout << "Login Successfull" << endl;
                LoginSuccessFull(student);
                break;
            }
            else
            {
                cout << "Login Failed" << endl;
            }
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}