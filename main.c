#include"project2.h"

int main() {
	
	int i; //argument given
	int count; //number of products currently in list
	int minNumProducts = 1; //mininum number of products to display a list
	
	//case 1
	struct node *head;
	
	//variables for case 2
	char case2Name[100];
	char case2Unit[100];
	int case2Price, case2Quantity;
	
	//variables for case 3
	char case3Name[100]; 
	
	//variables for case 5
	char case5Name[100]; 
	
	//variables for case 7
	char case7Name[100];
	
	//variables for case 8
	char case8Name[100]; 
	
	//variable for case 9
	FILE *fout;
	struct node *current;
	char filename[] = "productList.txt";
	

	printf("Input a number from 0-10 to execute a command. \n");
	printf("User must create a list (0) before any other commands can be executed. \n \n"); 
	printf("1: Create an empty list		2: Insert a product \n"); 
	printf("3: Delete a product		4: Delete the entire list \n"); 
	printf("5: Search a product 		6: Display products in the list \n"); 
	printf("7: Purchase a product 		8: Sell a product \n"); 
	printf("9: Save to file 		0: Exit \n \n");
	

	printf("Please enter a command as seen above. If an empty list has not yet been created (1), the program will fail. \n \n"); 
	
	while(i != 0) {
		scanf("%d", &i); 
		
		switch(i) {
			case 1: //create a linked list with only a head
				head = init();
				printf("A new list has been created! \n \n"); 
				printf("Please enter another command, or enter 0 to exit program. \n \n"); 
				break;

			case 2: //insert new node with user input
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				printf("Enter product name: ");
				scanf("%99s", case2Name);
				
				printf("Enter the unit of measurement for the product: ");
				scanf("%99s",case2Unit);
				
				printf("Enter the price of the product (int): ");
				scanf("%d", &case2Price);
				
				printf("Enter the quantity of the product (int): ");
				scanf("%d", &case2Quantity);
				
				insert(head, case2Name, case2Unit, case2Price, case2Quantity);
				printf("Please enter another command, or enter 0 to exit program. \n \n"); 		
				break;
			
			case 3: //delete product with name from user input	
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				printf("Enter the name of the product you want to delete: ");
				scanf("%99s", case3Name); 
				
				deleteNode(head, case3Name); 
				printf("Please enter another command, or enter 0 to exit program. \n \n"); 
				break;
				
			case 4: //delete all the products in the list
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				deleteAll(head); 
				printf("Please enter 1 to create a new list, or enter 0 to exit program. \n \n"); 
				break;
				
			case 5: //search if a product is found in the list or not
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				printf("Enter the name of the product you want to search for: ");
				scanf("%s", case5Name); 
				
				searchProduct(head, case5Name); 
				printf("Please enter another command, or enter 0 to exit program. \n \n");
				break;
			
			case 6: //display the whole list of products
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				count = numProducts(head); 
				if(count < minNumProducts) {
					printf("List is empty. Populate/create list to display list. \n \n"); 
					break; 
				}
				else {
					printf("Printing list: \n \n"); 
					display(head); 
					printf("Please enter another command, or enter 0 to exit program. \n \n"); 
					break;
				}
		
			case 7: //purchase a product
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				printf("Specify the name of the product you wish to purchase: ");
				scanf("%99s", case7Name); 
			
				purchaseProduct(head, case7Name); 
				printf("Please enter another command, or enter 0 to exit program. \n \n"); 				
				break;
		
			case 8: //sell a product
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				printf("Specify the name of the product you wish to sell: ");
				scanf("%99s", case8Name); 
			
				sellProduct(head, case8Name); 
				printf("Please enter another command, or enter 0 to exit program. \n \n"); 
				break;
		
			case 9: //save list to file
				if(head == NULL) { 
					printf("A new list must be initiated before using other commands. Press 1 to create a new list. \n \n"); 
					break; 
				}
				fout = fopen(filename, "w");
				current = head->next; 
				while(current != NULL) {
					fprintf(fout, "Product: %s\nUnit: %s \nPrice: $%d \nQuantity: %d \n \n", current->name, current->unit, current->price, current->quantity); 
					current = current->next; 
				}
				free(current); 
				fclose(fout); 
				printf("Your output file is [productList.txt] in your project folder. Exit program (0) to view, or enter more commands. \n \n");  
				break;
		
			case 0: //exit the program
				printf("Exiting program. Visit again soon! \n \n"); 
				exit(1); 
				break; 
			
			default: 
				printf("Use a valid input (0-9). \n \n"); 
				break; 
		}
	}
	
	return 1;
	
}