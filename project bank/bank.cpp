#include <stdio.h>

struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};

void createAccount(struct BankAccount accounts[], int *numAccounts) {
    if (*numAccounts >= 100) {
        printf("Cannot create more accounts.\n");
        return;
    }
    
    struct BankAccount newAccount;
    
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    
    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;
    
    printf("Account created successfully.\n");
}

void deposit(struct BankAccount accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    int accountIndex = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }
    
    if (accountIndex == -1) {
        printf("Account not found.\n");
        return;
    }
    
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    
    accounts[accountIndex].balance += amount;
    
    printf("Deposit successful.\n");
}

void withdraw(struct BankAccount accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    int accountIndex = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }
    
    if (accountIndex == -1) {
        printf("Account not found.\n");
        return;
    }
    
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    if (accounts[accountIndex].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    
    accounts[accountIndex].balance -= amount;
    
    printf("Withdrawal successful.\n");
}

void checkBalance(struct BankAccount accounts[], int numAccounts) {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    int accountIndex = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }
    
    if (accountIndex == -1) {
        printf("Account not found.\n");
        return;
    }
    
    printf("Account holder: %s\n", accounts[accountIndex].accountHolder);
    printf("Balance: %.2f\n", accounts[accountIndex].balance);
}

int main() {
    struct BankAccount accounts[100];
    int numAccounts = 0;
    int choice;
    
    do {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

