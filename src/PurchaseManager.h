#pragma once
#include "PurchaseRecord.h"
#include <vector>
#include <filesystem>

namespace harmony
{

    class PurchaseManager
    {
    private:
        std::vector<PurchaseRecord> purchases;

    public:
        void loadFromFile(const std::string &filename);
        void saveToFile(const std::string &filename) const;

        void addPurchase(int studentId);
        void displayAllPurchases() const;
    };

}
