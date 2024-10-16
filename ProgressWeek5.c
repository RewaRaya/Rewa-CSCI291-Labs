#include <stdio.h> //to use input and output functions
#include <math.h> //to use math operation functions 

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

/*Inserting global values*/
float price_E = 3.5;
float price_C = 4.5;
float price_M = 5.5;
float total_amount = 0.0;

/*Initiating Variables for later calculations and processes*/
int coffeeBeans = 100;
int water = 500;
int milk = 300;
int chocoSyrup = 100;

/*Function Prototypes for coffee machine functions*/
void orderCoffee();
void updateIngreQuantity(int beans, int water, int milk, int chocoSyrup);
void adminMode();
void dispStatus();
void refillIngre();
void priceChange();

/*Function Calls for the Coffee type Order*/
int main(void)
{
    int opt; // variable to store the user's option after main screen
    while(1)
    {
        //main screen options:
        printf("---- Coffee Machine Menu ----\n");
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Select an option from the list above by using the corresponding number: ");
        scanf("%d", &opt);
        
        // using switch to admit the user to chosen option:
        switch(opt) 
        {
            case 1: /*Odering the Coffee and nested ifs*/
            orderCoffee(); break; //calling ordering function 
            
            case 2: /*Accessing Admin Mode*/
            adminMode(); break; //Calling admin fdunction
            
            case 3: /*Exiting Program*/
            printf("Exiting the program. Please wait a moment.\n");
            return 0;
            
            default:
            printf("Invalid Option. Please try again.\n");
        }
    }
    return 0;
}

/*FUNCTION DEFINITIONS*/
void orderCoffee() 
{
    int x; // variable for chosen coffee type 
    float price = 0;

    /*Infinite loop for the Coffee Ordering*/
    while (1)
    {
        printf("MENU\n");
        printf("1.  Espresso,           %.2f AED\n", price_E);
        printf("2.  Cappauccino,        %.2f AED\n", price_C);
        printf("3.  Mocha,              %.2f AED\n\n", price_M);
        printf("0. Exit\n\n");
        printf("Choose the coffee you want by typing its number represented in the Menu:");
        scanf("%d\n", &x);
        
        switch (x) 
        {
            case 1:
            if (coffeeBeans >= COFFBEANS && water >= WATER_EC) //Enough ingredients to make the coffee
            {
                price = price_E;
                printf("You selected Espresso. Price: %.2f AED\n", price);
            }         
            else {
               printf("Espresso is unavailable due to insufficient ingredients. \n");
            }
            break;
                    
            case 2:
            if (coffeeBeans >= COFFBEANS && water >= WATER_EC && milk >= MILK_C)
            {
                price = price_C;
                printf("You selected Cappuccino. Price: %.2f AED\n", price);
            }
            else {
                printf("Cappuccino is unavailable due to insufficient ingredients. \n");
            }
            break;
                
            case 3:
            if (coffeeBeans >= COFFBEANS &&  water >= WATER_M && milk >= MILK_M && chocoSyrup >= CHOCO)
            {
                price = price_M;
                printf("You selected Mocha. Price: %.2f AED\n", price);
            }
            else {
                printf("Mocha is unavailable due to insufficient ingredients. \n");
            }
            break;
            
            case 0:
            puts("Please wait for a moment.");
            break;
            
            default:
            printf("Invalid selection. Please try Again. \n"); 
            continue;
        }
    
        /*Process of Payment*/
        if (price > 0)
        {
            float paidAmount = 0;
            float coin;
            while (paidAmount < price) //using while loop similarly to MATLAB
            {
                printf("Insert amount %.2f AED in coins (0.5 or 1 are Accepted)\n", price);
                scanf("%.2f", &coin);
                if (coin == 0.5 || coin == 1) //measure how much user paid with coins
                {
                    paidAmount += coin;
                }
                else {
                    printf("Coin regected, please collect the coin and insert a valid coin again.\n");
                }
            break;
            }
            // Update the amount of money in machine and display how much user has paid:
            total_amount += price;
            printf("You paid %.2f AED. Enjoy Your Coffee!\n", paidAmount);

            // Update the ingredients quantity:
            if (x == 1)
                updateIngreQuantity(COFFBEANS, WATER_EC, 0,0);
            if (x == 2)
                updateIngreQuantity(COFFBEANS, WATER_EC, MILK_C,0);
            if (x == 3)
                updateIngreQuantity(COFFBEANS, WATER_M, MILK_M, CHOCO);
        }
    } //end while loop 
}//end function definition


