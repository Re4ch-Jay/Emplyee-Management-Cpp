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
    if(Employee.age >= 50) {
        ofstream write;
        write.open("retired.txt", ios::app);
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

void readDataRetired() {
    Employee Employee;
    ifstream read;
    read.open("retired.txt");
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
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.attendance;
            read2 >> Employee.dayOff;
            read2 >> Employee.workHours;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.attendance;
                tempFile2 << "\n" << Employee.dayOff;
                tempFile2 << "\n" << Employee.workHours;
                tempFile2 << "\n" << Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData deleted successfuly";

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
    ID--; // not test
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
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.attendance;
            read2 >> Employee.dayOff;
            read2 >> Employee.workHours;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.attendance;
                tempFile2 << "\n" << Employee.dayOff;
                tempFile2 << "\n" << Employee.workHours;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< newData.name;
                tempFile2 << "\n"<< newData.age;
                tempFile2 << "\n"<< newData.job;
                tempFile2 << "\n"<< newData.gender;
                tempFile2 << "\n"<< newData.attendance;
                tempFile2 << "\n"<< newData.dayOff;
                tempFile2 << "\n"<< newData.workHours;
                tempFile2 << "\n"<< newData.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // update retired

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
                tempFile << "\n"<< newData.attendance;
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
