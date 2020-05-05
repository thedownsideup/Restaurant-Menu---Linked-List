/*NAME: Mahsa Eskandari Ghadi STUnum: 810196597*/


#include "Header.h"
#include <stdio.h>

int main() {


	Akbar_Joojeh* akbar = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));

	akbar->foodlist = makeheadfood();
	akbar->customerlist = makeheadcustomer();
	akbar->orderlist = makeheadorder();

	customer* new_node;
	food* new_food;
	order* new_order;

	char username[30];
	char name[20];
	int order_num = 0;
	int orderN = 0;
	int agreement;
	int insertC, removeC, addO, removeO, addF;
	printf(" Hello! Welcome to AkbarJooje!\n");


	while (1) {
		switch (Request())
		{

		case 1:

			print_customers(akbar->customerlist);
			break;

		case 2:
			printf("Please read and agree to Terms and Conditions agreement:\n I Solemnly Swear That I Am Upto No Good.\n");
			printf("press 1 to agree\npress 0 to reject\n");
			scanf("%d", &agreement);
			if (agreement == 0)
			{
				printf("Peace out\n");
			}
			else {
				insertC = insert_customer(&(akbar->customerlist), (customer*)malloc(sizeof(customer)));
				if (insertC == 0)
					printf("\n couldn't add customer\n!");
				else if (insertC == 1)
					printf("\nCongratulations! You are an Akjooj!\n");
				
			}
			

			break;

		case 3:

			printf("\n Please enter your username to find:   ");
			scanf("%s", username);
			new_node = search_customer(akbar->customerlist, username);
			if (new_node == NULL)
			{
				printf("Customer not found\n");
			}
			else
			{
				printf("Customer found\n");
				printf("\n %s      ", new_node->username);
				printf("%d      ", new_node->phoneNum);
				printf("%s      ", new_node->address);
			}
			break;

		case 4:

			printf("\n Please enter your username to remove:   ");
			scanf("%s", &username);
			removeC = remove_customer(akbar, username);
			if (removeC == 0)
				printf("FAAAIL!");
			if (removeC == 1)
				printf("\n Sorry to see you leave\n");
			break;

		case 5:

			print_foods(akbar->foodlist);
			break;

		case 6:

			addF = add_food(akbar->foodlist, (food*)malloc(sizeof(food)));
			if (addF == 1)
				printf("Food was successfuly added\n");
			else if (addF == 0)
				printf("FAAIL\n try again\n");
			break;

		case 7:

			printf("\n Please enter the name of the food to search:   ");
			scanf("%s", name);
			new_food = search_food(akbar->foodlist, name);
			if (new_food == NULL) {
				printf("\n Sorry. We don't serve this food. \n");
			}
			else
			{
				printf("Dish found: \n");
				printf("\n %s      ", new_food->name);
				printf("%d      ", new_food->price);
			}
			break;

		case 8:

			print_orders(akbar);
			break;

		case 9:
			new_order = (order*)malloc(sizeof(order));
			new_order->orderNum = orderN;
			addO = add_order(akbar, new_order);
			if (addO == 1)
				printf("Order was successfully added!\n");
			else if (addO == 0)
				printf("FAAILL\n");
			orderN++;
			break;

		case 10:

			printf("\n Please enter your order number to remove:   ");
			scanf("%d", &order_num);
			removeO = remove_order(akbar->orderlist, order_num);
			if (removeO == 1)
				printf("Order was successfully removed\n");
			else if (removeO == 0)
				printf("FAAIL\n");
			break;

		case 0:

			//printf("Are you sure you want to QUIT?/n");
			//scanf("%c", sure);
			return 0;
			break;
		default: {printf("request not found\n"); exit(0); }

		}//END SWITCH
		
	} //END WHILE
	return 0;
}
