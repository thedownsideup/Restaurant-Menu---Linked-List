/*NAME: Mahsa Eskandari Ghadi STUnum: 810196597*/

#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void print_customers(customer* customer_root) /*prints the list of the customers*/
{
	if (customer_root->next == NULL)
	{
		printf("list is empty. try again\n");

		return;
	}

	customer* current;
	current = customer_root->next;


	while (current != NULL) {
		printf("\n %s      ", current->username);
		printf("%d      ", current->phoneNum);
		printf("%s      ", current->address);
		current = current->next;
	}// END WHILE

} //end of print_customer


  /******************************************************************************************************************/


int insert_customer(customer** customer_root, customer* new_node) /*adds a new customer*/
{
	customer* current;
	char Username[30];

	if (*customer_root == NULL)                  //the list is empty
		*customer_root = new_node;                   //creates a whole new list
	else {
		printf("Please, Enter your username:  ");
		scanf("%s", Username);

		current = *customer_root;
		while (current->next != NULL && strcmp(current->next->username, Username) < 0) {
			current = current->next;
		} //END WHILE
		if (current->next != NULL && strcmp(Username, current->next->username) == 0) {
			printf("\nUsername has already been taken\n");
			return 0;
		}//END IF

		new_node->next = current->next;
		current->next = new_node;

		strcpy(new_node->username, Username);

		printf("\n Enter your phone number:   ");

		scanf("%d", &(new_node->phoneNum));
		if (new_node->phoneNum < 0 || new_node->phoneNum>99999999999) {
			printf("phone number is not valid\n");
			exit(0);
		}
		printf("\n Enter your address:   ");
		scanf("%s", new_node->address);
	} // END ELSE

	if (new_node != NULL)
		return 1;
	else return 0;
}//end of insert_customer


 /******************************************************************************************************************/


int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]) /*removes a customer by username*/
{
	customer* current;
	customer* prev;
	prev = akbar_joojeh->customerlist;
	current = akbar_joojeh->customerlist->next;
	while (current != (customer*)NULL)
	{
		if (strcmp(username, current->username) != 0)
		{                                                    //if not found yet goes to the next node
			prev = current;                                //keeps track of the previous node
			current = prev->next;
			continue;
		} //END IF
		else
		{
			prev->next = current->next;
			free(current);
			return 1;
		}//END ELSE
	} //END WHILE

	return 0;
} // end of remove_customer


  /******************************************************************************************************************/


  /* search a customer by username and return its pointer ???????????*/

customer* search_customer(customer* customer_root, char username[]) /*searches for a customer - by username*/
{
	customer* current;
	current = customer_root->next;


	while (current != (customer*)NULL)
	{
		if (strcmp(username, current->username) == 0)
			return current;
		current = current->next;
	}//END WHILE
	 //printf("\n You Don't Exist...\n");
	return NULL;

}// end of search_customer


 /**------------------------------------------ Foods -----------------------------------------------**/

void print_foods(food* food_list) /*prints the menu*/
{
	food* current;
	if (food_list->next == (food*)NULL)
	{
		printf("list is empty.\n");

		return;
	}
	current = food_list->next;
	do {
		printf("\n %s      ", current->name);
		printf("%d      ", current->price);
		current = current->next;
	} while (current != (food*)NULL);

} //end of print_food


  /******************************************************************************************************************/


int add_food(food* food_list, food* new_food) /*adds new dish to the menu*/
{
	food* current;
	current = food_list;

	printf("Please, Enter the name of the food you want to add:  ");
	scanf("%s", new_food->name);
	printf("\n Enter the price:   ");
	scanf("%d", &(new_food->price));

	while (current->next != NULL) {
		if (strcmp(new_food->name, current->next->name) == 0) {
			printf("\nDish already exists\n");
			free(new_food);
			return 0;
		}
		current = current->next;
	}//END IF
	current->next = new_food;
	new_food->next = (food*)NULL;
	return 1;
} //end of add_food


  /******************************************************************************************************************/


food* search_food(food* food_list, char name[]) /*searches for a dish - by name*/
{
	food* current;

	current = food_list;
	while (current != (food*)NULL)
	{
		if (strcmp(name, current->name) == 0)
			return current;
		current = current->next;
	}//END WHILE
	 //printf("\n Sorry. We don't serve this food. \n");
	return NULL;
} //end of search_food


  /**------------------------------------------------------- Orders -----------------------------------------------------**/
  /*
  print all orders with user informatin and total price
  */
