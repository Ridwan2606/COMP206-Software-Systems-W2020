//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

struct BANK_ACCOUNT {
    char type; // ‘S’=savings, ‘C’=checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge; // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};


void print_acc(struct BANK_ACCOUNT acc);
