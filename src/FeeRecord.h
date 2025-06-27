#pragma once
#include <string>
#include <iostream>

namespace harmony
{

    class FeeRecord
    {
    private:
        int studentId;
        double totalFee = 0.0;
        double paidAmount = 0.0;

    public:
        FeeRecord() = default;
        FeeRecord(int id, double total, double paid);

        void input(int id);
        void display() const;

        std::string toCSV() const;
        static FeeRecord fromCSV(const std::string &line);

        int getStudentId() const { return studentId; }
        double getBalance() const { return totalFee - paidAmount; }
    };

}
