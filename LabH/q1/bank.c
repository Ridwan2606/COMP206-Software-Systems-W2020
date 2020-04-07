//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include <stdio.h>
#include <stdlib.h>

struct BANK_ACCOUNT {
    char type; // ‘S’=savings, ‘C’=checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge; // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};


void print_acc(struct BANK_ACCOUNT acc){
    printf("Account of type %c holding: %.2f $", acc.type, acc.balance);
	if (acc.type == 'C') {
		printf(" with a credit score of %d \n", acc.specific.credit_score);
	} else if (acc.type == 'S') {
		printf(" with a charge of %.2f $ \n", acc.specific.charge);
	}
}


