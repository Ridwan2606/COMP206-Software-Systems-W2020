//Author: Joseph Vybihal & Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>

struct BANK_ACCOUNT {
	char type; // 'S'=savings, 'C'=checking
	double balance;

	union ACCOUNT_SPECIFIC {
		double charge; // for withdrawal from savings accounts
		int credit_score; //for checking account
	} specific;
};


int main(int argc, char *argv[]) {
	int nextSpot = 0;
	int newAccounts;

	printf("How many accounts are being created:"); 
	scanf("%d", &newAccounts);
	
	/* Note that in the following line of code
	 we are reserving as much space for the bank accounts
	 as we need using calloc & specifying the number of accounts in
	 the newAccounts variable. If the user inputs 50, 
	 enough space for 50 Struct BANK_ACCOUNT will be reserved. 

	 In contrary to the previous example in bank.c , we use
	 an array of struct BANK_ACCOUNT of arbitrary size 100 is used. This
	 implies that if the user was to create only 5 accounts, we've effectively
	 wasted 95 cells in the array. Or if the user wanted to create >100 accounts,
	 this would cause an error. 
	 
	 In this aspect, dynamic memory allocation (calloc or malloc) is more flexible.
	 )
	 */
	struct BANK_ACCOUNT* accounts = (struct BANK_ACCOUNT*) calloc(newAccounts, sizeof(struct BANK_ACCOUNT));
	
	for (int i =0; i < newAccounts; i++) {

		printf("What is the type of the account ('C'/'S') ");
		
		// Note that instead of the pointer notation, you could have used
		// &accounts[nextSpot].type
		scanf(" %c", &(accounts+nextSpot)->type);
		printf("How much money does the account hold: ");
		
		scanf("%lf", &(accounts+nextSpot)->balance);
		
		if ((accounts+nextSpot)->type == 'C') {
			printf("What is the account credit score: ");
			scanf(" %d", &(accounts+nextSpot)->specific.credit_score);
		} else if ((accounts+nextSpot)->type == 'S') {
			printf("What is the charge on the account: ");
			scanf("%lf", &(accounts+nextSpot)->specific.charge);
		}
		nextSpot++;
		printf(" - Account Created - \n");
	}
	
	printf(" --- Displaying Accounts --- \n");

	for(int j = 0; j < nextSpot; j++) {
		printf("Account #%d of type %c holding: %.2f $", j, (accounts+j)->type, (accounts+j)->balance);
		if ((accounts+j)->type == 'C') {
			printf(" with a credit score of %d \n", (accounts+j)->specific.credit_score);
		} else if ((accounts+j)->type == 'S') {
			printf(" with a charge of %.2f $ \n", (accounts+j)->specific.charge);
		}
	}

	// Do not forget to free every objects created using malloc/calloc
	// to prevent memory leak. There's no garbage collector in C unlike Java.
	// You manually have to do the garbage collecting using free()
    free(accounts);
	return 0;
}

