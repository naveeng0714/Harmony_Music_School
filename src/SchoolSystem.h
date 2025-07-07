#pragma once
#include "StudentManager.h"
#include "FeeManager.h"
#include "PurchaseManager.h"
#include "ProgressManager.h"
#include "CertificationManager.h"
#include <string>

namespace harmony
{

    class SchoolSystem
    {
    private:
        StudentManager studentMgr;
        FeeManager feeMgr;
        PurchaseManager purchaseMgr;
        ProgressManager progressMgr;
        CertificationManager certMgr;

        const std::string studentFile = "../data/students.txt";
        const std::string feeFile = "../data/fees.txt";
        const std::string purchaseFile = "../data/purchases.txt";
        const std::string progressFile = "../data/progress.txt";
        const std::string certificationsFile = "../data/certifications.txt";

        void showMenu();
        void handleChoice(int choice);

    public:
        void run();
    };

}
