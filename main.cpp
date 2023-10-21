#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//global variables declaration
long long jumlah_uang;
long long PIN; 
long long no_rek;
long long gopayAccount, gopayAmount;
long long ovoAccount, ovoAmount;
long long linkajaAccount, linkajaAmount;
long long phoneAccount, creditAmount;
long long topup;
int attempt = 0;
int menu;
int menu_topup;
int rekening_tujuan;
int moneyTransfer;
int withdraw;
int userTopup;
int userInput;
string string_PIN; 
string username; 
string string_no_rek;
string beritaTransfer;
string userType, userPass;

void menu_main();

void return_menu(){
  cout<<"       Return to main menu?"<<endl;
  cout<<endl;
  cout<<"       1.Yes"<<endl;
  cout<<"       2.No"<<endl;
  cout<<endl;
  
  cin>>userInput;

  if (cin.fail()){
    cout << "       Please enter proper numbers"<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return return_menu();
    }

  else if (userInput == 1){
    return menu_main();
  }
  else if (userInput == 2){
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout << "|                     Thank you for using our services!                      |" << endl;
    cout << "|----------------------------------------------------------------------------|" << endl << endl << endl;
    return;
  }
  else {
    return return_menu();
  }

}
void konfirmasi_pin(){
/*
Konfirmasi PIN flow
1. While loops 3 kali attempt
2. masukin PIN terus di compare == dengan PIN diawal
3. kalo salah lebih dari 3 kali, end program
4. function ini di recall dalem int main setelah void
*/
while ( attempt < 3 ){
cout << "Enter your PIN: " << endl;
cin >> userPass;

if (userPass != string_PIN )
{
    cout << "Incorrect PIN combination. Please try again." << "\n" <<
    endl;

    attempt++;
}

else
{
    break;
}
}
}

void transfer_money() {
/*
Transfer Money Menu terdiri dari:
1. Input rekening tujuan [int]
2. Input amount of money [int]
3. Input berita transfer [string]
4. Output Final Confirmation recap
5. Input 6 Digit PIN [If Else Statement]
6. Output Message Transfer Berhasil 
7. Output Final Balance setelah transfer_money
8. Konfirmasi ingin lanjutkan transaksi atau end program [go to]
*/
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                              Transfer Money Menu                              |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << endl;

  cout << "       Receiver Account Number: ";
  cin >> rekening_tujuan;

  cout << "       Amount: ";
  cin >> moneyTransfer;

  cout << "       Notes: ";
  cin >> beritaTransfer;

  cout <<endl<< "       Confirmation" << endl;
  cout << "       Receiver Account Number: " << rekening_tujuan << endl;
  cout << "       Amount: " << moneyTransfer << endl;
  cout << "       Notes: " << beritaTransfer << endl;

  jumlah_uang = jumlah_uang - moneyTransfer;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + moneyTransfer;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }

       for (int attempt = 3; attempt > 0; --attempt) {

        cout << endl << "       ===============" << endl << "       Enter PIN: ";
        cin >> userPass;

        if (attempt == 1) {
        cout << "       You have exceeded the attempt limit" << endl;
        }
        if (userPass != string_PIN) {
          cout << "       Incorrect username or PIN!" << endl;
        }
        else if (userType == username && userPass == string_PIN) {
            cout << endl;
            cout << "|----------------------------------------------------------------------------|" << endl;
            cout << "|                         Transaction Successful                             |" << endl;
            cout << "|----------------------------------------------------------------------------|" << endl; 

            cout << "       Sender Account Number: " << no_rek << endl;
            cout << "       Sender Name: " << username << endl;
            cout << endl;
            cout << "       Receiver Account Number: " << rekening_tujuan << endl;
            cout << "       Amount: " << moneyTransfer << endl;
            cout << "       Notes: " << beritaTransfer << endl;
            cout << endl;
            cout << "|----------------------------------------------------------------------------|" << endl;

            break;
        }
  }
  return_menu();
}

