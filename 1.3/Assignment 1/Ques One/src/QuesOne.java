import java.util.Scanner;

class AddressBook{
    private String name;
    private String address;
    private String email;
    private String phone;

    void setName(String name){
        this.name = name;
    }

    void setAddress(String address){
        this.address = address;
    }

    void setEmail(String email){
        this.email = email;
    }

    void setPhone(String phone){
        this.phone = phone;
    }

    String getName(){
        return name;
    }

    String getAddress(){
        return  address;
    }

    String getEmail(){
        return email;
    }

    String getPhone(){
        return phone;
    }
}

class Application{
    AddressBook[] addressArray;
    int index;
    Scanner input = new Scanner(System.in);

    Application(){
        addressArray = new AddressBook[100];
    }

    void createRecord(){
        System.out.print("Enter Name: ");
        input.nextLine();
        String name = input.nextLine();
        System.out.print("Enter Address: ");
        String address = input.nextLine();
        System.out.print("Enter Email: ");
        String email = input.nextLine();
        System.out.print("Enter Phone Number: ");
        String phone = input.nextLine();

        AddressBook newRecord = new AddressBook();
        newRecord.setName(name);
        newRecord.setAddress(address);
        newRecord.setEmail(email);
        newRecord.setPhone(phone);

        System.out.println("\nRecord has been stored successfully");

        addressArray[index] = newRecord;
        index++;
    }

    void updateRecord(){
        int flag=0;
        System.out.print("Enter name which you want to update : ");
        input.nextLine();
        String searchName = input.nextLine();
        for (int i = 0; i < index; i++) {
            if(addressArray[i].getName().equals(searchName)){
                System.out.print("Enter Updated Address: ");
                String address = input.nextLine();
                System.out.print("Enter Updated Email: ");
                String email = input.nextLine();
                System.out.print("Enter Updated Phone Number: ");
                String phone = input.nextLine();

                addressArray[i].setAddress(address);
                addressArray[i].setEmail(email);
                addressArray[i].setPhone(phone);

                System.out.println("\nRecord is updated successfully");
                flag =0;
                break;
            }else{
                flag++;
            }
        }
        if(flag !=0){
            System.out.println("\nRecord is not found !!");
        }
    }

    void deleteRecord(){
        int flag=0;
        System.out.print("Enter name which you want to delete : ");
        input.nextLine();
        String searchName = input.nextLine();
        for (int i = 0; i < index; i++) {
            if(addressArray[i].getName().equals(searchName)){
                for (int j = i; j <index-1 ; j++) {
                    addressArray[j] = addressArray[j+1];
                }
                System.out.println("\nRecord is deleted successfully");
                index-=1;
                flag =0;
                break;
            }else{
                flag++;
            }
        }
        if(flag !=0){
            System.out.println("\nRecord is not found !!");
        }
    }

    void showAllAddress(){
        for (int i = 0; i < index; i++) {
            System.out.println(addressArray[i].getName());
            System.out.println(addressArray[i].getAddress());
            System.out.println(addressArray[i].getEmail());
            System.out.println(addressArray[i].getPhone());
            System.out.println();
        }
    }

    void showMenu(){
        int option;
        do{
            System.out.println("\n***Address Book Application***");
            System.out.println(" 1. Create Record\n 2. Update Record\n 3. Delete Record \n 4. Show All Record\n 5. Exit ");
            System.out.print("\nEnter your choice: ");
            option = input.nextInt();

            switch(option){
                case 1:
                    createRecord();
                    break;
                case 2:
                    updateRecord();
                    break;
                case 3:
                    deleteRecord();
                    break;
                case 4:
                    showAllAddress();
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


public class QuesOne {
    public static void main(String[] args) {
        Application a = new Application();
        a.showMenu();
    }
}
