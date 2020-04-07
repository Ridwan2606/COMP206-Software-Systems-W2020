//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include <stdio.h>
#include <stdlib.h>
#include"bank.h"
/*
struct BANK_ACCOUNT {
    char type; // ‘S’=savings, ‘C’=checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge; // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};

void print_acc(struct BANK_ACCOUNT acc);
*/

int main(int argc, char *argv[]) {

	struct BANK_ACCOUNT accounts[100];

	int nextSpot = 0;
	int newAccounts;

	printf("How many accounts are being created:"); 
	scanf("%d", &newAccounts);
	
	for (int i =0; i < newAccounts; i++) {

		printf("What is the type of the account ('C'/'S') ");
		
		scanf(" %c", &accounts[nextSpot].type);
		printf("How much money does the account hold: ");
		
		scanf("%lf", &accounts[nextSpot].balance);
		
		if (accounts[nextSpot].type == 'C') {
			printf("What is the account credit score: ");
			scanf(" %d", &accounts[nextSpot].specific.credit_score);
		} else if (accounts[nextSpot].type == 'S') {
			printf("What is the charge on the account: ");
			scanf("%lf", &accounts[nextSpot].specific.charge);
		}
		nextSpot++;
		printf(" - Account Created - \n");
	}
	
	printf(" --- Displaying Accounts --- \n");

	for(int j = 0; j < nextSpot; j++) {
		printf("%d.) ", j+1);
		print_acc(accounts[j]);
	}


	return 0;
}