void withdraw_money() {
/*
1. Display option mau withdraw berapa
2. make switch case untuk pilih option berapa
3. masukin registered PIN
4. if true, maka continue, if PIN false maka program end. 
*/
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                                Withdraw Money Menu                            |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  
  renew:
  cout << "       Please Select the amount of money you want to withdraw                  " << endl;
    
  cout << "       1. Rp 50.000" << endl;
  cout << "       2. Rp 100.000" << endl;
  cout << "       3. Rp 200.000" << endl;
  cout << "       4. Rp 500.000" << endl;
  cout << "       5. Rp 1.000.000" << endl;
  cout << "    " << endl;
  cin >> withdraw;

          if (cin.fail()){
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
     
  switch (withdraw) {
  case 1:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Withdraw Confirmation                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Withdraw : Rp 50.000" << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - 50000;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + 50000;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }

  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Please take your money                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;

  return_menu();

  
  case 2:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Withdraw Confirmation                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Withdraw : Rp 100.000" << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - 100000;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + 100000;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }            
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Please take your money                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  return_menu();

    
  case 3:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Withdraw Confirmation                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Withdraw : Rp 200.000" << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - 200000;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + 200000;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }            
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Please take your money                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  return_menu();

  case 4:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Withdraw Confirmation                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Withdraw : Rp 500.000" << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - 500000;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + 500000;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }            
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Please take your money                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  return_menu();


  case 5:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Withdraw Confirmation                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Withdraw : Rp 1.000.000" << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - 1000000;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + 1000000;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }              
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                           Please take your money                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  return_menu();

  default:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                         Select the number between 1-5                      |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  goto renew;
  }
}

void show_balance(){

cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                              Account Balance Menu                             |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  
  cout << endl;
  cout << "       Username: " << username << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Balance: Rp " << jumlah_uang << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  return_menu();  

}

void top_up(){
  
  top_up_menu:
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                                 Top Up Menu                                   |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;

  cout << endl;

  cout << "       1. GOPAY" << endl;
  cout << "       2. OVO" << endl;
  cout << "       3. Link Aja" << endl;
  cout << "       4. Pulsa" << endl;
  cout << "     " << endl;
  cin >> userTopup;

  switch (userTopup){
  case 1:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                                   GoPay                                    |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         GoPay Customer Number : ";
  cin >> gopayAccount;
  cout << "         Amount : Rp ";
  cin >> gopayAmount;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - gopayAmount;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + gopayAmount;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }            
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                               Top Up Successful                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         GoPay Customer Number : " << gopayAccount << endl;
  cout << "         Amount : Rp " << gopayAmount << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                        Thank you for using our services!                   |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl << endl << endl;;
  
  return_menu();

  case 2:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                                     OVO                                    |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         OVO Number : ";
  cin >> ovoAccount;
  cout << "         Amount : Rp ";
  cin >> ovoAmount;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - ovoAmount;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + ovoAmount;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }            
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                               Top Up Successful                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         OVO Number : " << ovoAccount << endl;
  cout << "         Amount : Rp " << ovoAmount << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                        Thank you for using our services!                   |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl << endl << endl;
  return_menu();


  case 3:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                                  Link Aja                                  |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         Link Aja Number : ";
  cin >> linkajaAccount;
  cout << "         Amount : Rp ";
  cin >> linkajaAmount;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - linkajaAmount;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + linkajaAmount;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }              
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                               Top Up Successful                            |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         Link Aja Number : " << linkajaAccount << endl;
  cout << "         Amount : Rp " << linkajaAmount << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                        Thank you for using our services!                   |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl << endl << endl;
  return_menu();


  case 4:
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Pulsa Top Up                                 |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         Phone Number : ";
  cin >> phoneAccount;
  cout << "         Amount : Rp ";
  cin >> creditAmount;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                              Input Your PIN                                |" << endl; 
  cout << "|----------------------------------------------------------------------------|" << endl;
            
  konfirmasi_pin();
  jumlah_uang = jumlah_uang - creditAmount;
  
  if(jumlah_uang<0){
    jumlah_uang = jumlah_uang + creditAmount;
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout<<"              You do not have enough money! Returning to main menu"<<endl;
    cout<<endl;
    return menu_main();
  }               
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                             Top Up Successful                              |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "         Username : " << username << endl;
  cout << "         Account Number : " << no_rek << endl;
  cout << "         Phone Number : " << phoneAccount << endl;
  cout << "         Amount : Rp " << creditAmount << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                     Thank you for using our services!                      |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl << endl << endl;
  return_menu();

  default: 
  cout << "Invalid input!" << endl;
  goto top_up_menu;
  }

}
void menu_main(){
    cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                             Mobile Banking Main Menu                          |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << endl;

  cout << "1. Transfer Money" << endl;
  cout << "2. Withdraw Money" << endl;
  cout << "3. Show Balance" << endl;
  cout << "4. Top Up" << endl;
  cout << "5. Log Out & End Program" << endl;
  cout << endl << "==============" << endl << "Input:    ";
  cin >> menu;
  
        if (cin.fail()){
        cout<<"Please pick a number from the menu : "<<endl<<endl;;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         return menu_main();
         }
 
  switch (menu){
    case 1:
    transfer_money();
    break;

    case 2:
    withdraw_money();
    break;
    
    case 3:
    show_balance();
    break;

    case 4:
    top_up();
    break;

    case 5:
    cout << "|----------------------------------------------------------------------------|" << endl;
    cout << "|                     Thank you for using our services!                      |" << endl;
    cout << "|----------------------------------------------------------------------------|" << endl << endl;
    break;
    }
}

