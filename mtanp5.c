/* -------------------------------------------------------------------------

Program file: mtanp5.c
Author: Melissa Tan
Date: July 26, 2020
Assignment: #5
Objective: This program allows users to make simple banking transactions,
such as deposits and withdrawals. It also displays the ending balance after all
transactions have been made.

-------------------------------------------------------------------------- */

#include <stdio.h>

float current_balance ()
{
	float balance_initial;
	char c;
	
	do
	{
		printf("\nEnter your current balance in dollars and cents: ");
		scanf("%f", &balance_initial);
		while ( (c = getchar() != '\n') && c != EOF);
		if (balance_initial < 0)
		{
			printf("\n*** Beginning balance must be at least zero, please re-enter.\n");
		}
	}while (balance_initial < 0);
	return balance_initial;
}

float deposit_amounts (float deposits[], int n_deposits)
{
	int x;
	float total_deposits;
	char c;
	
	for (x = 0; x < n_deposits; x++)
	{
 		printf ("Deposits #%i: ", x + 1);
 		scanf ("%f", &deposits[x]);
 		while ( (c = getchar() != '\n') && c != EOF);
		if (deposits[x] < 0)
		{
			printf("Deposit must be greater than zero, please re-enter.\n");
			x = x - 1;
			continue;
		}
		total_deposits += deposits[x];
	}
	return total_deposits;
}

void main ()
{	
	int x, n_deposits = 0, n_withdrawals = 0;
	float balance_ending = 0, opening_balance, balance_initial, obtain_deposits, total_withdrawals = 0, deposits[5], withdrawals[5]; 
	char c; 
	
	/* Output initial greeting. */
	/* ------------------------ */

	printf ("Welcome to the Computer Banking System\n");

	/* Prompt user for current balance. */
	/* -------------------------------- */
	
	opening_balance = current_balance (balance_initial);
		
	/* Prompt user for number of deposits. */
	/* ----------------------------------- */
	
	do
	{
		printf("\nEnter the number of deposits (0 - 5): ");
		scanf("%i", &n_deposits);
		while ( (c = getchar() != '\n') && c != EOF);
		if (n_deposits < 0 || n_deposits > 5)
		{
			printf("*** Invalid number of deposits, please re-enter.\n");
		}
	}while (n_deposits < 0 || n_deposits > 5);
	
	/* Obtain deposit amounts. */
	/* ----------------------- */
	
	obtain_deposits = deposit_amounts (deposits, n_deposits);

	/* Prompt user for number of withdrawals. */
	/* -------------------------------------- */

	do
	{
		printf("\nEnter the number of withdrawals (0 - 5): ");
		scanf("%i", &n_withdrawals);
		while ( (c = getchar() != '\n') && c != EOF);
		if (n_withdrawals < 0 || n_withdrawals > 5)
		{
			printf("*** Invalid number of withdrawals, please re-enter.\n");
		}
	}while (n_withdrawals < 0 || n_withdrawals > 5);
	
	/* Obtain withdrawal amounts. */
	/* -------------------------- */

	for (x = 0; x < n_withdrawals; x++)
	{
 		printf ("Withdrawal #%i: ", x + 1);
 		scanf ("%f", &withdrawals[x]);
 		while ( (c = getchar() != '\n') && c != EOF);
		total_withdrawals += withdrawals[x];
	 	if (opening_balance + obtain_deposits - total_withdrawals < 0)
		{
			printf("Withdrawal amount exceeds current balance, please re-enter.\n");
			total_withdrawals = total_withdrawals - withdrawals[x];
			x = x - 1;
			continue;
		}
	}
 	
	/* Output record of transaction. */
	/* ------------------------------*/

 	printf ("\n\n*** Bank Record ***\n\nStarting balance: %.2f\n", opening_balance);

	for (x = 0; x < n_deposits; x++)
	{
 		printf ("\nDeposit #%i: %.2f", x + 1, deposits[x]);
	}
	
	for (x = 0; x < n_withdrawals; x++)
	{
 		printf ("\nWithdrawal #%i: %.2f", x + 1, withdrawals[x]);
	}
	
	balance_ending = opening_balance - total_withdrawals + obtain_deposits;
	 
 	printf ("\n\nEnding balance: %.2f\n", balance_ending);
	 
	/* Pause output. */
	/* ------------- */
	
 	getchar();
 
 	return 0;

}
