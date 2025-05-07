//Muhammad Anas (SP25-BSE-078) Section C
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> students, REGnumbers, Degree, Degreecompleted, ObtainedMarks, TotalMarks;
    int choice;

    do {
        cout << "\nMenu\n";
        cout << "1. Add New Student Record\n";
        cout << "2. Show All Records\n";
        cout << "3. Delete a Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
        string name, rollno, degree, degreecompleted, obtainedmarks, totalmarks;
        cout << "\nAdding Students' Records (type 'exit' as name to stop)\n";
        while (true) {
        cout << "\nEnter student name: ";
        getline(cin, name);
        if (name == "exit") break;

        cout << "Enter registration number: ";
        getline(cin, rollno);
        cout << "Enter degree: ";
        getline(cin, degree);
        cout << "Has the degree been completed? (Yes/No): ";
        getline(cin, degreecompleted);
        cout << "Enter obtained marks: ";
        getline(cin, obtainedmarks);
        cout << "Enter total marks: ";
        getline(cin, totalmarks);

            
        students.push_back(name);          
        REGnumbers.push_back(rollno);
        Degree.push_back(degree);
        Degreecompleted.push_back(degreecompleted);
        ObtainedMarks.push_back(obtainedmarks);
        TotalMarks.push_back(totalmarks);
        }
        break;
        }

        case 2: {
        if (students.empty()) {
        cout << "\nNo records to display.\n";
        } else {
        cout << "\nShowing all student records:\n";
        cout << "--------------------------------------------------------------------------------------\n";
        cout << "Name\t\tReg No\t\tDegree\tCompleted\tObtained\tTotal\n";
        cout << "--------------------------------------------------------------------------------------\n";
        for (size_t i = 0; i < students.size(); i++) {
        cout << students[i] << "\t"
        << REGnumbers[i] << "\t"
        << Degree[i] << "\t\t"
        << Degreecompleted[i] << "\t\t"
        << ObtainedMarks[i] << "\t\t"
        << TotalMarks[i] << "\n";
        }
    }
        break;
    }

        case 3: {
        if (students.empty()) {
        cout << "\nNo records available to delete.\n";
        } else {
        string regToDelete;
        cout << "\nEnter registration number of student to delete: ";
        getline(cin, regToDelete);
        bool found = false;
        for (size_t i = 0; i < REGnumbers.size(); i++) {
        if (REGnumbers[i] == regToDelete) {
        students.erase(students.begin() + i);
        REGnumbers.erase(REGnumbers.begin() + i);
        Degree.erase(Degree.begin() + i);
        Degreecompleted.erase(Degreecompleted.begin() + i);
        ObtainedMarks.erase(ObtainedMarks.begin() + i);
        TotalMarks.erase(TotalMarks.begin() + i);
        cout << "Record deleted successfully.\n";
        found = true;
        break;
        }
    }
        if (!found) {
        cout << "No record found with that registration number.\n";
        }
    }
        break;
    }

        case 4:
        cout << "Exiting the program...\n";
        break;

        default:
        cout << "Invalid choice! Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
