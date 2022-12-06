// this program is to have a student database and their menu
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
class StudentsData // this is the student class
{
public:
    string ID, NAME, PROGRAM, EMAIL, PHONE, ATTEND, CGPA;
    StudentsData(string id, string name, string program, string email, string phone, string attend, string cgpa)
    {
        ID = id;
        NAME = name;
        PROGRAM = program;
        EMAIL = email;
        PHONE = phone;
        ATTEND = attend;
        CGPA = cgpa;
    }
    void setNAME(StudentsData *sd, string name) // to set the data
    {
        sd->NAME = name;
    }
    void setPROGRAM(StudentsData *sd, string program)
    {
        sd->PROGRAM = program;
    }
    void setEMAIL(StudentsData *sd, string email)
    {
        sd->EMAIL = email;
    }
    void setPHONE(StudentsData *sd, string phone)
    {
        sd->PHONE = phone;
    }
    void setATTEND(StudentsData *sd, string attend)
    {
        sd->ATTEND = attend;
    }
    void setCGPA(StudentsData *sd, string cgpa)
    {
        sd->CGPA = cgpa;
    }
    void getNAME(StudentsData *sd) // to get data
    {
        cout << sd->NAME << endl;
    }
    void getPROGRAM(StudentsData *sd)
    {
        cout << sd->PROGRAM << endl;
    }
    void getEMAIL(StudentsData *sd)
    {
        cout << sd->EMAIL << endl;
    }
    void getPHONE(StudentsData *sd)
    {
        cout << sd->PHONE << endl;
    }
    void getATTEND(StudentsData *sd)
    {
        cout << sd->ATTEND << endl;
    }
    void getCGPA(StudentsData *sd)
    {
        cout << sd->CGPA << endl;
    }
};
void makedummydata(vector<pair<string, StudentsData *>> &studentdata)
{
    StudentsData *sd = new StudentsData("1", "Ram", "CS", "abc@venc.com", "123456789", "90", "3.5");
    studentdata.push_back(make_pair("1", sd));
    StudentsData *sd1 = new StudentsData("2", "Shyam", "CS", "123@venc.com", "123456789", "95", "3.8");
    studentdata.push_back(make_pair("2", sd1));
    StudentsData *sd2 = new StudentsData("3", "Hari", "EC", "123@gmail.com", "123456789", "90", "4.0");
    studentdata.push_back(make_pair("3", sd2));
}
void updatefile(vector<pair<string, StudentsData *>> studentdata)
{
    ofstream myfile;
    myfile.open("studentdata.txt");
    for (int i = 0; i < studentdata.size(); i++)
    {
        myfile << studentdata[i].first << "," << studentdata[i].second->NAME << "," << studentdata[i].second->PROGRAM << "," << studentdata[i].second->EMAIL << "," << studentdata[i].second->PHONE << "," << studentdata[i].second->ATTEND << "," << studentdata[i].second->CGPA << endl;
    }
    myfile.close();
    return;
}
void showdata(vector<pair<string, StudentsData *>> &studentdata)
{
    cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
    for (auto elem : studentdata)
    {
        cout << elem.first << "\t\t" << elem.second->NAME << "\t\t" << elem.second->PROGRAM << "\t\t" << elem.second->EMAIL << "\t\t" << elem.second->PHONE << "\t\t" << elem.second->ATTEND << "\t\t" << elem.second->CGPA << endl;
    }
}
void LoggedIn(vector<pair<string, StudentsData *>> &studentdata)
{
    while (true)
    {

        int choice;
        cout << "______________________________________________________" << endl;
        cout << "|                                                     |" << endl;
        cout << "|                    Welcome to the Menu!             |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "|                                                     |" << endl;
        cout << "| 1. List All the Students                            |" << endl;
        cout << "| 2. List All the Students by their program           |" << endl;
        cout << "| 3. Add a Student                                    |" << endl;
        cout << "| 4. Search a Student                                 |" << endl;
        cout << "| 5. Modify the data of a Student                     |" << endl;
        cout << "| 6. Delete one Student                               |" << endl;
        cout << "| 7. Exit                                             |" << endl;
        cout << "|_____________________________________________________|\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            showdata(studentdata);
        }
        else if (choice == 2)
        {
            bool found = false;
            string program;
            cout << "Enter the program" << endl;
            cin >> program;
            cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
            for (int i = 0; i < studentdata.size(); i++)
            {
                if (studentdata[i].second->PROGRAM == program)
                {
                    found = true;
                    cout << studentdata[i].first << "\t\t" << studentdata[i].second->NAME << "\t\t" << studentdata[i].second->PROGRAM << "\t\t" << studentdata[i].second->EMAIL << "\t\t" << studentdata[i].second->PHONE << "\t\t" << studentdata[i].second->ATTEND << "\t\t" << studentdata[i].second->CGPA << endl;
                }
            }
            if (!found)
            {
                cout << "No student found" << endl;
            }
        }
        else if (choice == 3)
        {
            bool found = false;
            string id, name, program, email, phone, attend, cgpa;
            cout << "Enter the student ID" << endl;
            cin >> id;
            for (int i = 0; i < studentdata.size(); i++)
            {
                if (studentdata[i].first == id)
                {
                    found = true;
                    cout << "Student ID already exists" << endl;
                }
            }
            if (!found)
            {
                cout << "Enter the student name" << endl;
                cin >> name;
                cout << "Enter the student program" << endl;
                cin >> program;
                cout << "Enter the student email" << endl;
                cin >> email;
                cout << "Enter the student phone" << endl;
                cin >> phone;
                cout << "Enter the student attendance" << endl;
                cin >> attend;
                cout << "Enter the student cgpa" << endl;
                cin >> cgpa;
                StudentsData sd(id, name, program, email, phone, attend, cgpa);
                studentdata.push_back(make_pair(id, &sd));
                updatefile(studentdata);
            }
            showdata(studentdata);
        }
        else if (choice == 4)
        {
            string id;
            bool found = false;
            cout << "Enter the student ID" << endl;
            cin >> id;
            cout << "Student ID\tStudent Name\tProgram\t\tEmail\t\tPhone\t\tAttendance\tCGPA" << endl;
            for (int i = 0; i < studentdata.size(); i++)
            {
                if (studentdata[i].first == id)
                {
                    found = true;
                    cout << studentdata[i].first << "\t\t" << studentdata[i].second->NAME << "\t\t" << studentdata[i].second->PROGRAM << "\t\t" << studentdata[i].second->EMAIL << "\t\t" << studentdata[i].second->PHONE << "\t\t" << studentdata[i].second->ATTEND << "\t\t" << studentdata[i].second->CGPA << endl;
                }
            }
            if (!found)
            {
                cout << "No student found" << endl;
            }
        }
        else if (choice == 5)
        {
            string id;
            bool found = false;
            cout << "Enter the student ID" << endl;
            cin >> id;
            for (int i = 0; i < studentdata.size(); i++)
            {
                if (studentdata[i].first == id)
                {
                    found = true;
                    cout << "______________________________________________________" << endl;
                    cout << "|                                                     |" << endl;
                    cout << "|                    Menu For Modification            |" << endl;
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
                    int choice;
                    cin >> choice;
                    if (choice == 1)
                    {
                        string program;
                        cout << "Enter the program" << endl;
                        cin >> program;
                        studentdata[i].second->setPROGRAM(studentdata[i].second, program);
                        updatefile(studentdata);
                        break;
                    }
                    else if (choice == 2)
                    {
                        string email;
                        cout << "Enter the email" << endl;
                        cin >> email;
                        studentdata[i].second->setEMAIL(studentdata[i].second, email);
                        updatefile(studentdata);
                        break;
                    }
                    else if (choice == 3)
                    {
                        string phone;
                        cout << "Enter the phone" << endl;
                        cin >> phone;
                        studentdata[i].second->setPHONE(studentdata[i].second, phone);
                        updatefile(studentdata);
                        break;
                    }
                    else if (choice == 4)
                    {
                        string attend;
                        cout << "Enter the attendance" << endl;
                        cin >> attend;
                        studentdata[i].second->setATTEND(studentdata[i].second, attend);
                        updatefile(studentdata);
                        break;
                    }
                    else if (choice == 5)
                    {
                        string cgpa;
                        cout << "Enter the cgpa" << endl;
                        cin >> cgpa;
                        studentdata[i].second->setCGPA(studentdata[i].second, cgpa);
                        updatefile(studentdata);
                        break;
                    }
                    else if (choice == 6)
                    {
                        studentdata.erase(studentdata.begin() + i);
                        updatefile(studentdata);
                        break;
                    }
                }
            }
            if (!found)
            {
                cout << "Student with this id not found" << endl;
            }
            showdata(studentdata);
        }
        else if (choice == 6)
        {
            string id;
            bool found = false;
            cout << "Enter the student ID" << endl;
            cin >> id;
            for (int i = 0; i < studentdata.size(); i++)
            {
                if (studentdata[i].first == id)
                {
                    found = true;
                    studentdata.erase(studentdata.begin() + i);
                    updatefile(studentdata);
                    break;
                }
            }
            if (!found)
            {
                cout << "Student with this id not found" << endl;
            }
            showdata(studentdata);
        }
        else if (choice == 7)
        {
            showdata(studentdata);
            cout << "Program terminated" << endl;
            exit(0);
        }
        updatefile(studentdata);
    }
}

