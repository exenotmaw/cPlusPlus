#include <iostream>
#include<string>

using namespace std;

int userCount = 0;

string userArray[99] = {};
string fullArray[99] = {};
string passArray[99] = {};

string userName = "";
string fullName = "";
string passWord = "";

int depositArray[99][99] = {};
int depositMoney = 0;
int depositCount = 0;

int withdrawArray[99][99] = {};
int withdrawMoney = 0;
int withdrawCount = 0;

int sumBalance = 0;
int currentBalance = 0;
int minusBalance = 0;

int periodTime = 0;
int amount = 0;
int interestRate = 0;


bool check(string userName, int count) {
    for (int i = 0; i < count; i++) {
        if (userName == userArray[i]) {
            return true;
        }
    }
    return false;
}


void signUp() {
    system("cls");

    cout << "JAMOYO TIPIDSKI REGISTER" << endl;
    cout << endl << "Enter Full Name: ";
    getline(cin, fullName);
    cout << endl << "Enter Username: ";
    getline(cin, userName);
    cout << endl << "Enter Password: ";
    getline(cin, passWord);

    if (check(userName, userCount)) {
        cout << endl << "Username Already Exist" << endl << endl;
    }
    else {
        userArray[userCount] = userName;
        fullArray[userCount] = fullName;
        passArray[userCount] = passWord;
        userCount++;
        cout << endl << "Account Succesful Registered" << endl << endl;
    }
}

void depositTab(int i) {
    system("cls");

    cout << "JAMOYO TIPIDSKI INCOME MONEY" << endl;

    cout << endl << "Enter the amount of Income: ";
    cin >> depositMoney;
    cin.ignore();

    if (depositMoney >= 1) {
        depositArray[i][depositCount] = depositMoney;
        depositCount++;
        cout << endl << "Transaction Completed" << endl << endl;
    }
    else {
        cout << endl << "Invalid amount" << endl << endl;
    }
}

void depositHistory(int i) {
    system("cls");

    cout << "JAMOYO TIPIDSKI INCOME HISTORY" << endl;

    for (int j = 0; j < depositCount; j++) {
        if (depositArray[i][j] == 0) {
            continue;
        }
        else {
            cout << endl <<depositArray[i][j] << endl;
        }
        
    }
}

int viewBalance(int i) {
    system("cls");

    sumBalance = 0;
    minusBalance = 0;

    cout << "JAMOYO TIPIDSKI BALANCE TAB" << endl << endl;

    for (int j = 0; j < depositCount; j++) {
        sumBalance = sumBalance + depositArray[i][j];
    }

    for (int j = 0; j < withdrawCount; j++) {
        minusBalance = minusBalance + withdrawArray[i][j];
    }

    currentBalance = sumBalance - minusBalance;

    cout << "Current Balance: " << currentBalance << endl << endl;

    return currentBalance;
}

void withdrawTab(int i) {
    system("cls");

    sumBalance = 0;
    minusBalance = 0;

    for (int j = 0; j < depositCount; j++) {
        sumBalance = sumBalance + depositArray[i][j];
    }

    for (int j = 0; j < withdrawCount; j++) {
        minusBalance = minusBalance + withdrawArray[i][j];
    }

    currentBalance = sumBalance - minusBalance;

    cout << "JAMOYO TIPIDSKI EXPENSES TAB" << endl << endl;

    cout << endl << "Enter the amount of Expenses: ";
    cin >> withdrawMoney;
    cin.ignore();

    if (withdrawMoney < currentBalance) {
        withdrawArray[i][withdrawCount] = withdrawMoney;
        withdrawCount++;
        cout << endl << "Transaction Completed" << endl << endl;
    }
    else {
        cout << endl << "Insuficient amount" << endl << endl;
    }
}

