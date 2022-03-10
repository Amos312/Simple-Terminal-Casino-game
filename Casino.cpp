#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void casino()
{
    cout<<"\t\t\t====WELCOME TO THE CASINO====\n";
    cout<<"\t\t-------------------------------------------\n";
}

void rules()
{
    cout<<"\nRules:\n";
    cout<<"1.Each player can choose any amount to start with.\n";
    cout<<"2.If a player wins the bet the money gets doubled.\n";
    cout<<"3.If a player loses all the initial money the game will end automatically.\n";
    cout<<"4.So the player can play untill their money gets nill or he/she wants to quit the game.\n\n";    
}
int main()
{
    string name; 
    int balance,amount,bet;
    int dice;
    char choice;
    casino();
    rules();
    cout<<"Player please enter your name:"<<endl;
        getline(cin,name);
    cout<<"Enter the amount you want to start with: $";
        cin>>balance;
    rules();
    system("pause");//use do while
    system("cls");
    srand(time(0));
    do{
        system("cls");
        casino();
        do{
            cout<<"Your balance:$"<<balance<<endl;
            cout<<name<<" how much you want to bet? $";
            cin>>amount; 
            if(amount>balance || amount<=0) cout<<"Invalid amount Please enter a valid amount!"<<endl;
        }
        while(amount>balance ||amount<=0);
        do{
            cout<<"Please enter a bet from 1 to 5"<<endl;
            cin>>bet;
            if(bet>5 || bet<1) cout<<"Invalid entry, please enter a valid bet!"<<endl;
        }
        while(bet>5 || bet<1);
        dice=rand()%5+1;//this actually generates number from 0 to 5(if rand()%6)to eliminate 0 we mod it by 5 and add 1
        cout<<"The winning bet was:"<<dice<<endl;
        if(dice!=bet)
        {
            cout<<"\nBetter luck next time!"<<endl;
            balance=balance-amount;
            cout<<"\nYour balance:$"<<balance<<endl;
        }
        else if(dice==bet)
        {
            balance=amount*2+balance;
            cout<<"\nCongratulation you've won the bet!\nNow your balance is"<<balance;
        }
        if(balance<=0)
        {
            cout<<"You've exchausted your balance!\nPlease come again!"<<endl;
            break;
        }
        else
        {
            cout<<"Do you wish to continue? press(y/n)"<<endl;
            cin>>choice;
            
        } 
    }
    while(choice=='y' || choice=='Y');
    return 0;
}