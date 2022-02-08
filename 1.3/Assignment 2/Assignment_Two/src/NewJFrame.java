import java.io.*;
import java.util.*;

public class NewJFrame extends javax.swing.JFrame {

    public NewJFrame() {
        initComponents();
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">
    private void initComponents() {

        nameLabel = new javax.swing.JLabel();
        nameTF = new javax.swing.JTextField();
        phoneLabel = new javax.swing.JLabel();
        phoneTF = new javax.swing.JTextField();
        emailTF = new javax.swing.JTextField();
        emailLabel = new javax.swing.JLabel();
        addressLabel = new javax.swing.JLabel();
        addressTF = new javax.swing.JTextField();
        saveBTN = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        displayField = new javax.swing.JTextArea();
        showAllBTN = new javax.swing.JButton();
        newEntryTitleLabel = new javax.swing.JLabel();
        searchTitleLabel = new javax.swing.JLabel();
        searchNameLabel = new javax.swing.JLabel();
        searchTF = new javax.swing.JTextField();
        searchBTN = new javax.swing.JButton();
        editTitleLabel = new javax.swing.JLabel();
        editNameLabel = new javax.swing.JLabel();
        editNameTF = new javax.swing.JTextField();
        editPhoneLabel = new javax.swing.JLabel();
        editPhoneTF = new javax.swing.JTextField();
        editEmailLabel = new javax.swing.JLabel();
        editEmailTF = new javax.swing.JTextField();
        editAddressLabel = new javax.swing.JLabel();
        editAddressTF = new javax.swing.JTextField();
        updateBTN = new javax.swing.JButton();
        clearDisplayBTN = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Address Book App");
        setResizable(false);

        nameLabel.setFont(new java.awt.Font("Roboto", 1, 14)); // NOI18N
        nameLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        nameLabel.setText("Name");

        nameTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        phoneLabel.setFont(new java.awt.Font("Roboto", 1, 14)); // NOI18N
        phoneLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        phoneLabel.setText("Phone");

        phoneTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        emailTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        emailLabel.setFont(new java.awt.Font("Roboto", 1, 14)); // NOI18N
        emailLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        emailLabel.setText("Email");

        addressLabel.setFont(new java.awt.Font("Roboto", 1, 14)); // NOI18N
        addressLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        addressLabel.setText("Address");

        addressTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        saveBTN.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        saveBTN.setText("Save");
        saveBTN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveBTNActionPerformed(evt);
            }
        });

        jScrollPane1.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

        displayField.setColumns(20);
        displayField.setFont(new java.awt.Font("SansSerif", 0, 14)); // NOI18N
        displayField.setRows(5);
        displayField.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jScrollPane1.setViewportView(displayField);

        showAllBTN.setBackground(new java.awt.Color(102, 102, 255));
        showAllBTN.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        showAllBTN.setForeground(new java.awt.Color(255, 255, 255));
        showAllBTN.setText("Show All Contact");
        showAllBTN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                showAllBTNActionPerformed(evt);
            }
        });

        newEntryTitleLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        newEntryTitleLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        newEntryTitleLabel.setText("Enter New Contact Info");

        searchTitleLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        searchTitleLabel.setText("Searching");

        searchNameLabel.setFont(new java.awt.Font("Roboto", 1, 14)); // NOI18N
        searchNameLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        searchNameLabel.setText("Input Key");

        searchTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        searchBTN.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        searchBTN.setText("Search");
        searchBTN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                searchBTNActionPerformed(evt);
            }
        });

        editTitleLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        editTitleLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        editTitleLabel.setText("Edit A Contact Info");

        editNameLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        editNameLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        editNameLabel.setText("Name");

        editNameTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        editPhoneLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        editPhoneLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        editPhoneLabel.setText("Phone");

        editPhoneTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        editEmailLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        editEmailLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        editEmailLabel.setText("Email");

        editEmailTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        editAddressLabel.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        editAddressLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        editAddressLabel.setText("Address");

        editAddressTF.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N

        updateBTN.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        updateBTN.setText("Update");
        updateBTN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                updateBTNActionPerformed(evt);
            }
        });

        clearDisplayBTN.setBackground(new java.awt.Color(255, 102, 102));
        clearDisplayBTN.setFont(new java.awt.Font("SansSerif", 1, 14)); // NOI18N
        clearDisplayBTN.setForeground(new java.awt.Color(255, 255, 255));
        clearDisplayBTN.setText("Clear Display");
        clearDisplayBTN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                clearDisplayBTNActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addGroup(layout.createSequentialGroup()
                                                        .addComponent(nameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(nameTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                                        .addComponent(saveBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                .addGroup(layout.createSequentialGroup()
                                                                        .addComponent(phoneLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                        .addComponent(phoneTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                .addGroup(layout.createSequentialGroup()
                                                                        .addComponent(emailLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                        .addComponent(emailTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                .addGroup(layout.createSequentialGroup()
                                                                        .addComponent(addressLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                        .addComponent(addressTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))))
                                                .addComponent(newEntryTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 165, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGroup(layout.createSequentialGroup()
                                                        .addComponent(searchNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                        .addComponent(searchTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addComponent(searchBTN, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(searchTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(editNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(editNameTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                                .addComponent(updateBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addComponent(editPhoneLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                .addComponent(editPhoneTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addComponent(editEmailLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                .addComponent(editEmailTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addComponent(editAddressLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 68, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                .addComponent(editAddressTF, javax.swing.GroupLayout.PREFERRED_SIZE, 197, javax.swing.GroupLayout.PREFERRED_SIZE))))
                                        .addComponent(editTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(112, 112, 112)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 472, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(showAllBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 152, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(clearDisplayBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 152, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                .addContainerGap(26, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(newEntryTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(nameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(nameTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(phoneLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(phoneTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(emailLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(emailTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(addressLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(addressTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(saveBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(searchTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(searchNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(searchTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(searchBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(editTitleLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(editNameLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(editNameTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(editPhoneLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(editPhoneTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(editEmailLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(editEmailTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(editAddressLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(editAddressTF, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                        .addComponent(jScrollPane1))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(updateBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(showAllBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(clearDisplayBTN, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(0, 17, Short.MAX_VALUE))
        );

        pack();
    }

    private void saveBTNActionPerformed(java.awt.event.ActionEvent evt) {
        try{
            PrintWriter w = new PrintWriter(new FileWriter("Data/data.txt",true));

            String name = nameTF.getText();
            String phone = phoneTF.getText();
            String email = emailTF.getText();
            String addressDetail = addressTF.getText();
            w.println(name+"-"+phone+"-"+email+"-"+addressDetail);
            w.close();

            nameTF.setText("");
            phoneTF.setText("");
            emailTF.setText("");
            addressTF.setText("");

            displayField.setText("   New Contact Info Has been stored Successfully !!   ");

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    private void showAllBTNActionPerformed(java.awt.event.ActionEvent evt) {
        try{
            Scanner r = new Scanner(new FileReader("Data/data.txt"));
            ArrayList<Address>allContact = new ArrayList<>();

            while(r.hasNext()){
                String line = r.nextLine();
                String[]info = line.split("-");
                String name = info[0];
                String phone = info[1];
                String email = info[2];
                String addressDetail = info[3];

                allContact.add(new Address(name,phone,email,addressDetail));
            }

            allContact.sort(new Comparator<Address>() {
                @Override
                public int compare(Address o1, Address o2) {
                    return o1.name.compareTo(o2.name);
                }
            });

            displayField.setText("");
            for(Address a:allContact){
                displayField.append(a.name+"\nPhone : "+a.phone+"\nEmail :  "+a.email+"\nAddress : "+a.addressDetail+"\n\n");
            }
            r.close();

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    private void searchBTNActionPerformed(java.awt.event.ActionEvent evt) {
        try{
            Scanner r = new Scanner(new FileReader("Data/data.txt"));
            ArrayList<Address>allContact = new ArrayList<>();

            while(r.hasNext()){
                String line = r.nextLine();
                String[]info = line.split("-");
                String name = info[0];
                String phone = info[1];
                String email = info[2];
                String addressDetail = info[3];

                allContact.add(new Address(name,phone,email,addressDetail));
            }
            int flag = 0;
            String searchName = searchTF.getText().toUpperCase();
            displayField.setText("");
            for(Address a:allContact){
                String temp = a.name.toUpperCase();
                if(temp.contains(searchName)|| a.phone.contains(searchName)){
                    displayField.append(a.name+"\nPhone : "+a.phone+"\nEmail :  "+a.email+"\nAddress : "+a.addressDetail+"\n\n");
                    flag++;
                }
            }
            if(flag==0){
                displayField.setText("    Record is not found !!");
            }
            searchTF.setText("");
            r.close();

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    private void updateBTNActionPerformed(java.awt.event.ActionEvent evt) {
        try{
            Scanner r = new Scanner(new FileReader("Data/data.txt"));
            ArrayList<Address>allContact = new ArrayList<>();

            while(r.hasNext()){
                String line = r.nextLine();
                String[]info = line.split("-");
                String name = info[0];
                String phone = info[1];
                String email = info[2];
                String addressDetail = info[3];

                allContact.add(new Address(name,phone,email,addressDetail));
            }

            int flag = 0;
            String searchName = editNameTF.getText().toUpperCase();
            String updatePhone = editPhoneTF.getText();
            String updateEmail = editEmailTF.getText();
            String updateAddress = editAddressTF.getText();

            PrintWriter w = new PrintWriter(new FileWriter("Data/data.txt"));

            for(Address a :allContact){
                String temp = a.name.toUpperCase();
                if(temp.equals(searchName)){
                    a.phone = updatePhone;
                    a.email = updateEmail;
                    a.addressDetail = updateAddress;

                    w.println(a.name+"-"+a.phone+"-"+a.email+"-"+a.addressDetail);
                    flag++;
                }else{
                    w.println(a.name+"-"+a.phone+"-"+a.email+"-"+a.addressDetail);
                }
            }

            if(flag==0){
                displayField.setText("     Record is not found !!"+"\n"+"     Updating Unsuccessful !!");
            }else{
                displayField.setText("     Record has been updated successfully ");
            }
            editNameTF.setText("");
            editPhoneTF.setText("");
            editEmailTF.setText("");
            editAddressTF.setText("");
            r.close();
            w.close();

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    private void clearDisplayBTNActionPerformed(java.awt.event.ActionEvent evt) {
        displayField.setText("");
    }

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NewJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify
    private javax.swing.JLabel addressLabel;
    private javax.swing.JTextField addressTF;
    private javax.swing.JButton clearDisplayBTN;
    private javax.swing.JTextArea displayField;
    private javax.swing.JLabel editAddressLabel;
    private javax.swing.JTextField editAddressTF;
    private javax.swing.JLabel editEmailLabel;
    private javax.swing.JTextField editEmailTF;
    private javax.swing.JLabel editNameLabel;
    private javax.swing.JTextField editNameTF;
    private javax.swing.JLabel editPhoneLabel;
    private javax.swing.JTextField editPhoneTF;
    private javax.swing.JLabel editTitleLabel;
    private javax.swing.JLabel emailLabel;
    private javax.swing.JTextField emailTF;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel nameLabel;
    private javax.swing.JTextField nameTF;
    private javax.swing.JLabel newEntryTitleLabel;
    private javax.swing.JLabel phoneLabel;
    private javax.swing.JTextField phoneTF;
    private javax.swing.JButton saveBTN;
    private javax.swing.JButton searchBTN;
    private javax.swing.JLabel searchNameLabel;
    private javax.swing.JTextField searchTF;
    private javax.swing.JLabel searchTitleLabel;
    private javax.swing.JButton showAllBTN;
    private javax.swing.JButton updateBTN;
    // End of variables declaration
}
