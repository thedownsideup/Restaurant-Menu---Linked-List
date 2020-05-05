/*NAME: Mahsa Eskandari Ghadi STUnum: 810196597*/

#ifndef CODE_HEADER_H
#define CODE_HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct _Akbar_Joojeh Akbar_Joojeh;
typedef struct _customer customer;
typedef struct _food food;
typedef struct _food_row food_row;
typedef struct _order order;

/* This Struct must contain:
*     list of customers
*     list of foods
*     list of orders
*/
struct _Akbar_Joojeh {
	order* orderlist;
	food* foodlist;
	customer* customerlist;
};



/* This Struct must contain:
*     username
*     phone number
*     address
*     left_child
*     right_child
* *** if you want to use linklist, use next instead of left child and right child
*/
struct _customer {
	char username[30];
	int phoneNum;
	char address[200];
	customer *left;
	customer *right;
	customer *next;
};



/* This Struct must contain:
*     name
*     price
*     next_node
*/
struct _food {
	char name[30];
	int price;
	food *next;
};



/* This Struct must contain:
*     food name
*     quantity
*     next
*/
struct _food_row {
	char foodName[30];
	int quantity;
	food_row *next;

};



/* This struct must contain:
*     order number
*     customer username
*     list of food_row
*     Date and Time
*     next_node
*/
struct _order {
	int orderNum;
	char customerUsername[30];
	int numOfOrders;
	food_row* link;
	order *next;
	time_t x = time(NULL);
};


/* NOTICE: YOU CANNOT CHANGE ANY FUNCTION DECLARATION */

/**--------------- Customrs --------------**/
/*
* print all customers in detail sorted by usernames (alphabetically)
*/
void print_customers(customer* customer_root);

/*
* add new node in tree in alphabetical order
*      return 1 if added successfully, otherwise if username is duplicated return 0
*/
int insert_customer(customer** customer_root, customer* new_node);

/* Bonus Part:
* remove a customer by its username
* (also you should remove all his/her orders)
*      return 1 if removed successfully, otherwise return 0
*/
int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]);

/*
* search a customer by username and return its pointer
*     return NULL if customer did not find
*/
customer* search_customer(customer* customer_root, char username[]);


/**--------------- Foods --------------**/
/*
* print all foods
*/
void print_foods(food* food_list);

/*
* add new food
*     return 1 if added successfully, otherwise if name is duplicated return 0
*/
int add_food(food* food_list, food* new_food);

/*
* search a food by name and return its pointer
*      return NULL if food did not find
*/
food* search_food(food* food_list, char name[]);


/**--------------- Orders --------------**/
/*
* print all orders with user informatin and total price
*/
void print_orders(Akbar_Joojeh* akbar_joojeh);

/*
* add new order
*     return 1 if added successfully, otherwise if order number is duplicated or entered invalid username or invalid food return 0
*/
int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order);

/*
* remover a order by its number
*      return 1 if removed successfully, otherwise return 0
*/
int remove_order(order* order_list, int order_number);

food* makeheadfood();
order* makeheadorder();
customer* makeheadcustomer();
food_row *makeheadfoodrow();

int Request();
#endif //CODE_HEADER_