#include <stdio.h> //to use input and output functions
#include <math.h> //to use math operation functions 
#include <stdlib.h> //for rand funtion

/*defining constants*/
#define COFFBEANS 8

#define WATER_EC 30
#define WATER_M 39

#define MILK_C 70
#define MILK_M 160 

#define CHOCO 30

#define THRESHOLD_BEANS 10
#define THRESHOLD_WATER 40
#define THRESHOLD_MILK 80
#define THRESHOLD_CHOCO 35

#define ADMINPASS 1234

/*global values*/
float price_E = 3.5;
float price_C = 4.5;
float price_M = 5.5;
float total_amount = 0.0;
float price;

/*Initiating Variables for later calculations and processes*/
int coffeeBeans = 1000;
int water = 5000;
int milk = 3000;
int chocoSyrup = 1000;

/*Function Prototypes for coffee machine functions*/
void orderCoffee();
void updateIngreQuantity(int beans, int water, int milk, int chocoSyrup);
void adminMode();
void dispStatus();
void refillIngre();
void priceChange();
void paymentcheck(float price);

/*Function Calls for the Coffee type Order*/
int main(void)
{
    int opt; // variable to store the user's option after main screen
    while(1) /*infinite loop for the main menu screen*/
    {
        //main screen options:
        printf("---- Coffee Machine Menu ----\n\n");
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n\n");
        printf("0. Exit\n\n");
        printf("Select an option from the list above by using the corresponding number: \n");
        scanf("%d", &opt);
        
        // using switch to admit the user to chosen option:
        switch(opt) 
        { 
            case 1: 
            orderCoffee(); break; /*Ordering Menu*/
            
            case 2: /*Accessing Admin Mode*/
            adminMode(); break; //Function Call for Admin
            
            case 0: /*Exiting Program*/
            printf("Program exited successfully.\n");
            return(0); break; //using return to close the whole program.
            
            default: 
            printf("Invalid Option. Please try again.\n\n"); 
            break;
        }
    }
    return 0;
}

/*FUNCTION DEFINITIONS*/

void orderCoffee() 
{
    int x=0;
    int confirm;
    
     if (coffeeBeans <= THRESHOLD_BEANS &&  water <= THRESHOLD_WATER && milk <= THRESHOLD_MILK && chocoSyrup <= THRESHOLD_CHOCO)
    {
        puts("No coffee can be served at the moment. ");
    }
    
   else{
    /*Infinite loop for the Coffee Ordering*/
    while (x == 0 || x>3 || x<0)
    {
        printf("\n              MENU\n\n");
        printf("1.  Espresso,           %.2f AED\n", price_E);
        printf("2.  Cappauccino,        %.2f AED\n", price_C);
        printf("3.  Mocha,              %.2f AED\n\n", price_M);
        printf("0. Exit\n\n");
        printf("Choose the coffee you want by typing its number represented in the Menu: \n");
        scanf("%d", &x);
        
                switch(x) 
        {
            case 1:
            if (coffeeBeans >= COFFBEANS && water >= WATER_EC) //Enough ingredients to make the coffee
            {
                price = price_E; 
                printf("\nYou selected Espresso. Price: %.2f AED\nType 1 to confirm and 0 if not: \n", price);
                scanf("%d", &confirm); 
                
                if (confirm == 1){ //confirming order
                total_amount += price;
                paymentcheck(price);
                updateIngreQuantity(COFFBEANS, WATER_EC, 0,0); break; //update quantity
                }
                else{
                    x=0; break;
                }
                
            }         
            else {
               printf("\nUnavailable due to temporarily insuﬃcient ingredients.\n"); break;
            }
            
            case 2:
            if (coffeeBeans >= COFFBEANS && water >= WATER_EC && milk >= MILK_C)
            {
                price = price_C;
                printf("\nYou selected Cappuccino. Price: %.2f AED\nType 1 to confirm and 0 if not: \n", price);
                scanf("%d", &confirm);
                
                if (confirm == 1){
                total_amount += price;
                paymentcheck(price);
                updateIngreQuantity(COFFBEANS, WATER_EC, MILK_C,0); break; //update quantity
                }
                else{
                    x=0; break;
                }
            }
            else {
                printf("\nUnavailable due to temporarily insuﬃcient ingredients.\n"); break;
            }
         
            case 3:
            if (coffeeBeans >= COFFBEANS &&  water >= WATER_M && milk >= MILK_M && chocoSyrup >= CHOCO)
            {
                price = price_M;
                printf("\nYou selected Mocha. Price: %.2f AED\nType 1 to confirm and 0 if not: \n", price);
                scanf("%d", &confirm);
                
                if (confirm == 1){
                total_amount += price;
                paymentcheck(price);
                updateIngreQuantity(COFFBEANS, WATER_M, MILK_M, CHOCO); break; //update quantity
                }
                else{
                    x=0; break;
                }
            }
            else {
                printf("\nUnavailable due to temporarily insuﬃcient ingredients.\n"); break;
            }
            
            case 0:
            x=1; //using 1 to not loop this menu
            puts("\nPlease wait for a moment.\n"); break;
            
            default:
                printf("Invalid selection. Please try Again. \n"); break;
         }
        
    }//end while loop
    }//end else statement
}//end function definition

void paymentcheck(float price){
    /*Process of Payment*/
    float paidAmount = 0; //variable for amount paid
    float coin; //variable for coins inserted
    
    while(paidAmount < price) //using while loop similarly to MATLAB
        {
            printf("Insert amount %.2f AED in coins (0.50 or 1.00 are Accepted)\n", price);
            scanf("%f", &coin);
            if(coin == 0.50 || coin == 1.00) //measure how much user paid with coins
            {
                paidAmount += coin;
                if(paidAmount>price)
                printf("Please collect the change.\n");
            }
            else 
                printf("Coin regected, please collect the coin and insert a valid coin again.\n\n");
        }
    printf("You paid %.2f AED. Enjoy Your Coffee!\n\n", price);
}

