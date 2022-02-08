import java.util.Scanner;

class BankAccount{
    private String accountName;
    private double balance;

    void setAccountName(String accountName){
        this.accountName = accountName;
    }

    void setBalance(double initialBalance){
        balance = initialBalance;
    }

    String getAccountName(){
        return accountName;
    }

    double getBalance(){
        return balance;
    }
}

class Menu{
    BankAccount b;
    Scanner input = new Scanner(System.in);

    void showMenu(){
        int option;
        do{
            System.out.println("\n***Banking System Application***");
            System.out.println(" 1. Create account\n 2. Deposit the amount\n 3. Withdraw the amount \n 4.Check Balance \n 5.Exit ");
            System.out.print("Enter your choice: ");
            option = input.nextInt();

            switch(option){
                case 1:
                    createAccount();
                    break;
                case 2:
                    depositAmount();
                    break;
                case 3:
                    withdrawAmount();
                    break;
                case 4:
                    checkBalance();
                    break;
                case 5:
                    System.out.println("Thank You !!");
                    break;
                default:
                    System.out.println("Invalid Option");
            }
        }while(option != 5);
    }

    void createAccount(){
        System.out.print("Enter Account Name : ");
        input.nextLine();
        String name = input.nextLine();
        System.out.print("Enter Initial Amount : ");
        double initialAmount = input.nextDouble();
        b = new BankAccount();
        b.setAccountName(name);
        b.setBalance(initialAmount);
    }

    void depositAmount(){
        System.out.print("Enter Deposit Amount : ");
        double depositAmount = input.nextDouble();
        b.setBalance(b.getBalance()+depositAmount);
        System.out.println("Deposit Successful");
    }

    void withdrawAmount(){
        System.out.print("Enter Withdraw Amount : ");
        double withdrawAmount = input.nextDouble();
        if(b.getBalance() < withdrawAmount){
            System.out.println("Insufficient Amount!!");
        }else{
            b.setBalance(b.getBalance()-withdrawAmount);
        }
    }

    void checkBalance(){
        System.out.println("Your Balance : "+ b.getBalance());
    }
}

public class QuesTwo {
    public static void main(String[] args) {
        Menu a = new Menu();
        a.showMenu();
    }
}
