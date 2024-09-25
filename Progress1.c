#include <stdio.h> //to use input and output functions
#include <math.h> //to use math operation functions 

/*defining constants*/
#define COFFBEANS 8

#define WATER_EC 30
#define WATER_M 39

#define MILK_C 70
#define MILK_M 160 

#define CHOCO 30

#define THRESHOLD_BEANS 8
#define THRESHOLD_WATER 40
#define THRESHOLD_MILK_C 70
#define THRESHOLD_MILK_M 160
#define CHOCO 30

#define ADMINPASS 1234

/*Inserting global values*/
float price_E = 3.5;
float price_C = 4.5;
float price_M = 5.5;
float totalSales = 0.0;

/*Initiating Variables for later calculations and processes*/
int coffeeBeans = 100;
int water = 500;
int milk = 300;
int chocoSyrup = 100;

/*Function Calls for the Coffee type Order*/
int main(void)
{
    int x; // variable for chosen coffee type 
    printf("MENU\n");
    printf("1.  Espresso,           %.2f\n", price_E);
    printf("2.  Cappauccino,        %.2f\n", price_C);
    printf("3.  Mocha,              %.2f\n\n", price_M);
    printf("Choose the coffee you want by typing its number represented in the Menu:");
    scanf("%d\n", x);
}