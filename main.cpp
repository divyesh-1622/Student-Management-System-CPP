#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:


    void addStudent()
    {
        do
        {
            cout << "\nEnter Roll Number (Positive Number): ";
            cin >> rollNo;

            if(rollNo <= 0)
            {
                cout << "Invalid Roll Number! Try Again.\n";
            }

        } while(rollNo <= 0);

        cout << "Enter Full Name: ";
        getline(cin>>ws, name);

        do
        {
            cout << "Enter Marks (0 - 100): ";
            cin >> marks;

            if(marks < 0 || marks > 100)
            {
                cout << "Invalid Marks! Try Again.\n";
            }

        } while(marks < 0 || marks > 100);
    }

    void displayStudent()
    {
        cout << "\n---------------------------";
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nMarks       : " << marks;
        cout << "\n---------------------------";
    }

    int getRollNo()
    {
        return rollNo;
    }
};

int main()
{
    Student students[100];

    int count = 0;
    int choice;
    int searchRoll;
    bool found;

    while(true)
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:

                if(count < 100)
                {
                    students[count].addStudent();
                    count++;

                    cout << "\nStudent Added Successfully!";
                }
                else
                {
                    cout << "\nStorage Full!";
                }

                break;

            case 2:

                if(count == 0)
                {
                    cout << "\nNo Students Found!";
                }
                else
                {
                    cout << "\n\n==== STUDENT RECORDS ====\n";

                    for(int i = 0; i < count; i++)
                    {
                        students[i].displayStudent();
                    }
                }

                break;

            case 3:

                if(count == 0)
                {
                    cout << "\nNo Students Available!";
                    break;
                }

                cout << "\nEnter Roll Number to Search: ";
                cin >> searchRoll;

                found = false;

                for(int i = 0; i < count; i++)
                {
                    if(students[i].getRollNo() == searchRoll)
                    {
                        students[i].displayStudent();
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "\nStudent Not Found!";
                }

                break;

            case 4:

                cout << "\nThank You!";
                return 0;

            default:

                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}