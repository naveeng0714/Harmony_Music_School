#pragma once
#include "FeeRecord.h"
#include <unordered_map>
#include <string>
#include <filesystem>

namespace harmony
{

    class FeeManager
    {
    private:
        std::unordered_map<int, FeeRecord> fees;

    public:
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;

        void addFee(int studentId);
        void displayAllFees() const;
        const FeeRecord *getFee(int studentId) const;
    };

}
