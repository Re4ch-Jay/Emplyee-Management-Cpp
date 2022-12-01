#include <iostream>
#include <fstream>
#include<string>

using namespace std;
int ID;

struct Employee {

    int id;
    string name;
    string job;
    int age;
    string gender;
    string attendance;
    string dayOff;
    double workHours;
    double salary;
};

void addEmployee() {
    List *ls;
    ls = createEmptyList();
    Employee Employee;
    cout << "\n\tEnter Employee name : ";
    cin.get();
    getline(cin, Employee.name); //Nouman Habib
    cout << "\n\tEnter Employee age : ";
    cin >> Employee.age;
    cout << "\n\tEnter Employee job : ";
    cin >> Employee.job;
    cout << "\n\tEnter Employee gender : ";
    cin >> Employee.gender;
    cout << "\n\tEnter Employee attendance : ";
    cin >> Employee.attendance;
    cout << "\n\tEnter Employee Day off (Monday or Sunday) : ";
    cin >> Employee.dayOff;
    cout << "\n\tEnter Employee work hours : ";
    cin >> Employee.workHours;
    cout << "\n\tEnter Employee salary: ";
    cin >> Employee.salary;
    ID++;

    insertToReportFileAndSave(ls, ID, Employee.name, Employee.job, Employee.salary, Employee.gender, Employee.attendance, Employee.dayOff, Employee.workHours);

    ofstream write;
    write.open("Employee.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << Employee.name ;
    write << "\n" << Employee.age ;
    write << "\n" << Employee.job ;
    write << "\n" << Employee.gender;
    write << "\n" << Employee.attendance ;
    write << "\n" << Employee.dayOff ;
    write << "\n" << Employee.workHours ;
    write << "\n" << Employee.salary;

    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print(Employee s) {
    cout << "\tID is : " << s.id;
    cout << "\tName is : " << s.name;
    cout << "\tAge is : " << s.age;
    cout << "\tJob is : " << s.job;
    cout << "\tGender is : " << s.gender;
    cout << "\tAttendance is : " << s.attendance;
    cout << "\tDay Off is : " << s.dayOff;
    cout << "\tWork hours is : " << s.workHours;
    cout << "\tSalary is : " << s.salary;
    cout <<endl;
}

void readData() {
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.attendance;
        read >> Employee.dayOff;
        read >> Employee.workHours;
        read >> Employee.salary;     
        print(Employee);
    }
    read.close();
}

int searchDataById() {
    int id;
    cout << "\n\tEnter Employee id want to search : ";
    cin >> id;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.attendance;
        read >> Employee.dayOff;
        read >> Employee.workHours;
        read >> Employee.salary;
        if (Employee.id == id) {
            print(Employee);
            return id;
        }
    }
}

double searchDataBySalary() {
    double salary;
    int count = 0;
    cout << "\n\tEnter Employee salary want to search : ";
    cin >> salary;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.attendance;
        read >> Employee.dayOff;
        read >> Employee.workHours;
        read >> Employee.salary;
        if (Employee.salary == salary) {
            print(Employee);
            return salary;
        }
    }
}

string searchDataByName() {
    string name;
    cout << "\n\tEnter Employee job want to search : ";
    cin >> name;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.attendance;
        read >> Employee.dayOff;
        read >> Employee.workHours;
        read >> Employee.salary;
        if (Employee.name == name) {
            print(Employee);
            return name;
        }
    }
}

string searchDataByJob() {
    string job;
    cout << "\n\tEnter Employee job want to search : ";
    cin >> job;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.attendance;
        read >> Employee.dayOff;
        read >> Employee.workHours;
        read >> Employee.salary;
        if (Employee.job == job) {
            print(Employee);
            return job;
        }
    }
}


void deleteData() {
    int id = searchDataById();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Employee Employee;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.attendance;
            read >> Employee.dayOff;
            read >> Employee.workHours;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.attendance;
                tempFile << "\n" << Employee.dayOff;
                tempFile << "\n" << Employee.workHours;
                tempFile << "\n" << Employee.salary;
            }
        }
        read.close();
        tempFile.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateData() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Employee newData;
        cout << "\n\tEnter Employee name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        cout << "\n\tEnter Employee job : ";
        cin >> newData.job;
        cout << "\n\tEnter Employee gender : ";
        cin >> newData.gender;
        cout << "\n\tEnter Employee attendance : ";
        cin >> newData.attendance;
        cout << "\n\tEnter Employee day off : ";
        cin >> newData.dayOff;
        cout << "\n\tEnter Employee work hours : ";
        cin >> newData.workHours;
        cout << "\n\tEnter Employee salary : ";
        cin >> newData.salary;
        
        Employee Employee;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.attendance;
            read >> Employee.dayOff;
            read >> Employee.workHours;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.attendance;
                tempFile << "\n" << Employee.dayOff;
                tempFile << "\n" << Employee.workHours;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n"<< newData.job;
                tempFile << "\n"<< newData.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< newData.dayOff;
                tempFile << "\n"<< newData.workHours;
                tempFile << "\n"<< newData.salary;
            }
        }
        read.close();
        tempFile.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

// int main()
// {
//     ifstream read;
//     read.open("id.txt");
//     if (!read.fail()) {
//         read >> ID;
//     }
//     else {
//         ID = 0;
//     }
//     read.close();

//     while (true) {
//         cout << "\n\t1.Add Employee data";
//         cout << "\n\t2.See Employee data";
//         cout << "\n\t3.Search Employee data";
//         cout << "\n\t4.Delete Employee data";
//         cout << "\n\t5.Update Employee data";

//         int choice;
//         cout << "\n\tEnter choice : ";
//         cin >> choice;
//         switch (choice) {
//         case 1:
//             addEmployee();
//             break;
//         case 2:
//             readData();
//             break;
//         case 3:
//             searchData();
//             break;
//         case 4:
//             deleteData();
//             break;
//         case 5:
//             updateData();
//             break;
//         }
//     }

// }
