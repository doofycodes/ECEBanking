#include <stdio.h>
#include <math.h>

    /*
    printf("address of balance: %p\n", &balance);
    printf("value of pBalance:%p \n", pBalance);

    printf("size of balance: %lu bytes\n", sizeof(balance));
    printf("size of pBalance: %lu bytes\n", sizeof(pBalance));
    
    printf("value of balance: %lf \n", balance);
    printf("value at stored address: %lf \n", *pBalance);//dereferencing
    */

void menu(double *pBalance, FILE *pF);
void depo(double *pBalance, FILE *pF);
void with(double *pBalance, FILE *pF);
void printBalance(double *pBalance);


int main()
{

    double balance =0.0;
    double *pBalance = &balance;

    FILE *pF;
    pF = fopen("Statement.txt","w");
    fprintf(pF, "-----Welcome to your statement-----\n\n");

    printf("\n\nHello welcome to Gbank\n");
    menu(pBalance,pF);//passing the POINTER to menu function 
    // when passing a pointer, you wont include the * because you are passing the actual address. When you receive a pointer, you must specify with a 
    //* because you are saying that you are passing a POINTER
    // you can use/change the actual value of the pointer by DEREFERENCING by putting a * before the name
   
    fclose(pF);
    return 0;
}

//this function will determine what the user wants to do and then call the next appropriate function 
void menu(double *pBalance, FILE *pF)
{

    int choice;

    while(choice !=4){

    //print options
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n\n");
    printf("Enter your choice:");
    
    //take and store choice
    scanf("%d", &choice);

    //call functions 
    switch(choice){

        case 1:
        depo(pBalance,pF);
        break;

        case 2:
        with(pBalance,pF);
        break;

        case 3:
        printBalance(pBalance);
        break;

        case 4:
        printf("thank you!\n");
        break;

        default:
        printf("invalid choice, try again\n\n");
        continue;
        }
    }
}

void depo(double *pBalance, FILE *pF)
{
    //declare variable and store deposit amount
    double amount;
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    //make sure deposit amount is positive
    if(amount <0){ 
        printf("\ninvalid amount, please try again\nEnter deposit amount: ");
        scanf("%lf", &amount);
    }

    //add deposit amount to balance
    *pBalance += amount;//dereference

    //send the deposit and new balance to history file
    fprintf(pF, "Deposited %.2lf\n", amount);
    fprintf(pF, "   Balance: %.2lf\n", *pBalance);
    //print success message and new balance to terminal
    printf("\nDeposit succesful\nNew balance: %.2lf\n\n",*pBalance);
}
 
void with(double *pBalance, FILE *pF)
{

    //declare variable and store withdrawal amount
    double amount;
    printf("please enter withdrawal amount\n");
    scanf("%lf", &amount);

    //make sure withdrawal is less than balance
    while(amount > *pBalance){ 
        printf("\ninsufficient funds. \nEnter a new withdraw amount: ");
        scanf("%lf", &amount);
    }

    //this will check if the withdraw amount is divisible by 20. fmod(numerator,denominator)
    while(fmod(amount, 20.0) !=0){
        printf("\nYou can only withdraw in multiples of 20. \nEnter a new withdraw amount: ");
        scanf("%lf", &amount);
    }
    //withdraw money from balance
    *pBalance -= amount;

    //send the deposit and new balance to history file
    fprintf(pF, "Withdrew %.2lf\n", amount);
    fprintf(pF, "   Balance: %.2lf\n", *pBalance);
    //print success message and new balance to terminal
    printf("\nWithdrawal successful\nNew balance %.2lf \n\n", *pBalance);

}
void printBalance(double *pBalance)
{

    printf("your balance is: $%.2lf \n",*pBalance); //dereference
}
