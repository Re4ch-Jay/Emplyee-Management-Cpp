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
    
    cout << "\n\tEnter Employee Day off (Monday - Sunday): ";
    cin >> Employee.dayOff;
    cout << "\n\tEnter Employee work hours (e.g 10): ";
    cin >> Employee.workHours;
    cout << "\n\tEnter Employee salary (e.g. 3000): ";
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
    cout << "\tSalary is : $" << s.salary;
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
    if(read.eof() && Employee.id != id) {
        cout<<"\n\tThis data with these id is not exist"<<endl;
        return 0;
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

void viewDeveloperDepartment() {
    string department = "Developer" ;
    // cout << "\n\tEnter department want to search : ";
    // cin >> department;
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
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void viewTeachingDepartment() {
    string department = "Teacher" ;
    // cout << "\n\tEnter department want to search : ";
    // cin >> department;
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
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void viewAccountingDepartment() {
    string department = "Accounting" ;
    // cout << "\n\tEnter department want to search : ";
    // cin >> department;
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
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void deleteData() {
    int id = searchDataById();
    if(id == 0) {
        cout<<endl;
    }else{
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

        // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
            // check if Id is equal than saved it to reportData.txt
            if(Employee.id == id) {
                writeToReport << "\tDelete data: ID: " << Employee.id <<"\tName: "<< Employee.name <<"\tJob: "<< Employee.job <<"\tGender: "<< Employee.gender <<"\tAttendance: "<< Employee.attendance<<"\tDay off: "<< Employee.dayOff <<"\tWork hours: "<< Employee.workHours<<"\tSalary: $"<< Employee.salary<<"\tAge: "<< Employee.age<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData deleted successfuly";
       
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
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
    if(id == 0) {
        cout<<endl;
    }else{
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

        // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
                writeToReport << "\tUpdate name with ID: "<<Employee.id <<"\t New name: "<<newData.name<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not updated";
    }
    }
    
}

void updateDataAge() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        
        Employee Employee;

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);
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
        writeToReport.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
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
                writeToReport << "\tUpdate age with ID: "<<Employee.id <<"\t New age: "<<newData.age<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
}

void updateDataAttendance() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
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

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
                writeToReport << "\tUpdate attendance with ID: "<<Employee.id <<"\t New attendance: "<<newData.attendance<<endl;
            }
                
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
}

void updateDataGender() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
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

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
                writeToReport << "\tUpdate gender with ID: "<<Employee.id <<"\t New gender: "<<newData.gender<<endl;
            }
                
            
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}

void updateDataDayOff() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee day off : ";
        cin >> newData.dayOff;
        
        Employee Employee;

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
                writeToReport << "\tUpdate day off with ID: "<<Employee.id <<"\t New day off: "<<newData.dayOff<<endl;
            }
               
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}

void updateDataSalary() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee salary : ";
        cin >> newData.salary;
        
        Employee Employee;
         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);
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
                writeToReport << "\tUpdate salary with ID: "<<Employee.id <<"\t New salary: "<<newData.salary<<endl;
            }
        
                
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}

void updateDataWorkHours() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee work hours : ";
        cin >> newData.workHours;
        
        Employee Employee;

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

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
                writeToReport << "\tUpdate work hours with ID: "<<Employee.id <<"\t New wourk hours: "<<newData.workHours<<endl;
            }
               
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}
