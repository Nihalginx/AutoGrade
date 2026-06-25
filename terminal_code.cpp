#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

// Structure for Student Record
struct Student
{
    int studentID;
    float attendance;
    float unitTestMarks;
    float mockPracticalMarks;
    string achievements;
    float finalTermWork;

    Student* next;
};

// Hash Table
Student* hashTable[TABLE_SIZE];

// Initialize Hash Table
void initializeTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

// Hash Function
int hashFunction(int studentID)
{
    return studentID % TABLE_SIZE;
}

// Calculate Final Term Work Score
float calculateTermWork(float attendance, float unitTest, float mockPractical)
{
    return (attendance * 0.2) +
           (unitTest * 0.4) +
           (mockPractical * 0.4);
}

// Add Student Record
void addStudent()
{
    Student* newStudent = new Student();

    cout << "\nEnter Student ID: ";
    cin >> newStudent->studentID;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input!\n";
        delete newStudent;
        return;
    }

    int index = hashFunction(newStudent->studentID);

    // Check duplicate ID
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->studentID == newStudent->studentID)
        {
            cout << "Student ID already exists!\n";
            delete newStudent;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Attendance Percentage: ";
    cin >> newStudent->attendance;

    cout << "Enter Unit Test / Prelim Marks: ";
    cin >> newStudent->unitTestMarks;

    cout << "Enter Mock Practical Marks: ";
    cin >> newStudent->mockPracticalMarks;

    cin.ignore();

    cout << "Enter Achievements: ";
    getline(cin, newStudent->achievements);

    // Calculate Final Term Work Score
    newStudent->finalTermWork = calculateTermWork(
        newStudent->attendance,
        newStudent->unitTestMarks,
        newStudent->mockPracticalMarks
    );

    newStudent->next = NULL;

    // Insert using Chaining
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newStudent;
    }
    else
    {
        Student* ptr = hashTable[index];

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newStudent;
    }

    cout << "Student Record Added Successfully!\n";
}

// Search Student
void searchStudent()
{
    int id;

    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    int index = hashFunction(id);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->studentID == id)
        {
            cout << "\nStudent Found!\n";

            cout << "-----------------------------------\n";
            cout << "Student ID          : " << temp->studentID << endl;
            cout << "Attendance          : " << temp->attendance << "%" << endl;
            cout << "Unit Test Marks     : " << temp->unitTestMarks << endl;
            cout << "Mock Practical      : " << temp->mockPracticalMarks << endl;
            cout << "Achievements        : " << temp->achievements << endl;
            cout << "Final Term Work     : " << temp->finalTermWork << endl;
            cout << "-----------------------------------\n";

            return;
        }

        temp = temp->next;
    }

    cout << "Student Record Not Found!\n";
}

// Update Student Record
void updateStudent()
{
    int id;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    int index = hashFunction(id);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->studentID == id)
        {
            cout << "Enter New Attendance Percentage: ";
            cin >> temp->attendance;

            cout << "Enter New Unit Test Marks: ";
            cin >> temp->unitTestMarks;

            cout << "Enter New Mock Practical Marks: ";
            cin >> temp->mockPracticalMarks;

            cin.ignore();

            cout << "Enter New Achievements: ";
            getline(cin, temp->achievements);

            temp->finalTermWork = calculateTermWork(
                temp->attendance,
                temp->unitTestMarks,
                temp->mockPracticalMarks
            );

            cout << "Record Updated Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Student Record Not Found!\n";
}

// Delete Student Record
void deleteStudent()
{
    int id;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    int index = hashFunction(id);

    Student* temp = hashTable[index];
    Student* prev = NULL;

    while (temp != NULL)
    {
        if (temp->studentID == id)
        {
            if (prev == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;

            cout << "Student Record Deleted Successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Student Record Not Found!\n";
}

// Display All Records in Ranking Format
void displayRecords()
{
    Student* allStudents[100];
    int count = 0;

    // Collect all students
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Student* temp = hashTable[i];

        while (temp != NULL)
        {
            allStudents[count++] = temp;
            temp = temp->next;
        }
    }

    if (count == 0)
    {
        cout << "\nNo Records Available!\n";
        return;
    }

    // Sort by Final Term Work Score (Descending)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (allStudents[i]->finalTermWork < allStudents[j]->finalTermWork)
            {
                Student* temp = allStudents[i];
                allStudents[i] = allStudents[j];
                allStudents[j] = temp;
            }
        }
    }

    cout << "\n=========== STUDENT RANKING ===========\n";

    cout << left
         << setw(8)  << "Rank"
         << setw(12) << "ID"
         << setw(15) << "Attendance"
         << setw(15) << "UT Marks"
         << setw(18) << "Mock Practical"
         << setw(15) << "TW Score"
         << endl;

    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
             << setw(8)  << i + 1
             << setw(12) << allStudents[i]->studentID
             << setw(15) << allStudents[i]->attendance
             << setw(15) << allStudents[i]->unitTestMarks
             << setw(18) << allStudents[i]->mockPracticalMarks
             << setw(15) << allStudents[i]->finalTermWork
             << endl;
    }
}

// Main Function
int main()
{
    int choice;

    initializeTable();

    do
    {
        cout << "\n=====================================\n";
        cout << " AUTOMATED TERM WORK ASSESSMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Add Student Record\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Display All Records (Ranking)\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                displayRecords();
                break;

            case 6:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}