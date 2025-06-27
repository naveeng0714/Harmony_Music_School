#include "FeeRecord.h"
#include <sstream>

namespace harmony
{

    FeeRecord::FeeRecord(int id, double total, double paid)
        : studentId(id), totalFee(total), paidAmount(paid) {}

    void FeeRecord::input(int id)
    {
        studentId = id;
        std::cout << "Enter total fee for student ID " << id << ": ";
        std::cin >> totalFee;
        std::cout << "Enter amount paid: ";
        std::cin >> paidAmount;
        std::cin.ignore();
    }

    void FeeRecord::display() const
    {
        std::cout << "Student ID: " << studentId
                  << "\nTotal Fee: " << totalFee
                  << "\nAmount Paid: " << paidAmount
                  << "\nBalance: " << getBalance() << "\n";
    }

    std::string FeeRecord::toCSV() const
    {
        return std::to_string(studentId) + "," + std::to_string(totalFee) + "," + std::to_string(paidAmount);
    }

    FeeRecord FeeRecord::fromCSV(const std::string &line)
    {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        int id = std::stoi(token);
        std::getline(ss, token, ',');
        double total = std::stod(token);
        std::getline(ss, token, ',');
        double paid = std::stod(token);

        return FeeRecord(id, total, paid);
    }

}