int main()
{

    vector<pair<string, StudentsData *>> studentdata; // this is the vector of pair of string and student data
    int chce;                                         // this is the choice variable
    string usrname, psswrd;                           // username and password

    makedummydata(studentdata); // this function is used to make dummy data for testing purpose
    updatefile(studentdata);    // this function is used to update the file with the data in the vector
    cout << "____________________________________" << endl;
    cout << "|                                   |" << endl;
    cout << "|        Students Database          |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "| 1- Are You a Existing user?       |" << endl;
    cout << "| 2- Are you a New user?            |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "Please enter your option" << endl;
    cin >> chce;
    if (chce == 1)
    {
        bool found = false;
        cout << "Please enter your User Name without anyspaces: ";
        cin >> usrname;
        cout << "Please enter your password without anyspaces: ";
        cin >> psswrd;
        ifstream MyFile("userandpass.txt");
        string line;
        while (getline(MyFile, line))
        {
            if (line == usrname + " " + psswrd)
            {
                found = true;
                cout << "Login Successfull" << endl;
                LoggedIn(studentdata); // this function is used to show the menu to the user
                break;
            }
        }
        if (!found)
        {
            cout << "Usename not found!" << endl;
        }
    }
    else if (chce == 2)
    {
        cout << "Please enter your User Name without anyspaces: ";
        cin >> usrname;
        cout << "Please enter your password without anyspaces: ";
        cin >> psswrd;
        ofstream MyFile("userandpass.txt", ios::app);
        MyFile << usrname << " " << psswrd << endl;
        MyFile.close();
        cout << "Login Successfull" << endl;
        LoggedIn(studentdata);
    }
    else
    {
        cout << "Invalid option" << endl;
    }

    return 0;
}