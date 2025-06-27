#include "SchoolSystem.h"
#include <iostream>

namespace harmony
{

    void SchoolSystem::run()
    {
        studentMgr.loadFromFile(studentFile);
        feeMgr.loadFromFile(feeFile);

        int choice;
        do
        {
            showMenu();
            std::cin >> choice;
            std::cin.ignore();
            handleChoice(choice);
        } while (choice != 11);

        studentMgr.saveToFile(studentFile);
        feeMgr.saveToFile(feeFile);
    }

    void SchoolSystem::showMenu()
    {
        // Prompt the user to enter the choice
        std::cout << "\n=== Naveen's Harmony Music School ===\n";
        std::cout << "1. Add Student\n2. View Students\n3. Add Fee Record\n4. View Fees Record\n";
        std::cout << "5. Add Purchase\n6. View Purchases\n7. Add Progress\n8. View Progress\n";
        std::cout << "9. Add Certification\n10. View Certifications\n11. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void SchoolSystem::handleChoice(int choice)
    {
        int id;
        switch (choice)
        {
        case 1:
            // Add the new student details
            studentMgr.addStudent();
            break;

        case 2:
            // Display all available student details
            studentMgr.displayAllStudents();
            break;
        case 3:
        {
            //Adding the Fee details for the student
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cin.ignore();

            // Check for student ID exist or not
            if (studentMgr.getStudentById(id))
            {
                feeMgr.addFee(id);
            }
            else
            {
                std::cout << "Student not found.\n";
            }
            break;
        }
        case 4:
            // Display all available student fees details
            feeMgr.displayAllFees();
            break;
            
        case 5:
            // Adding student purchase details
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (studentMgr.getStudentById(id))
                purchaseMgr.addPurchase(id);
            else
                std::cout << "Student not found\n";
            break;

        case 6:
             // Display all available student's purchase details
             purchaseMgr.displayAllPurchases();
            break;

        case 7:
             // Adding student learning progress details 
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (studentMgr.getStudentById(id))
                progressMgr.addProgress(id);
            else
                std::cout << "Student not found\n";
            break;

        case 8:
            // Display all available student's progress details
            progressMgr.displayAllProgress();
            break;

        case 9:
            // Adding student certification details
            std::cout << "Enter student ID: ";
            std::cin >> id;
            if (studentMgr.getStudentById(id))
                certMgr.addCertification(id);
            else
                std::cout << "Student not found\n";
            break;
        case 10:
            // Display all available student's certification details
            certMgr.displayAllCertifications();
            break;

        case 11:
            std::cout << "Saving all records of the student to persist file...\n";
            studentMgr.saveToFile(studentFile);
            feeMgr.saveToFile(feeFile);
            purchaseMgr.saveToFile(purchaseFile);
            progressMgr.saveToFile(progressFile);
            certMgr.saveToFile(certificationsFile);
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }
    }

}
