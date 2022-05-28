//U19CS038 SUMIT SHETTY
#include<iostream>
using namespace std;

class account{
    protected:
    string customer_name;
    long long int account_number;
    string account_type;

    public:
    void customerName(string name) {
        this->customer_name = name;
    }
    void accountNo(long long int acctno) {
        this->account_number = acctno;
    }
    void acct_type(string acct) {
        this->account_type = acct;
    }
};

class cur_acct : public account{
    static double min_balance;
    static double srv_charge;
    double act_balance;

    public:
    void minBalance(double money) {
        min_balance = money;
    }
    void initCharge(double money) {
        srv_charge = money;
    }
    void initBalance(double bal) {
        this->act_balance = bal;
    }
    void money_deposit(double money) {
        this->act_balance += money;
    }
    void checkMinBalance() {
        if(this->act_balance<min_balance) {
            cout << "Please maintain minimum balance!!\n";
            if(this->act_balance > srv_charge){
                this->act_balance -= srv_charge;
                cout << "Amount 50 charged for not maintaining minimum balance!!\n";
            }
            else
                this->act_balance = 0;
        }
        else{
            cout << "Remaining balance : " << this->act_balance << "\n";
        }
    }
    void withdrawal(double money) {
        if(money <= this->act_balance)
        {
            this->act_balance -= money;
            checkMinBalance();
            cout << "Money Withdrawal Successful !!!\n\n";
        }
        else{
            cout << "You do not have enough balance in your account!!\n\n";
        }
    }
    void displayBalance() {
        cout <<"\nAccount Balance is : "<< (double)this->act_balance <<"\n\n";
        if(this->act_balance < min_balance)
        {
            cout << "Please maintain minimum balance!!!\n\n";
        }
    }
    void acctInfo() {
        cout << "\n----------Account Information----------------";
        cout << "\nAccount holder    : " << this->customer_name;
        cout << "\nAccount no.       : " << this->account_number;
        cout << "\nAccount type      : " << this->account_type;
        cout << "\nCurrent Balance   : " << (double)this->act_balance;
        cout << "\nHaving Chequebook : Yes"; 
        cout << "\n\n" ;
    }
};
double cur_acct::min_balance{ 500.00 };
double cur_acct::srv_charge{ 50.00 };

class sav_acct : public account{
    static double rate;
    double interest;
    double act_balance;

    public:
    void initBalance(double bal) {
        this->act_balance = bal;
    }
    void money_deposit(double money) {
        this->act_balance += money;
    }
    void withdrawal(double money) {
        if(money <= this->act_balance) {
            this->act_balance -= money;
            cout << "Money Withdrawal Successful !!!\n";
            cout << "Remaining balance : " << this->act_balance << "\n\n";
        }
        else
            cout << "You do not have enough balance in your account!!\n";
    }
    void computeInterest(int years) {
        interest = (this->act_balance)*(rate)*(years);
        cout << "Calculated interest : "<< interest << "\n";
        cout << "Final amount after "<< years << "years will be : " << this->act_balance + interest;
        cout << "\n\n";
    }
    void displayBalance() {
        cout << "Account Balance is : " << this->act_balance <<"\n\n";
    }
    void acctInfo() {
        cout << "\n----------Account Information----------------";
        cout << "\nAccount holder    : " << this->customer_name;
        cout << "\nAccount no.       : " << this->account_number;
        cout << "\nAccount type      : " << this->account_type;
        cout << "\nCurrent Balance   : " << this->act_balance;
        cout << "\nHaving Chequebook : No"; 
        cout << "\n\n" ;
    }
};
double sav_acct::rate{6.00};

int main()
{
    while(1)
    {
        int accounttype;
        cout << "Account types : \n1 : Savings\n2 : Current\nEnter your choice : ";
        cin >> accounttype; 
        if(accounttype == 1)
        {
            int amt;
            sav_acct sav;
            string name;
            sav.acct_type("Savings");

            cout << "Enter Account name : ";
            cin >> name;
            sav.customerName(name);

            sav.accountNo(0ll + 311099181000 + rand()%1000);

            cout << "Deposit initial balance (greater than zero): ";
            cin >> amt;
            sav.initBalance(amt);

            while(1)
            {
                cout << "Following operations are allowed : ";
                cout << "\n1.Deposit money\n2.Withraw Money\n3.Check Balance in your account\n";
                cout << "4.Interest calculation\n5.Account Information\n";
                int i;
                cout << "Choose any operation you want to perform : ";
                cin >> i;

                if(i==1) {
                    double money;
                    cout << "\nEnter the amount to deposit : ";
                    cin >> money;
                    sav.money_deposit(money);
                    cout << "Successfully money deposited!!!\n\n";
                }
                else if(i==2) {
                    double money;
                    cout << "\nEnter the amount for withrawal : ";
                    cin >> money;
                    sav.withdrawal(money);
                }
                else if(i==3) {
                    sav.displayBalance();
                }
                else if(i==4) {
                    int years;
                    cout << "Enter no of years : ";
                    cin >> years;
                    sav.computeInterest(years);
                }
                else if(i==5){
                    sav.acctInfo();
                }
                else{
                    cout << "Invalid Operation\n\n";
                    break;
                }
            }        
        }
        else if (accounttype == 2){
            string name;
            double amt;
            cur_acct curr;
            curr.acct_type("Current");

            cout << "\nEnter Account name : ";
            cin >> name;
            curr.customerName(name);

            curr.accountNo(0ll + 311099181000 + rand()%1000);

            cout << "\nMinimum Balance in current account : 500.00";
            cout << "\nService Charge : 50.00\n";

            cout << "\nDeposit initial balance (should be more than minimum balance) : ";
            cin >> amt;
            curr.initBalance(amt);

            while(1)
            {
                cout << "Following operations are allowed : ";
                cout << "\n1.Deposit money\n2.Withraw Money\n3.Check Balance in your account\n";
                cout << "4.Account Information\n";
                int i;
                cout << "Choose any operation you want to perform : ";
                cin >> i;

                if(i==1) {
                    double money;
                    cout << "\nEnter the amount to deposit : ";
                    cin >> money;
                    curr.money_deposit(money);
                    cout << "Successfully money deposited!!!\n\n";
                }
                else if(i==2) {
                    double money;
                    cout << "\nEnter the amount for withrawal : ";
                    cin >> money;
                    curr.withdrawal(money);
                }
                else if(i==3) {
                    curr.displayBalance();
                }
                else if(i==4){
                    curr.acctInfo();
                }
                else{
                    cout << "Invalid Operation\n\n";
                    break;
                }
            }
        }

        int ch;
        cout << "Do you want to perform further operation (1:Yes 0:No) ? ";
        cin >> ch;
        if(ch != 1)
            return 0;
    }
    return 0;
}