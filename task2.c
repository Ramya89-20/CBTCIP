#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100
#define ACCOUNT_NAME_LENGTH 50
#define SAVINGS_INTEREST_RATE 0.03
#define CHECKING_INTEREST_RATE 0.01

typedef struct{
    int accountNumber;
    char accountHolderName[ACCOUNT_NAME_LENGTH];
    double balance;
    char accountType[10];
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts=0;
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void Interest();
void displayMenu();
int main() {
    printf("\n---------------------------------------- Bank Account Management System ----------------------------------------\n");
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: Interest(); break;
            case 6: printf("Thanks for using.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
void displayMenu() {
    printf("\n\n");
    printf("1. Create Account\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Funds\n");
    printf("4. Check Balance\n");
    printf("5. Calculate Interest\n");
    printf("6. Exit\n");
}
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber=numAccounts+1;
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolderName);
    printf("Enter account type (savings/checking): ");
    scanf("%s", newAccount.accountType);
    newAccount.balance = 0.0;
    accounts[numAccounts++] = newAccount;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}
void deposit() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    accounts[accountNumber - 1].balance += amount;
    printf("Amount deposited successfully. New balance: %.2f\n", accounts[accountNumber - 1].balance);
}
void withdraw() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[accountNumber - 1].balance);
}
void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Account Number: %d\n", accountNumber);
    printf("Account Holder: %s\n", accounts[accountNumber - 1].accountHolderName);
    printf("Account Type: %s\n", accounts[accountNumber - 1].accountType);
    printf("Balance: %.2f\n", accounts[accountNumber - 1].balance);
}
void Interest() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > numAccounts) {
        printf("Invalid account number.\n");
        return;
    }
    double interestRate = 0.0;
    if (strcmp(accounts[accountNumber - 1].accountType, "savings") == 0) {
        interestRate = SAVINGS_INTEREST_RATE;
    } else if (strcmp(accounts[accountNumber - 1].accountType, "checking") == 0) {
        interestRate = CHECKING_INTEREST_RATE;
    } else {
        printf("Unknown account type.\n");
        return;
    }
    double interest = accounts[accountNumber - 1].balance * interestRate;
    printf("Interest for account number %d: %.2f\n", accountNumber, interest);
}