// Function Definiton for Alert about Ingredients:
void updateIngreQuantity(int beans, int waterUsed, int milkUsed, int chocoSyrupUsed)
{
    coffeeBeans -= beans;
    water -= waterUsed;
    milk -= milkUsed;
    chocoSyrup -= chocoSyrupUsed; 
    if (coffeeBeans <= THRESHOLD_BEANS) /*check if the ingredients are below threshold*/
        puts("\nALERT! Insufficient Coffee beans amount. Call admin to refill.");
        
    if (water <= THRESHOLD_WATER)
        puts("\nALERT! Insufficient Water volume. Call admin to refill."); 
    
    if (milk <= THRESHOLD_MILK)
        puts("\nALERT! Insufficient Milk volume. Call admin to refill.");
        
    if (chocoSyrup <= THRESHOLD_CHOCO)
        puts("\nALERT! Insufficient Chocolate syrup volume. Call admin to refill.");
    if (coffeeBeans <= THRESHOLD_BEANS &&  water <= THRESHOLD_WATER && milk <= THRESHOLD_MILK && chocoSyrup <= THRESHOLD_CHOCO)
        puts("\nALERT! ALL ingredients are below threshold amount! Call admin to refill.");
}

void adminMode()
{
    int pass, opt;
    printf("\nEnter the Admin password: \n");
    scanf("%d", &pass);

    if (pass != ADMINPASS)
    {
        printf("\nIncorrect password.\n\n");  return;  
    }
    else{
        while(1)
        {
            printf("\n---- Admin Menu ----\n\n");
            printf("Choose an option:\n");
            printf("1. Check ingredients levels and total money in machine\n");
            printf("2. Restock Ingredients\n");
            printf("3. Change coffee prices\n\n");
            printf("0. Exit Admin Menu\n");
            printf("Select an option using the respective number: \n");
            scanf("%d", &opt);

            /*Use switch to divert the tasks based on option selected*/
            switch (opt)
            {
                case 1: 
                dispStatus(); break; //calls to function for diplaying ingredients' current level and money stored

                case 2:
                refillIngre(); break; //calls to function for restocking ingredients

                case 3:
                priceChange(); break; //calls to function to change coffee prices

                case 0:
                return; break; //exits switch and goes back to admin menu

                default:
                printf("Invalid option selected. Try again.\n"); break;
            }
        }
    }
}

//Function Definition for Diplaying Status:
void dispStatus()
{
    int opt1;
    printf("\n---- Machine Status ----\n");
    printf("Coffee Beans amount>          %d grams\n", coffeeBeans);
    printf("Water amount>                 %d mL\n", water);
    printf("Milk amount>                  %d mL\n", milk);
    printf("Chocolate Syrup amount>       %d mL\n", chocoSyrup);
    printf("\nThe total money amount: AED %.2f\n", total_amount);
    
    if (total_amount != 0){
        printf("\nWould you like to withdraw the cureent money? 1 = Yes, 0 = No");
        scanf("%d", &opt1);
        if (opt1 == 1)
        {
            total_amount = 0;
            printf("\nReseting total amount is complete. Please collect the money.\n\n");
        }
    }    
    else
    return;
}

//Function Definition for Restocking Ingredients:
void refillIngre() 
{
    int choose, amount;

    while(1)
    {
        printf("\n---- Select Ingredient to Refill ----\n");
        printf("1. Coffee Beans\n");
        printf("2. Water\n");
        printf("3. Milk\n");
        printf("4. Chocolate Syrup\n");
        printf("0. Exit\n");
        printf("Select option by typing its respective number: \n");
        scanf("%d", &choose);

        switch(choose)
        {
            case 1:
            coffeeBeans += rand() %200 + 100; //coffee beans top up with refill amount
            printf("Coffee Beans are succeffuly refilled to %d grams.\n", coffeeBeans);
            break;

            case 2:
            water += rand() %600 + 300; //water top up with refill amount
            printf("Water is succeffuly refilled to %d mL.\n", water);
            break;

            case 3:
            milk += rand() %600 + 400; //milk top up with refill amount
            printf("Milk is succeffuly refilled to %d mL.\n", milk);
            break;

            case 4: 
            chocoSyrup += rand() %400 + 200; //Chocolate Syrup with refill amount
            printf("Chocolate Syrup is succeffuly refilled to %d mL.\n", chocoSyrup);
            break;

            case 0:
            printf("Exiting Restocking mode.\n");
            return;

            default:
            printf("Invalid option. Please try again.\n");
        }
    }
}

//Changing Coffee Prices Function Definition:
void priceChange()
{
    int choose;
    float newPrice;
    while(1)
    {
        printf("\n---- Price Control Mode ----\n");
        printf("1. Espresso\n");
        printf("2. Cappucino\n");
        printf("3. Mocha\n");
        printf("0. Exit mode\n");
        printf("Choose an option from the above by referring to the respective number:\n");
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
            printf("Enter Espresso's new price:\n");
            scanf("%f", &newPrice);
            price_E = newPrice;
            break;

            case 2:
            printf("Enter Cappucino's new price:\n");
            scanf("%f", &newPrice);
            price_C = newPrice;
            break;

            case 3:
            printf("Enter Mocha's new price:\n");
            scanf("%f", &newPrice);
            price_M = newPrice;
            break;

            case 0:
            return; break;

            default:
            printf("Invalid option. Try again.\n");
        }
    }
}