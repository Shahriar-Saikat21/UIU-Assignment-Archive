import java.util.Scanner;

class Employee{
    private String name;
    private String designation;
    private double salary;

    void setName(String name){
        this.name = name;
    }

    void setDesignation(String designation){
        this.designation = designation;
    }

    void setSalary(double salary){
        this.salary = salary;
    }

    String getName(){
        return name;
    }

    String getDesignation(){
        return designation;
    }

    double getSalary(){
        return salary;
    }

    double calculateSalary(double salaryAmount){
        return salaryAmount;
    }

    double calculateSalary(double salaryPerHour,int workHour){
        return salaryPerHour*workHour;
    }

    double calculateSalary(double baseSalary,int numberOfProductSale, double commissionPerSale){
        return baseSalary+(numberOfProductSale*(commissionPerSale/100));
    }
}

class SalariedEmployee extends Employee{
    SalariedEmployee(String name,String designation,double salary){
        super.setName(name);
        super.setDesignation(designation);
        super.setSalary(super.calculateSalary(salary));
    }
}

class HourlySalaried extends Employee{
    HourlySalaried(String name,String designation,double salaryPerHour,int workHour){
        super.setName(name);
        super.setDesignation(designation);
        super.setSalary(super.calculateSalary(salaryPerHour,workHour));
    }
}

class CommissionBasedSalaried extends Employee{
    CommissionBasedSalaried(String name,String designation,double baseSalary,int numberOfProductSale, double commissionPerSale){
        super.setName(name);
        super.setDesignation(designation);
        super.setSalary(super.calculateSalary(baseSalary, numberOfProductSale, commissionPerSale));
    }
}

class Application{
    Employee[] employeeArray;
    int index;
    Scanner input = new Scanner(System.in);

    Application(){
        employeeArray = new Employee[100];
    }

    void createEmployeeProfile(){
        System.out.print("Enter Employee Name : ");
        input.nextLine();
        String employeeName = input.nextLine();
        System.out.println("   Enter Designation Option\n    1.Salaried\n    2.Hourly Salaried\n    3.Commissioned");
        System.out.print("    Enter Option : ");
        int designationOption = input.nextInt();
        if(designationOption == 1){
            System.out.print("Enter Salary : ");
            double salary = input.nextDouble();
            Employee e = new SalariedEmployee(employeeName,"Salaried",salary);
            employeeArray[index] = e;
            index++;
        }else if(designationOption == 2){
            System.out.print("Enter Salary Per Hour : ");
            double salaryPerHour = input.nextDouble();
            System.out.print("Enter Work Hour : ");
            int workHour = input.nextInt();
            Employee e = new HourlySalaried(employeeName,"Hourly Salaried",salaryPerHour,workHour);
            employeeArray[index] = e;
            index++;
        }else if(designationOption == 3){
            System.out.print("Enter Base Salary : ");
            double baseSalary = input.nextDouble();
            System.out.print("Enter Number of Product Sale: ");
            int numberOfProductSale = input.nextInt();
            System.out.print("Enter Commission: ");
            double commission = input.nextDouble();
            Employee e = new CommissionBasedSalaried(employeeName,"Commissioned",baseSalary,numberOfProductSale,commission);
            employeeArray[index] = e;
            index++;
        }else{
            System.out.println("Invalid Designation !!");
        }
    }

    void searchEmployee(){
        int flag = 0;
        System.out.print("Enter Employee Name to Search : ");
        input.nextLine();
        String searchName = input.nextLine();
        for (int i = 0; i < index; i++) {
            if (employeeArray[i].getName().equals(searchName)){
                System.out.println(employeeArray[i].getName());
                System.out.println(employeeArray[i].getDesignation());
                System.out.println(employeeArray[i].getSalary());
                System.out.println();
                flag = 0;
                break;
            }else{
                flag++;
            }
        }
        if (flag!=0){
            System.out.println("Record is not found !!");
        }
    }

    void updateRecord(){
        int flag = 0;
        System.out.print("Enter Employee Name to Update : ");
        input.nextLine();
        String searchName = input.nextLine();
        for (int i = 0; i < index; i++) {
            if (employeeArray[i].getName().equals(searchName)){
                System.out.println("Enter Update Designation : ");
                System.out.println("   1.Salaried\n   2.Hourly Salaried\n   3.Commissioned");
                System.out.print("    Enter Option : ");
                int designationOption = input.nextInt();
                if(designationOption == 1){
                    System.out.print("Enter Salary : ");
                    double salary = input.nextDouble();
                    employeeArray[i].setDesignation("Salaried");
                    employeeArray[i].setSalary(employeeArray[i].calculateSalary(salary));
                    System.out.println("\nRecord is updated successfully");
                    flag = 0;
                    break;
                }else if(designationOption == 2){
                    System.out.print("Enter Salary Per Hour : ");
                    double salaryPerHour = input.nextDouble();
                    System.out.print("Enter Work Hour : ");
                    int workHour = input.nextInt();
                    employeeArray[i].setDesignation("Hourly Salaried");
                    employeeArray[i].setSalary(employeeArray[i].calculateSalary(salaryPerHour,workHour));
                    System.out.println("\nRecord is updated successfully");
                    flag = 0;
                    break;
                }else if(designationOption == 3){
                    System.out.print("Enter Base Salary : ");
                    double baseSalary = input.nextDouble();
                    System.out.print("Enter Number of Product Sale: ");
                    int numberOfProductSale = input.nextInt();
                    System.out.print("Enter Commission: ");
                    double commission = input.nextDouble();
                    employeeArray[i].setDesignation("Commissioned");
                    employeeArray[i].setSalary(employeeArray[i].calculateSalary(baseSalary,numberOfProductSale,commission));
                    System.out.println("\nRecord is updated successfully");
                    flag = 0;
                    break;
                }else{
                    System.out.println("Invalid Designation !!");
                    flag = 0;
                    break;
                }
            }else{
                flag++;
            }
        }
        if (flag!=0){
            System.out.println("Record is not found !!");
        }
    }

    void showAllEmployee(){
        for (int i = 0; i < index; i++) {
            System.out.println(employeeArray[i].getName());
            System.out.println(employeeArray[i].getDesignation());
            System.out.println(employeeArray[i].getSalary());
            System.out.println();
        }
    }

    void showMenu(){
        int option;
        do{
            System.out.println("\n***Employee Record System***");
            System.out.println(" 1. Create Employee Profile \n 2. Search Employee Record\n 3. Update Record \n 4. Show All Record\n 5. Exit ");
            System.out.print("\nEnter your choice: ");
            option = input.nextInt();

            switch(option){
                case 1:
                    createEmployeeProfile();
                    break;
                case 2:
                    searchEmployee();
                    break;
                case 3:
                    updateRecord();
                    break;
                case 4:
                    showAllEmployee();
                    break;
                case 5:
                    System.out.println("Thank You !!");
                    break;
                default:
                    System.out.println("Invalid Option");
            }
        }while(option != 5);
    }
}

public class QuesThree {
    public static void main(String[] args) {
        Application a = new Application();
        a.showMenu();
    }
}