void withdrawHistory(int i){
    system("cls");

    cout << "JAMOYO TIPIDSKI EXPENSES HISTORY" << endl;

    for (int j = 0; j < withdrawCount; j++) {
        if (withdrawArray[i][j] == 0) {
            continue;
        }
        else {
            cout << endl << withdrawArray[i][j] << endl;
        }

    }
}

void interestR(int i) {
    system("cls");

    sumBalance = 0;
    minusBalance = 0;

    cout << "JAMOYO TIPIDSKI INTEREST RATE" << endl;

    for (int j = 0; j < depositCount; j++) {
        sumBalance = sumBalance + depositArray[i][j];
    }

    for (int j = 0; j < withdrawCount; j++) {
        minusBalance = minusBalance + withdrawArray[i][j];
    }

    currentBalance = sumBalance - minusBalance;

    if (currentBalance >= 1) {
        cout << endl << "You have a balance of: $ " << currentBalance << endl;

        cout << endl << "Enter the Interest rate: ";
        cin >> interestRate;
        cout << endl << "Enter the period of years: ";
        cin >> periodTime;

        amount = currentBalance * (1 + interestRate / 100, periodTime);
        cout << endl << "The total savings in the span of " << periodTime << " years with interest of " << interestRate << " are : $ " << amount << endl;
    }
    else {
        cout << endl << "You don't have enough balance" << endl;
    }

}

void logIn() {
    int option = 0;
    system("cls");

    cout << "JAMOYO TIPIDSKI LOG IN TAB" << endl;

    if (userCount >= 1) {
        
        cout << endl << "Enter your Username: ";
        getline(cin, userName);
        cout << endl << "Enter your Password: ";
        getline(cin, passWord);

        
        for (int i = 0; i < userCount; i++) {
            do{
                if (userName == userArray[i] && passWord == passArray[i]) {
                    system("cls");
                    cout << "WELCOME " << fullArray[i] << " TO YOUR ACCOUNT" << endl;
                    cout << endl << "[1] View Balance" << endl;
                    cout << endl << "[2] Show Income History" << endl;
                    cout << endl << "[3] Show Expenses History" << endl;
                    cout << endl << "[4] Income Money" << endl;
                    cout << endl << "[5] Expenses Balance" << endl;
                    cout << endl << "[6] Show Interest Rate" << endl;
                    cout << endl << "[7] Log Out" << endl;
                    cout << endl << "Input: ";
                    cin >> option;
                    cin.ignore();
                    if (option == 1) {
                        viewBalance(i);
                    }
                    else if (option == 2) {
                        depositHistory(i);
                    }
                    else if (option == 3) {
                        withdrawHistory(i);
                    }
                    else if (option == 4) {
                        depositTab(i);
                    }
                    else if (option == 5) {
                        withdrawTab(i);
                    }
                    else if (option == 6) {
                        interestR(i);
                    }
                    else if (option == 7) {
                        cout << endl << "Log Outing." << endl;
                        break;
                    }
                    else {
                        cout << endl << "Invalid Input, Please Try Again." << endl;
                        break;
                    }
                }
                else {
                    cout << endl << "Invalid Username or Password." << endl << endl;
                    break;
                }
                system("pause");
            } while (option != 7);
        }
    }
    else {
        cout << endl << "No account currently existing. Register First." << endl << endl;
    }
}

int main()
{
    int choice = 0;
    do{
        system("cls");
        cout << "JAMOYO TIPIDSKI" << endl;
        cout << endl << "[1] Register User" << endl;
        cout << endl << "[2] Log In User" << endl;
        cout << endl << "[3] Exit" << endl;
        cout << endl << "Input : ";
        cin >> choice;
        cin.ignore();
    
        if (choice == 1) {
            signUp();
        }
        else if (choice == 2) {
            logIn();
        }
        else if (choice == 3) {
            cout << endl << "Thank you for using the Jamoyo TipidSki." << endl;
            return 0;
        }
        else {
            cout << endl << "Invalid Input, Please Try Again." << endl;
        }
        system("pause");
    } while (choice != 3);
}