void print_orders(Akbar_Joojeh* akbar_joojeh)
{
	food_row* current;
	order *help;
	if (akbar_joojeh->orderlist->next == (order*)NULL)
	{
		printf("There are no orders.\n");
		return;
	}
	help = akbar_joojeh->orderlist->next;

	do {
		int total = 0;
		printf("\n %s      ", help->customerUsername);
		printf("order number: %d      ", help->orderNum);
		printf("%s      ", ctime(&(help->x)));
		current = help->link->next;

		while (current != NULL)
		{
			food* foood = search_food(akbar_joojeh->foodlist, current->foodName);
			total += foood->price * current->quantity;
			printf("food: %s      ", current->foodName);
			printf("quantity: %d      \n", current->quantity);
			current = current->next;

		}// END WHILE
		printf("Total cost: %d \n", total);
		printf("\n");
		help = help->next;
	} while (help != (order*)NULL);

} // end of print_orders


  /******************************************************************************************************************/


int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order)/* adds a new order*/
{
	order* help;
	help = akbar_joojeh->orderlist;
	food_row* head = makeheadfoodrow();
	new_order->link = head;
	food_row* new_fr;
	food_row* current;
	current = head;
	int t;

	new_order->next = (order*)NULL;

	while (help->next != NULL)
	{
		if (help->next->orderNum == new_order->orderNum)
			return 0;
		help = help->next;
	}

	printf("Please, Enter your username:  ");
	scanf("%s", new_order->customerUsername);
	if (search_customer(akbar_joojeh->customerlist, new_order->customerUsername) == NULL)
	{
		return 0;
	}
	printf("\nEnter the number of orders    ");
	scanf("%d", &(new_order->numOfOrders));

	for (t = 0; t < new_order->numOfOrders; t++)
	{
		new_fr = (food_row*)malloc(sizeof(food_row));
		new_fr->next = (food_row*)NULL;

		current->next = new_fr;
		current = new_fr; //sets as the last node

		printf("\n Enter the name of the dish    ");
		scanf("%s", current->foodName);
		if (search_food(akbar_joojeh->foodlist, current->foodName) == NULL)
			return 0;
		printf("\n How many %ss do you want?    ", current->foodName);
		scanf("%d", &(current->quantity));

	} //END FOR
	new_order->x = time(NULL);
	help->next = new_order;
	return 1;
} // end of add_order

  /******************************************************************************************************************/


  /*
  * remover a order by its number
  *      return 1 if removed successfully, otherwise return 0
  */
int remove_order(order* order_list, int order_number) {

	order* current;
	order* prev;
	prev = order_list;
	current = order_list->next;
	while (current != (order*)NULL)
	{
		if (current->orderNum != order_number)
		{                                                    //if not found yet goes to the next node
			prev = current;                                //keeps track of the node before the one we're looking for
			current = prev->next;
			continue;
		} //END IF
		else
		{
			prev->next = current->next;
			free(current);
			return 1;
		}//END ELSE
	} //END WHILE

	return 0;
}

order *makeheadorder()
{
	order *temp = (order*)malloc(sizeof(order));

	temp->orderNum = -1;
	temp->numOfOrders = -1;
	temp->next = NULL;

	return temp;
}
food_row *makeheadfoodrow()
{
	food_row *temp = (food_row*)malloc(sizeof(food_row));

	temp->quantity = -1;
	temp->next = NULL;

	return temp;
}
customer *makeheadcustomer()
{
	customer* temp = (customer*)malloc(sizeof(customer));

	temp->phoneNum = -1;
	temp->next = NULL;

	return temp;
}

food *makeheadfood()
{
	food*temp;
	temp = (food*)malloc(sizeof(food));


	temp->price = -1;
	temp->next = NULL;

	return temp;
}
int Request()
{
	int request;
	printf("\n What can we do for you?\n");
	printf(" 1- Print CustomerList\n 2- Add Customer\n 3- Search Customer\n 4- Remove Customer\n 5- Print Menu\n 6- Add Dish\n 7- Search Dish\n 8- Print OrderList\n 9- Add Order\n 10- Remove Order\n 0- Quit\n");
	scanf("%d", &request);
	if (request < 0 || request>10) {
		printf("Sorry, request is not valid, please try again...\n");
	}

	return request;
}