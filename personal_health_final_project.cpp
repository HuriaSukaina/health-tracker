#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===|| Personal Health Tracker ||===\n";
        cout << "1. Add Personal Information\n";
        cout << "2. View Personal Information\n";
        cout << "3. Add Health Record\n";
        cout << "4. View Health Records\n";
        cout << "5. Add Reminder\n";
        cout << "6. View Reminders\n";
        cout << "7. Daily Health Tracking\n";
        cout << "8. View Daily Health Tracking\n";
        cout << "9. Clear All Data\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // -------- Add Personal Info --------
        if (choice == 1)
        {
            string name, gender;
            int age;

            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;

            ofstream file("personal.txt", ios::app);
            file << name << endl
                 << age << endl
                 << gender << endl;
            file.close();

            cout << "Personal information saved.\n";
        }

        // -------- View Personal Info --------
        else if (choice == 2)
        {
            string name, gender;
            int age;

            ifstream file("personal.txt");
            if (!file)
            {
                cout << "No personal information found.\n";
            }
            else
            {
                cout << "\nPersonal Information:\n";
                cout << left << setw(20) << "Name" << setw(10) << "Age" << "Gender" << endl;
                while (getline(file, name))
                {
                    if (name.empty())
                        continue; // skip empty lines
                    if (file >> age >> gender)
                    {
                        file.ignore(); // ignore the newline after gender
                        cout << left << setw(20) << name << setw(10) << age << gender << endl;
                    }
                }
                file.close();
            }
        }

        // -------- Add Health Record --------
        else if (choice == 3)
        {
            string date;
            float temp;
            int hr, bp, sugar;

            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter temperature: ";
            cin >> temp;
            cout << "Enter heart rate: ";
            cin >> hr;
            cout << "Enter blood pressure: ";
            cin >> bp;
            cout << "Enter sugar level: ";
            cin >> sugar;

            ofstream file("health.txt", ios::app);
            file << date << " " << temp << " " << hr << " " << bp << " " << sugar << endl;
            file.close();

            cout << "Health record added.\n";
        }

        // -------- View Health Records --------
        else if (choice == 4)
        {
            string date;
            float temp;
            int hr, bp, sugar;

            ifstream file("health.txt");
            if (!file)
            {
                cout << "No health records found.\n";
            }
            else
            {
                cout << "\nHealth Records:\n";
                cout << left << setw(15) << "Date" << setw(12) << "Temperature" << "HR" << setw(10) << "BP" << "Sugar" << endl;

                while (file >> date >> temp >> hr >> bp >> sugar)
                {
                    cout << left << setw(15) << date << setw(12) << temp << setw(10) << hr << setw(10) << bp << sugar << endl;
                }
                file.close();
            }
        }

        // -------- Add Reminder --------
        else if (choice == 5)
        {
            string date, reminder;

            cout << "Enter reminder date: ";
            cin >> date;
            cin.ignore();
            cout << "Enter reminder text: ";
            getline(cin, reminder);

            ofstream file("reminders.txt", ios::app);
            file << date << " - " << reminder << endl;
            file.close();

            cout << "Reminder saved.\n";
        }

        // -------- View Reminders --------
        else if (choice == 6)
        {
            string line;
            ifstream file("reminders.txt");

            cout << "\nReminders List:\n";
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }

        // -------- Daily Health Tracking --------
        else if (choice == 7)
        {
            int days, water, steps, sleep;

            cout << "Enter number of days: ";
            cin >> days;

            ofstream file("healthtracking.txt", ios::app);
            for (int i = 1; i <= days; i++)
            {
                cout << "\nDay " << i << endl;
                cout << "Water intake (glasses): ";
                cin >> water;
                cout << "Steps walked: ";
                cin >> steps;
                cout << "Sleep hours: ";
                cin >> sleep;

                file << "Day " << i << " " << water << " " << steps << " " << sleep << endl;

                if (water < 8)
                    cout << "Reminder: Drink more water!\n";
                if (steps < 5000)
                    cout << "Reminder: Walk more!\n";
                if (sleep < 7)
                    cout << "Reminder: Get proper sleep!\n";
            }
            file.close();
            cout << "Daily health tracking data saved.\n";
        }

        // -------- View Daily Health Tracking --------
        else if (choice == 8)
        {
            string day;
            int dayNum, water, steps, sleep;

            ifstream file("healthtracking.txt");
            if (!file)
            {
                cout << "No daily health tracking data found.\n";
            }
            else
            {
                cout << "\nDaily Health Tracking:\n";
                cout << left << setw(10) << "Day" << setw(15) << "Water (glasses)" << setw(15) << "Steps" << "Sleep (hours)" << endl;

                while (file >> day >> dayNum >> water >> steps >> sleep)
                {
                    if (day == "Day")
                    {
                        cout << left << setw(10) << ("Day " + to_string(dayNum)) << setw(15) << water << setw(15) << steps << sleep << endl;
                    }
                }
                file.close();
            }
        }

        // -------- Clear All Data --------
        else if (choice == 9)
        {
            char confirm;
            cout << "Warning: This will delete all saved data (personal info, health records, reminders, and daily tracking data).\n";
            cout << "Are you sure? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                // Clear all data files
                ofstream file1("personal.txt", ios::trunc);
                file1.close();

                ofstream file2("health.txt", ios::trunc);
                file2.close();

                ofstream file3("reminders.txt", ios::trunc);
                file3.close();

                ofstream file4("healthtracking.txt", ios::trunc);
                file4.close();

                cout << "All data cleared successfully.\n";
            }
            else
            {
                cout << "Operation cancelled.\n";
            }
        }

        else if (choice == 10)
        {
            cout << "Program terminated.\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}