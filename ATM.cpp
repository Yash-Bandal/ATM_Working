#include<iostream>
#include<iomanip>
using namespace std;

class ATM
{
    private:
    int balance;
    public:
    ATM(int bal)
    {
        balance=bal;
    }
    int getBalance(){
        return  balance;
    }
    int withDraw(int amount){
        if(amount>balance){
            return false;
        }
        balance=balance -amount;
        return true;
       
    }
    void deposit(int amount){
        balance=balance+amount;
    }

};
int main(){
    ATM atm(1000);
   int choice,amount,success;
   char opt;
   do{
    cout<<"1.View balance"<<endl;
    cout<<"2.Cash Withdraw"<<endl;
    cout<<"3.Cash Deposit"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    //cout<<"your available Balance is:"<<atm.getBalance()<<endl;
    switch(choice){
        case 1:
        cout<<"your available Balance is:"<<atm.getBalance()<<endl;
        break;
        case 2:
        cout<<"Enter amount to withdraw";
        cin>>amount;
        success=atm.withDraw(amount);
        if(success){
            cout<<"withdraw successful"<<endl;
        }else{
            cout<<"Insufficient balance"<<endl;
        }
        break;
        case 3:
        cout<<"Enter amount to deposit:";
        cin>>amount;
        atm.deposit(amount);
        cout<<"Deposit Successful"<<endl;
        break;
        case 4:
        cout<<"ATM-Complete"<<endl;
        break;
        default:
        cout<<"Processing.....ERROR"<<endl;
      }
   cout<<"Continue another transaction[Y/N]:";
   cin>>opt;
   }
   while(opt=='y'||opt=='Y');

}
//Refer to
//Ref-https://github.com/MaheshwaryNarkhede/ATM/blob/main/atm.cpp
