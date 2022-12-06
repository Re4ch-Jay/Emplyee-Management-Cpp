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
    
    do
    {
        cout << "\n\tEnter Employee job (Developer, Teacher, Accounting) **The department is not allowed to change : ";
        cin >> Employee.job;
        if(Employee.job == "Developer" || Employee.job == "Teacher" || Employee.job == "Accounting") {
            break;
        }else{
            cout<<"\n\tPlease input incorrectly"<<endl;
        }
    } while (Employee.job != "Developer" || Employee.job != "Teacher" || Employee.job != "Accounting");
    
    
    do
    {
        cout << "\n\tEnter Employee gender : ";
        cin >> Employee.gender;
        if(Employee.gender == "M" || Employee.gender == "F") {
            break;
        }else{
            cout<<"\n\tPlease input incorrectly"<<endl;
        }
        
    } while (Employee.gender != "M" || Employee.gender != "F");
    
    do
    {
        cout << "\n\tEnter Employee attendance (P or A) : ";
        cin >> Employee.attendance;
        if(Employee.attendance == "P" || Employee.attendance == "A") {
            break;
        }else{
            cout<<"\n\tPlease input incorrectly"<<endl;
        }
    } while (Employee.attendance != "P" || Employee.attendance != "A");
    
    cout << "\n\tEnter Employee Day off: ";
    cin >> Employee.dayOff;
    cout << "\n\tEnter Employee work hours : ";
    cin >> Employee.workHours;
    cout << "\n\tEnter Employee salary: ";
    cin >> Employee.salary;
    ID++;

    insertToReportFileAndSave(ls, ID, Employee.name, Employee.job, Employee.salary, Employee.gender, Employee.attendance, Employee.dayOff, Employee.workHours);
    // store upcomming retired employee
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

    if(Employee.job == "Developer") {
        // store developer department
        ofstream write;
        write.open("Developer.txt", ios::app);
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

    if(Employee.job == "Accounting"){

        // store accounting department
        ofstream write;
        write.open("Accounting.txt", ios::app);
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

    if(Employee.job == "Teacher") {
        // store teacher department
        ofstream write;
        write.open("Teacher.txt", ios::app);
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

    // store all employee
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
    if(!read.is_open()){
        cout<<"\n\tCould not open the file"<<endl;
    }
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


void readDataDeveloper() {
    Employee Employee;
    ifstream read;
    read.open("Developer.txt");
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

void readDataAccounting() {
    Employee Employee;
    ifstream read;
    read.open("Accounting.txt");
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

void readDataTeacher() {
    Employee Employee;
    ifstream read;
    read.open("Teacher.txt");
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

void searchDataBySalary() {
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
        }
    }
}

void searchDataByAttendance() {
    string attendance;
    cout << "\n\tEnter Employee attendance (P or A) want to search : ";
    cin >> attendance;
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
        if (Employee.attendance == attendance) {
            print(Employee);
        }
    }
}

void searchDataByGender() {
    string gender;
    cout << "\n\tEnter Employee gender (M or F) want to search : ";
    cin >> gender;
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
        if (Employee.gender == gender) {
            print(Employee);
        }
    }
}


void searchDataByDayOff() {
    string dayOff;
    cout << "\n\tEnter Employee day off (Monday or Sunday) want to search : ";
    cin >> dayOff;
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
        if (Employee.dayOff == dayOff) {
            print(Employee);
        }
    }
}

void searchDataByAge() {
    int age;
    cout << "\n\tEnter Employee age want to search : ";
    cin >> age;
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
        if (Employee.age == age) {
            print(Employee);
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
        // delete from upcomming retired file
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

        // delete from developer department
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData deleted successfuly";

        // delete from accounting department
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData deleted successfuly";

        // delete from teacher department
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData deleted successfuly";
        

        // delete from all employees file
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
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        // cout << "\n\tEnter Employee job : ";
        // cin >> newData.job;
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

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.job;
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


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< newData.name;
                tempFile3 << "\n"<< newData.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< newData.gender;
                tempFile3 << "\n"<< newData.attendance;
                tempFile3 << "\n"<< newData.dayOff;
                tempFile3 << "\n"<< newData.workHours;
                tempFile3 << "\n"<< newData.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< newData.name;
                tempFile4 << "\n"<< newData.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< newData.gender;
                tempFile4 << "\n"<< newData.attendance;
                tempFile4 << "\n"<< newData.dayOff;
                tempFile4 << "\n"<< newData.workHours;
                tempFile4 << "\n"<< newData.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< newData.name;
                tempFile5 << "\n"<< newData.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< newData.gender;
                tempFile5 << "\n"<< newData.attendance;
                tempFile5 << "\n"<< newData.dayOff;
                tempFile5 << "\n"<< newData.workHours;
                tempFile5 << "\n"<< newData.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.job;
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

void updateDataName() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee name : ";
        cin.get();
        getline(cin, newData.name);
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< newData.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< newData.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< newData.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< Employee.workHours;
                tempFile << "\n"<< Employee.salary;
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

void updateDataAge() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< newData.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< newData.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< newData.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< newData.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< Employee.workHours;
                tempFile << "\n"<< Employee.salary;
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

void updateDataAttendance() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        
        do
        {
            cout << "\n\tEnter Employee attendance : ";
            cin >> newData.attendance;
            if(newData.attendance == "P" || newData.attendance == "A") {
                break;
            }else{
                cout<<"\n\tInvalid Input"<<endl;
            }
        } while (newData.attendance != "P" || newData.attendance != "A");
        
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< newData.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< newData.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< newData.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< newData.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< newData.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< Employee.workHours;
                tempFile << "\n"<< Employee.salary;
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

void updateDataGender() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        
        do
        {
            cout << "\n\tEnter Employee gender : ";
            cin >> newData.gender;
            if(newData.gender == "M" || newData.gender == "F") {
                break;
            }else {
                cout<<"\n\tInvalid Input"<<endl;
            }
        } while (newData.gender != "M" || newData.gender != "F");
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< newData.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< newData.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< newData.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< newData.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< newData.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< Employee.workHours;
                tempFile << "\n"<< Employee.salary;
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

void updateDataDayOff() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee day off : ";
        cin >> newData.dayOff;
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< newData.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< newData.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< newData.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< newData.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< newData.dayOff;
                tempFile << "\n"<< Employee.workHours;
                tempFile << "\n"<< Employee.salary;
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

void updateDataSalary() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee salary : ";
        cin >> newData.salary;
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< Employee.workHours;
                tempFile2 << "\n"<< newData.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< Employee.workHours;
                tempFile3 << "\n"<< newData.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< Employee.workHours;
                tempFile4 << "\n"<< newData.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< Employee.workHours;
                tempFile5 << "\n"<< newData.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< Employee.workHours;
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

void updateDataWorkHours() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee work hours : ";
        cin >> newData.workHours;
        
        Employee Employee;

        // uppdate upcomming retired file
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
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.attendance;
                tempFile2 << "\n"<< Employee.dayOff;
                tempFile2 << "\n"<< newData.workHours;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // uppdate Developer department file
        ofstream tempFile3;
        tempFile3.open("temp3.txt");
        ifstream read3;
        read3.open("Developer.txt");
        while (!read3.eof()) {
            read3 >> Employee.id;
            read3.ignore();
            getline(read3, Employee.name);
            read3 >> Employee.age;
            read3 >> Employee.job;
            read3 >> Employee.gender;
            read3 >> Employee.attendance;
            read3 >> Employee.dayOff;
            read3 >> Employee.workHours;
            read3 >> Employee.salary;
            if (Employee.id != id) {
                tempFile3 << "\n" << Employee.id;
                tempFile3 << "\n" << Employee.name;
                tempFile3 << "\n" << Employee.age;
                tempFile3 << "\n" << Employee.job;
                tempFile3 << "\n" << Employee.gender;
                tempFile3 << "\n" << Employee.attendance;
                tempFile3 << "\n" << Employee.dayOff;
                tempFile3 << "\n" << Employee.workHours;
                tempFile3 << "\n" << Employee.salary;
            }
            else {
                tempFile3 << "\n"<< Employee.id;
                tempFile3 << "\n"<< Employee.name;
                tempFile3 << "\n"<< Employee.age;
                tempFile3 << "\n"<< Employee.job;
                tempFile3 << "\n"<< Employee.gender;
                tempFile3 << "\n"<< Employee.attendance;
                tempFile3 << "\n"<< Employee.dayOff;
                tempFile3 << "\n"<< newData.workHours;
                tempFile3 << "\n"<< Employee.salary;
            }
        }
        read3.close();
        tempFile3.close();
        remove("Developer.txt");
        rename("temp3.txt", "Developer.txt");
        cout << "\n\tData updated successfuly";


        // uppdate accounting department file
        ofstream tempFile4;
        tempFile4.open("temp4.txt");
        ifstream read4;
        read4.open("Accounting.txt");
        while (!read4.eof()) {
            read4 >> Employee.id;
            read4.ignore();
            getline(read4, Employee.name);
            read4 >> Employee.age;
            read4 >> Employee.job;
            read4 >> Employee.gender;
            read4 >> Employee.attendance;
            read4 >> Employee.dayOff;
            read4 >> Employee.workHours;
            read4 >> Employee.salary;
            if (Employee.id != id) {
                tempFile4 << "\n" << Employee.id;
                tempFile4 << "\n" << Employee.name;
                tempFile4 << "\n" << Employee.age;
                tempFile4 << "\n" << Employee.job;
                tempFile4 << "\n" << Employee.gender;
                tempFile4 << "\n" << Employee.attendance;
                tempFile4 << "\n" << Employee.dayOff;
                tempFile4 << "\n" << Employee.workHours;
                tempFile4 << "\n" << Employee.salary;
            }
            else {
                tempFile4 << "\n"<< Employee.id;
                tempFile4 << "\n"<< Employee.name;
                tempFile4 << "\n"<< Employee.age;
                tempFile4 << "\n"<< Employee.job;
                tempFile4 << "\n"<< Employee.gender;
                tempFile4 << "\n"<< Employee.attendance;
                tempFile4 << "\n"<< Employee.dayOff;
                tempFile4 << "\n"<< newData.workHours;
                tempFile4 << "\n"<< Employee.salary;
            }
        }
        read4.close();
        tempFile4.close();
        remove("Accounting.txt");
        rename("temp4.txt", "Accounting.txt");
        cout << "\n\tData updated successfuly";


        // uppdate teacher department file
        ofstream tempFile5;
        tempFile5.open("temp5.txt");
        ifstream read5;
        read5.open("Teacher.txt");
        while (!read5.eof()) {
            read5 >> Employee.id;
            read5.ignore();
            getline(read5, Employee.name);
            read5 >> Employee.age;
            read5 >> Employee.job;
            read5 >> Employee.gender;
            read5 >> Employee.attendance;
            read5 >> Employee.dayOff;
            read5 >> Employee.workHours;
            read5 >> Employee.salary;
            if (Employee.id != id) {
                tempFile5 << "\n" << Employee.id;
                tempFile5 << "\n" << Employee.name;
                tempFile5 << "\n" << Employee.age;
                tempFile5 << "\n" << Employee.job;
                tempFile5 << "\n" << Employee.gender;
                tempFile5 << "\n" << Employee.attendance;
                tempFile5 << "\n" << Employee.dayOff;
                tempFile5 << "\n" << Employee.workHours;
                tempFile5 << "\n" << Employee.salary;
            }
            else {
                tempFile5 << "\n"<< Employee.id;
                tempFile5 << "\n"<< Employee.name;
                tempFile5 << "\n"<< Employee.age;
                tempFile5 << "\n"<< Employee.job;
                tempFile5 << "\n"<< Employee.gender;
                tempFile5 << "\n"<< Employee.attendance;
                tempFile5 << "\n"<< Employee.dayOff;
                tempFile5 << "\n"<< newData.workHours;
                tempFile5 << "\n"<< Employee.salary;
            }
        }
        read5.close();
        tempFile5.close();
        remove("Teacher.txt");
        rename("temp5.txt", "Teacher.txt");
        cout << "\n\tData updated successfuly";



        // update all employees from employee file
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
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.attendance;
                tempFile << "\n"<< Employee.dayOff;
                tempFile << "\n"<< newData.workHours;
                tempFile << "\n"<< Employee.salary;
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
