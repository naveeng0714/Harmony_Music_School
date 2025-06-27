/*
#include <iostream>
#include "StudentManager.h"
#include "FeeManager.h"
#include "PurchaseManager.h"
#include "ProgressManager.h"
#include "CertificationManager.h"

int main()
{
    StudentManager sm;
    FeeManager fm;
    PurchaseManager pm;
    ProgressManager progm;
    CertificationManager cm;

    int choice;
    do
    {
        // Prompt the user to enter the choice
        std::cout << "\n=== Naveen's Harmony Music School ===\n";
        std::cout << "1. Add Student\n2. View Students\n3. Add Fee\n4. View Fees\n";
        std::cout << "5. Add Purchase\n6. View Purchases\n7. Add Progress\n8. View Progress\n";
        std::cout << "9. Add Certification\n10. View Certifications\n11. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        int id;
        switch (choice)
        {
        case 1:
            // Add the new student details
            sm.addStudent();
            break;
        case 2:
            // Display all available student details
            sm.displayAll();
            break;
        case 3:
            //Adding the Fee details for the student
            std::cout << "Enter student ID: ";
            std::cin >> id;

            // Check for student ID exist or not
            if (sm.getStudent(id))
                fm.addFee(id);
            else
                std::cout << "Student not found\n";
            break;
        case 4:
            fm.displayAll();
            break;
        case 5:
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (sm.getStudent(id))
                pm.addPurchase(id);
            else
                std::cout << "Student not found\n";
            break;
        case 6:
            pm.displayAll();
            break;
        case 7:
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (sm.getStudent(id))
                progm.addProgress(id);
            else
                std::cout << "Student not found\n";
            break;
        case 8:
            progm.displayAll();
            break;
        case 9:
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (sm.getStudent(id))
                cm.addCertification(id);
            else
                std::cout << "Student not found\n";
            break;
        case 10:
            cm.displayAll();
            break;
        case 11:
            sm.save();
            fm.save();
            pm.save();
            progm.save();
            cm.save();
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    } while (choice != 11);

    return 0;
}
*/

#include "SchoolSystem.h"

int main() {
    harmony::SchoolSystem app;
    app.run();
    return 0;
}
