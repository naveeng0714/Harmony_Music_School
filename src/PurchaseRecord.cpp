#include "PurchaseRecord.h"
#include <sstream>
#include <vector>

namespace harmony
{

    PurchaseRecord::PurchaseRecord(int sid, const std::string &type, const std::string &name, double pr, const std::string &dt)
        : studentId(sid), itemType(type), itemName(name), price(pr), date(dt) {}

    void PurchaseRecord::input(int sid)
    {
        studentId = sid;
        std::cout << "Enter item type (Instrument/Accessory): ";
        std::getline(std::cin, itemType);
        std::cout << "Enter item name: ";
        std::getline(std::cin, itemName);
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cin.ignore();
        std::cout << "Enter purchase date (YYYY-MM-DD): ";
        std::getline(std::cin, date);
    }

    void PurchaseRecord::display() const
    {
        std::cout << "Student ID: " << studentId
                  << "\nItem Type: " << itemType
                  << "\nItem Name: " << itemName
                  << "\nPrice: " << price
                  << "\nPurchase Date: " << date << "\n";
    }

    std::string PurchaseRecord::toCSV() const
    {
        return std::to_string(studentId) + "," + itemType + "," + itemName + "," + std::to_string(price) + "," + date;
    }

    PurchaseRecord PurchaseRecord::fromCSV(const std::string &line)
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 5)
            throw std::runtime_error("Invalid purchase record");

        return PurchaseRecord(std::stoi(tokens[0]), tokens[1], tokens[2], std::stod(tokens[3]), tokens[4]);
    }

}