// Function Definiton for Alert about Ingredients:
void updateIngreQuantity(int beans, int waterUsed, int milkUsed, int chocoSyrupUsed)
{
    coffeeBeans -= beans;
    water -= waterUsed;
    milk -= milkUsed;
    chocoSyrup -= chocoSyrupUsed; 
    if (coffeeBeans <= THRESHOLD_BEANS) /*check if the ingredients are below threshold*/
        puts("ALERT! Insufficient Coffee beans amount. Call admin to refill.");
        
    if (water <= THRESHOLD_WATER)
        puts("ALERT! Insufficient Water volume. Call admin to refill."); 
    
    if (milk <= THRESHOLD_MILK)
        puts("ALERT! Insufficient Milk volume. Call admin to refill.");
        
    if (chocoSyrup <= THRESHOLD_CHOCO)
        puts("ALERT! Insufficient Chocolate syrup volume. Call admin to refill.");
}

void adminMode()
{
    int pass, opt;
    printf("Enter the Admin password: \n");
    scanf("%d", pass);

    if (pass != ADMINPASS)
    {
        printf("Incorrect password.\n");    
    }
    else{
        while(1)
        {
            printf("\n---- Admin Menu ----\n\n");
            printf("Choose an option:\n");
            printf("1. Check ingredients levels and total money in machine\n");
            printf("2. Restock Ingredients\n");
            printf("3. Change coffee prices\n");
            printf("0. Exit Admin Menu\n");
            printf("Select an option using the respective number: ");
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
                break; //exits switch and goes back to admin menu

                default:
                printf("Invalid option selected. Try again.\n");
            }
        }
    }
}

//Function Definition for Diplaying Status:
void dispStatus()
{
    printf("\n---- Machine Status ----\n");
    printf("Coffee Beans amount>          %d grams\n", coffeeBeans);
    printf("Water amount>                 %d mL\n", water);
    printf("Milk amount>                  %d mL\n", milk);
    printf("Chocolate Syrup amount>       %d mL\n", chocoSyrup);
    printf("\nThe total money amount: AED %.2f", total_amount);
}

//Function Definition for Restocking Ingredients:
void refillIngre() 
{
    int choose, amount;

    while(1)
    {
        printf("\n---- Select Ingredient to Refill ----\n");
        printf("1. Coffee Beans\n");
        printf("2. water\n");
        printf("3. Milk\n");
        printf("4. Chocolate Syrup\n");
        printf("0. Exit\n");
        printf("Select option by typing its respective number: ");
        scanf("%d", &choose);

        switch(choose)
        {
            case 1:
            printf("Enter refill quantity of Coffee Beans: ");
            scanf("%d", &amount);
            coffeeBeans += amount;
            printf("Coffee Beans are succeffuly refilled to %d grams.\n", coffeeBeans);
            break;

            case 2:
            printf("Enter refill quantity of Water: ");
            scanf("%d", &amount);
            water += amount;
            printf("Water is succeffuly refilled to %d mL.\n", water);
            break;

            case 3:
            printf("Enter refill quantity of Milk: ");
            scanf("%d", &amount);
            milk += amount;
            printf("Milk is succeffuly refilled to %d mL.\n", milk);
            break;

            case 4: 
            printf("Enter refill quantity of Chocolate Syrup: ");
            scanf("%d", &amount);
            chocoSyrup += amount;
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
        printf("2.Cappucino\n");
        printf("3. Mocha\n");
        printf("0. Exit mode\n");
        printf("Choose an option from the above by referring to the respective number:\n");
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
            printf("Enter Espresso's new price:\n");
            scanf("%.2f", newPrice);
            price_E = newPrice;
            break;

            case 2:
            printf("Enter Cappucino's new price:\n");
            scanf("%.2f", newPrice);
            price_C = newPrice;
            break;

            case 3:
            printf("Enter Mocha's new price:\n");
            scanf("%.2f", newPrice);
            price_M = newPrice;
            break;

            case 0:
            break;

            default:
            printf("Invalid option. Try again.\n");
        }
    }
}