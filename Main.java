import java.util.Scanner;
class BankAccount {
private int accountNumber;
private double balance;
private double dailyWithdrawalLimit;
private double dailyWithdrawnAmount;
public BankAccount(int accountNumber, double initialBalance, double dailyWithdrawalLimit) { this.accountNumber = accountNumber;
this.balance = initialBalance;
this.dailyWithdrawalLimit = dailyWithdrawalLimit;
this.dailyWithdrawnAmount = 0;
}
public void deposit(double amount) {
balance += amount;
System.out.println(amount + " deposited successfully.");
}
public void withdraw(double amount) {
if (amount <= balance && amount <= (dailyWithdrawalLimit - dailyWithdrawnAmount)) { balance -= amount;
dailyWithdrawnAmount += amount;
System.out.println(amount + " withdrawn successfully.");
} else {
System.out.println("Withdrawal failed. Insufficient funds or daily limit reached."); }
}
public double checkBalance() {
return balance;
}
public void displayAccountInfo() {
System.out.println("Account Number: " + accountNumber);
System.out.println("Balance: " + balance);
}
}
class Main {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter Account Number: ");
int accountNumber = scanner.nextInt();
System.out.print("Enter Initial Balance: ");
double initialBalance = scanner.nextDouble();
System.out.print("Enter Daily Withdrawal Limit: ");
double dailyWithdrawalLimit = scanner.nextDouble();
BankAccount account = new BankAccount(accountNumber, initialBalance, dailyWithdrawalLimit);
int choice;
do {
System.out.println("\nChoose an option:");
System.out.println("1. Deposit");
System.out.println("2. Withdraw");
System.out.println("3. Check Balance");
System.out.println("4. Display Account Information");
System.out.println("0. Exit");
System.out.print("Enter your choice: ");
choice = scanner.nextInt();
switch (choice) {
case 1:
System.out.print("Enter deposit amount: ");
double depositAmount = scanner.nextDouble();
account.deposit(depositAmount);
break;
case 2:
System.out.print("Enter withdrawal amount: ");
double withdrawAmount = scanner.nextDouble();
account.withdraw(withdrawAmount);
break;
case 3:
System.out.println("Balance: " + account.checkBalance()); break;
case 4:
account.displayAccountInfo();
break;
case 0:
System.out.println("Exiting...");
break;
default:
System.out.println("Invalid choice. Please try again."); break;
}
} while (choice != 0);
scanner.close();
}
}
