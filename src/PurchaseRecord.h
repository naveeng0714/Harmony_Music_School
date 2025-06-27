#pragma once
#include <string>
#include <iostream>

namespace harmony
{

    class PurchaseRecord
    {
    private:
        int studentId;
        std::string itemType; // "Instrument" or "Accessory"
        std::string itemName;
        double price;
        std::string date;

    public:
        PurchaseRecord() = default;
        PurchaseRecord(int sid, const std::string &type, const std::string &name, double pr, const std::string &dt);

        void input(int sid);
        void display() const;

        std::string toCSV() const;
        static PurchaseRecord fromCSV(const std::string &line);

        int getStudentId() const { return studentId; }
    };

}
