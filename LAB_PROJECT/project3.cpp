#include <iostream> //this is for input output stream
#include <map>      //to include map datastructure
#include <fstream>  //for using file stream
#include <string>   //to use the getline function
#include <stdlib.h>
using namespace std;
class Studs // this is the student class
{
public:
    string ID, NAME, PROGRAM, EMAIL, PHONE, ATTEND, CGPA;
    Studs(string id, string name, string program, string email, string phone, string attend, string cgpa)
    {
        ID = id;
        NAME = name;
        PROGRAM = program;
        EMAIL = email;
        PHONE = phone;
        ATTEND = attend;
        CGPA = cgpa;
    }
    void tosetname(Studs *sd, string name) // to set the data
    {
        sd->NAME = name;
    }
    void tosetprogram(Studs *sd, string program)
    {
        sd->PROGRAM = program;
    }
    void tosetemail(Studs *sd, string email)
    {
        sd->EMAIL = email;
    }
    void tosetphone(Studs *sd, string phone)
    {
        sd->PHONE = phone;
    }
    void tosetattend(Studs *sd, string attend)
    {
        sd->ATTEND = attend;
    }
    void tosetgpa(Studs *sd, string cgpa)
    {
        sd->CGPA = cgpa;
    }
    void getname(Studs *sd) // to get data
    {
        cout << sd->NAME << endl;
    }
    void getprogram(Studs *sd)
    {
        cout << sd->PROGRAM << endl;
    }
    void getemail(Studs *sd)
    {
        cout << sd->EMAIL << endl;
    }
    void getphone(Studs *sd)
    {
        cout << sd->PHONE << endl;
    }
    void getattend(Studs *sd)
    {
        cout << sd->ATTEND << endl;
    }
    void getgpa(Studs *sd)
    {
        cout << sd->CGPA << endl;
    }
};
void filewrite(map<string, Studs *> &m) // to write the data in the file
{
    ofstream myfile;
    myfile.open("student.txt");
    for (auto it = m.begin(); it != m.end(); it++)
    {
        myfile << it->first << " " << it->second->NAME << " " << it->second->PROGRAM << " " << it->second->EMAIL << " " << it->second->PHONE << " " << it->second->ATTEND << " " << it->second->CGPA << endl;
    }
    myfile.close();
}
void datafiller(map<string, Studs *> &studentdetails) // to fill the data in the map
{
    Studs *st = new Studs("1", "Rocky", "CS", "abc@seca.co", "123456789", "100", "3.5"); // mock data
    Studs *st2 = new Studs("2", "Rambo", "CS", "test@eca.co", "987654321", "100", "3.5");
    Studs *st3 = new Studs("3", "Venom", "EE", "sample@sea.co", "123456789", "100", "3.5");
    studentdetails.insert(pair<string, Studs *>("1", st)); // inserting the mock data into the map
    studentdetails.insert(pair<string, Studs *>("2", st2));
    studentdetails.insert(pair<string, Studs *>("3", st3));
}
void Verified(map<string, Studs *> &m) // to process the verified data
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
        cout << "| 7. Exit Menu                                        |" << endl;
        cout << "|_____________________________________________________|\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "______________________________________________________" << endl;
            cout << "|                                                     |" << endl;
            cout << "|                    List of Students                 |" << endl;
            cout << "|_____________________________________________________|" << endl;
            cout << "|                                                     |" << endl;
            cout << "| ID | NAME | PROGRAM | EMAIL | PHONE | ATTEND | CGPA |" << endl;
            cout << "|_____________________________________________________|" << endl;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                cout << "| " << it->first << " | " << it->second->NAME << " | " << it->second->PROGRAM << " | " << it->second->EMAIL << " | " << it->second->PHONE << " | " << it->second->ATTEND << " | " << it->second->CGPA << " |" << endl;
            }
            cout << "|_____________________________________________________|" << endl;
        }
        else if (choice == 2)
        {
            string program;
            cout << "Enter the program: ";
            cin >> program;
            cout << "______________________________________________________" << endl;
            cout << "|                                                     |" << endl;
            cout << "|                    List of Students                 |" << endl;
            cout << "|_____________________________________________________|" << endl;
            cout << "|                                                     |" << endl;
            cout << "| ID | NAME | PROGRAM | EMAIL | PHONE | ATTEND | CGPA |" << endl;
            cout << "|_____________________________________________________|" << endl;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                if (it->second->PROGRAM == program)
                {
                    cout << "| " << it->first << " | " << it->second->NAME << " | " << it->second->PROGRAM << " | " << it->second->EMAIL << " | " << it->second->PHONE << " | " << it->second->ATTEND << " | " << it->second->CGPA << " |" << endl;
                }
            }
            cout << "|_____________________________________________________|" << endl;
        }
        else if (choice == 3)
        {
            string id, name, program, email, phone, attend, cgpa;
            cout << "Enter the ID: ";
            cin >> id;
            cout << "Enter the Name: ";
            cin >> name;
            cout << "Enter the Program: ";
            cin >> program;
            cout << "Enter the Email: ";
            cin >> email;
            cout << "Enter the Phone: ";
            cin >> phone;
            cout << "Enter the Attendance: ";
            cin >> attend;
            cout << "Enter the CGPA: ";
            cin >> cgpa;
            Studs *st = new Studs(id, name, program, email, phone, attend, cgpa);
            m[id] = st;
            cout << "Student added successfully" << endl;
        }
        else if (choice == 4)
        {
            string id;
            cout << "Enter the ID: ";
            cin >> id;
            if (m.find(id) != m.end())
            {
                cout << "______________________________________________________" << endl;
                cout << "|                                                     |" << endl;
                cout << "|                    List of Students                 |" << endl;
                cout << "|_____________________________________________________|" << endl;
                cout << "|                                                     |" << endl;
                cout << "| ID | NAME | PROGRAM | EMAIL | PHONE | ATTEND | CGPA |" << endl;
                cout << "|_____________________________________________________|" << endl;
                cout << "| " << m[id]->ID << " | " << m[id]->NAME << " | " << m[id]->PROGRAM << " | " << m[id]->EMAIL << " | " << m[id]->PHONE << " | " << m[id]->ATTEND << " | " << m[id]->CGPA << " |" << endl;
                cout << "|_____________________________________________________|" << endl;
            }
            else
            {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 5)
        {
            int choice2;
            string id;
            cout << "Enter the ID: ";
            cin >> id;
            if (m.find(id) != m.end())
            {

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
                cout << "| 6. Delete this Student                              |" << endl;
                cout << "  | 7. Exit this Menu                                   |" << endl;
                cout << "|_____________________________________________________|\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    string program;
                    cout << "Enter the Program: ";
                    cin >> program;
                    m[id]->tosetprogram(m[id], program);
                    cout << "Program modified successfully" << endl;
                }
                else if (choice2 == 2)
                {
                    string email;
                    cout << "Enter the Email: ";
                    cin >> email;
                    m[id]->tosetemail(m[id], email);
                    cout << "Email modified successfully" << endl;
                }
                else if (choice2 == 3)
                {
                    string phone;
                    cout << "Enter the Phone: ";
                    cin >> phone;
                    m[id]->tosetphone(m[id], phone);
                    cout << "Phone modified successfully" << endl;
                }
                else if (choice2 == 4)
                {
                    string attend;
                    cout << "Enter the Attendance: ";
                    cin >> attend;
                    m[id]->tosetattend(m[id], attend);
                    cout << "Attendance modified successfully" << endl;
                }
                else if (choice2 == 5)
                {
                    string cgpa;
                    cout << "Enter the CGPA: ";
                    cin >> cgpa;
                    m[id]->tosetgpa(m[id], cgpa);
                    cout << "CGPA modified successfully" << endl;
                }
                else if (choice2 == 6)
                {
                    m.erase(id);
                    cout << "Student deleted successfully" << endl;
                }
                else if (choice2 == 7)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice" << endl;
                }
            }
            else
            {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 6)
        {
            string id;
            cout << "Enter the ID: ";
            cin >> id;
            if (m.find(id) != m.end())
            {
                m.erase(id);
                cout << "Student deleted successfully" << endl;
            }
            else
            {
                cout << "Student not found" << endl;
            }
        }
        else if (choice == 7)
        {
            cout << "executition ended" << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        filewrite(m);
    }
}
int main()
{

    map<string, Studs *> studentdetails; // map that stores key as the id of the student value as the object of the corresponding id
    datafiller(studentdetails);          // to fill the data in the map
    filewrite(studentdetails);           // calling the function to write the data into the file
    int c;
    string user;
    string pass;
    cout << "____________________________________" << endl;
    cout << "|                                   |" << endl;
    cout << "|         Database                  |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "|                                   |" << endl;
    cout << "| 1. Existing user.                 |" << endl;
    cout << "| 2. New user.                      |" << endl;
    cout << "|___________________________________|" << endl;
    cout << "What do you want to do? ";
    cin >> c;
    if (c == 1)
    {
        cout << "Enter your username: ";
        cin >> user;
        cout << "Enter your password: ";
        cin >> pass;
        ifstream File("users.txt");
        string line;
        while (getline(File, line))
        {
            if (line == user + "+-+" + pass)
            {
                cout << "Logged In!" << endl;
                Verified(studentdetails);
                break;
            }
            else
            {
                cout << "Login Failed" << endl;
            }
        }
    }
    else if (c == 2)
    {
        cout << "Enter your username: ";
        cin >> user;
        cout << "Enter your password: ";
        cin >> pass;
        ofstream File;
        File.open("users.txt", ios::app);
        File << user << "+-+" << pass << endl; // writing the username and password in the file so that it can be used for login
        File.close();
        cout << "Account created!" << endl;
        Verified(studentdetails);
    }

    else
    {
        cout << "Invalid choice" << endl;
    }
}