int main(){

  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                                Registration Menu                              |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << endl;
  cout << "       Input New Username : "; 
  cin >> username;
  cout << endl;
  
 bool i = false;
  while (i == false){
    cout << "       Input New Digits PIN (6 Digits): ";
    cin >> PIN;
    string_PIN = to_string(PIN);
      if (cin.fail()){
         cout << "       Please enter proper numbers"<<endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
      else if (string_PIN.size() < 6 || string_PIN.size() > 6){
        i = false;
        cout << endl;
        cout << "       Please input the PIN Consisting of 6 Digits! " << endl;
      }
      else{
        i = true;
        break;
      }    
  }
  cout << endl;
  bool j = false;
  while (j == false){
    cout << "       Input New Account Number (8 Digits): ";
    cin >> no_rek;
    string_no_rek = to_string(no_rek);
        if (cin.fail()){
         cout << "       Please enter proper numbers"<<endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
        else if (no_rek % 1000000 == 0)
        cout << "Please input the Account number in integer!" << endl;
        

      else if (no_rek % 1000000 >= 1)
      {
          if (string_no_rek.size() < 8 || string_no_rek.size() > 8) 
          {
            j = false;
            cout << endl;
            cout << "       Please input the Account Number Consisting of 8 Digits! " << endl;
 
          }
          else{
            j = true;
            break;
          }
      }    
  }
  cout << endl;
  bool k = false;
  while (k == false){
    cout << "       Input Amount of money to deposit (Minimum of Rp 500.000) : ";
    cin >> jumlah_uang;;
      if (cin.fail()){
         cout << "       Please enter proper numbers"<<endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         }
      else if (jumlah_uang < 500000 ){
        k = false;
        cout << endl;
        cout << "       Please input money to deposit with the minimum of Rp 500.000! " << endl;
        
      }
      else if (cin.fail())
{
         cout << "       Please enter proper numbers"<<endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
      else{
        k = true;
        break;
      }    
  }
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                             Account Confirmation                           |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "       Username : " << username << endl;
  cout << "       PIN : " << PIN << endl;
  cout << "       Account Number: " << no_rek << endl;
  cout << "       Balance: Rp " << jumlah_uang << endl;
  cout << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << "|                             Registration Complete                          |" << endl;
  cout << "|         Please Proceed to the Mobile Banking Main menu by login in         |" << endl;
  cout << "|----------------------------------------------------------------------------|" << endl;
  cout << endl;
  cout << endl;
/* Login system terdiri dari (While Loop):
1. Login 3 kali attempt [while loop]
2. if username == username yang di save di struct
3. if PIN == PIN yang di save di struct
4. else, end the program or blocked
*/
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << "|                 ________   __  ______   ___  ___   _  ____ __                 |" << endl;
  cout << "|                / ___/ _ | /  |/  / _ | / _ )/ _ | / |/ / //_/                 |" << endl;
  cout << "|               / (_ / __ |/ /|_/ / __ |/ _  / __ |/    / ,<                    |" << endl;
  cout << "|               \\___/_/ |_/_/  /_/_/ |_/____/_/ |_/_/|_/_/|_|                   |" << endl;
  cout << "|                                                                               |" << endl;
  cout << "|                                   Login Menu                                  |" << endl;
  cout << "|-------------------------------------------------------------------------------|" << endl;
  cout << endl;

  int attemptX = 3;
  while (attemptX >= 0) {
        cout << "       Username: ";
        cin >> userType;

        cout << "       PIN: ";
        cin >> userPass;

        if (attemptX == 0) {
        cout << "       You have exceeded the attempt limit" << endl;
        return 0;
        }
        if (userType != username || userPass != string_PIN) {
          cout << "       Incorrect username or PIN!" << endl;
          attemptX--;
        }
        else if (userType == username && userPass == string_PIN) {
            cout << endl;
            cout << "|----------------------------------------------------------------------------|" << endl;
            cout << "|                              You Are Logged In                             |" << endl;
            cout << "|----------------------------------------------------------------------------|" << endl; 
            break;
        }
  
  }

menu_main();
return 0;
  }
