#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

/*Mini project - ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Update Mobile No.
*/
class atm
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setData(long int account_no_a,string name_a,int PIN_a,double balance_a,string mobile_no_a)
    {
        account_no=account_no_a;
        name=name_a;
        PIN=PIN_a;
        balance=balance_a;
        mobile_no=mobile_no_a;
    }
    long int getAccountno()
    {
        return account_no;
    }
    string getName()
    {
        return name;
    }
    int getPin()
    {
        return PIN;
    }
    double getbalance()
    {
        return balance;
    }
    string getMobileNo()
    {
        return mobile_no;
    }
    void setMobile(string mob_prev,string mob_new)
    {
        if(mob_prev==mobile_no)
        {
            mobile_no=mob_new;
            cout<<endl<<"Sucessfully updated mobile no.";
            getch();
        }
        else
        {
            cout<<"Sorry!!! Please enter valid mobile no:";
            getch();
        }
    }
    void checkBalance()
    {
        cout<<"Your Balance is :"<<balance;
        getch();
    }
    void getDetails()
    {
        cout<<"*** User Datails are ***"<<endl;
        cout<<"Your Account no is -> "<<account_no<<endl;
        cout<<"Your name is -> "<<name<<endl;
        cout<<"Your Mobile no is -> "<<mobile_no<<endl;
        cout<<"Your Balance is -> "<<balance<<endl;
    }
    void cashWithdraw(int amount_a)
    {
        if(amount_a>0 && amount_a<balance)
        {
            cout<<endl<<"Please collect your Cash";
            cout<<endl<<"Available Balance"<<balance;
            getch();
        }
        else
        {
            cout<<endl<<"Invalid Input or Insufficient Funds";
            getch();
        }
    }
};
int main()
{
    int choice=0,enterPin;
    long int enterAccountNo;
    system("cls");
    atm a;
    a.setData(1234567,"Aman",8504,45000.67,"8544219391");
    do
    {
        system("cls");

        cout<<endl<<"***** Welcome to ATM *****";
        cout<<endl<<"Enter your Account No:";
        cin>>enterAccountNo;

        cout<<endl<<"Enter Your Pin";
        cin>>enterPin;


        if((enterAccountNo==a.getAccountno()) && (enterPin==a.getPin()))
        {
            do
            {
                int amount =0;
                string oldMobileNo,newMobileNo;
                cout<<endl<<"*** WELCOME TO ATM ***";
                cout<<endl<<"Select Option:";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show user Details";
                cout<<endl<<"4. Upadate Mobile No";
                cout<<endl<<"5. Exit";
                cin>>choice;

                switch(choice)
                {
                case 1:
                    cout<<endl<<"Your Bank Balance is "<<a.getbalance();
                    getch();
                    break;
                case 2:
                    cout<<endl<<"Enter the amount :";
                    cin>>amount;
                    a.cashWithdraw(amount);
                case 3:
                    cout<<endl<<"*** USER DETAILS ARE ***";
                    cout<<endl<<"->Account No: "<<a.getAccountno();
                    cout<<endl<<"->Name: "<<a.getName();
                    cout<<endl<<"->Balance: "<<a.getbalance();
                    cout<<endl<<"->Mobile No:"<<a.getMobileNo();

                    getch();
                    break;
                case 4:
                    cout<<endl<<"Enter Old Mobile No:";
                    cin>>oldMobileNo;
                    cout<<endl<<"Enter New Mobile No:";
                    cin>>newMobileNo;

                    a.setMobile(oldMobileNo,newMobileNo);
                    break;
                case 5:
                    exit(0);
                default:
                    cout<<endl<<"Enter valid Data !!!";
                }

            } 
            while (1);
            
        }
        else
        {
            cout<<endl<<"User Details are Invalid !!! ";
            getch();
        }
    }
    while(1);
    
    return 0;
}