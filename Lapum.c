#include "project2.h"

//initialize: create an empty head node (whose "data" is intentionally missing); This head node will not be used to store any data;
struct node *init () {
	struct node * head = NULL;
	head = malloc(sizeof(struct node));
	head->next = NULL;	
}


/*Create a new node to store data and insert it to the end of current linked list; the head node will still be empty and data in the array in 
"main.c" are not stored in head node */
void insert(struct node *head, char inputName[], char inputUnit[], int price, int quantity) {
	struct node *current = head;
	while(current->next != NULL) { //finding the end of list
		//current = current->next;
		if(strcmp(current->next->name, inputName) == 0) {
			printf("Product already exists. \n \n"); 
			return; 
		}
		else {
			current = current->next; 
		}
	}
	//adding new node to the end of list, setting next link to NULL (as long as ints are positive, non zero)
	if(price < 1 || quantity < 1) {
		printf("Nor price or quantity can be less than 1. \n \n");
		return; 
	}
	else {
		current->next = malloc(sizeof(struct node));
		strcpy(current->next->name, inputName);
		strcpy(current->next->unit, inputUnit);
		current->next->price = price;
		current->next->quantity = quantity;
		current->next->next = NULL;	
		printf("Product has successfully been inserted. \n \n"); 
		return; 
	}
}


//print data for all nodes in the linked list except the head node (which is empty)
void display (struct node *head) {
	struct node *current = head->next;
	while(current != NULL) { 
		printf("Product: %s \n", current->name);
		printf("Unit of Measurment: %s \n", current->unit); 
		printf("Price of Product: $%d \n", current->price); 
		printf("Quantity of Product: %d \n \n", current->quantity); 
		current = current->next;
	}
}


//delete the entire linked list including the head node
void deleteAll(struct node *head) {
	struct node *current = head;
	while(current != NULL) {
		free(current->next);
		current->next = NULL;
		current = current->next;
	}
	printf("All products in list have been deleted. \n \n"); 
}

//delete a specified product
void deleteNode(struct node *head, char name[]) { 
	struct node *current = head;
	while(current->next != NULL) {
		if(strcmp(current->next->name, name) == 0) {
			struct node *temp = current->next; 
			current->next = current->next->next; 
			free(temp); 
			printf("Product has been removed from list. \n \n");
			return; 
		}
		else {
			current = current->next; 
		}
	}
	printf("Product was not found in list. \n \n"); 
}


//search for a specified product
void searchProduct(struct node *head, char name[]) {
	struct node *temp = head; 

	while(temp != NULL) {
		if(strcmp(temp->name, name) == 0) {
			printf("Product was: Found\n \n");
			break;
		}
		else {
			temp = temp->next; 
		}
	}
	
	printf("Product was: Not found\n \n"); 
}

//increase the quantity of a specified product by one
void purchaseProduct(struct node *head, char name[]) {
	while(head != NULL) {
		if(strcmp(head->name, name) == 0) {
			head->quantity = head->quantity + 1; 
			printf("Product quantity increased by one. \n \n"); 
			return; 
		}
		else {
			head = head->next; 
		}
	}
	printf("Product not found. \n \n"); 
}

//decrease quantity of a product by one (if possible), if not, remove product from list
void sellProduct(struct node *head, char name[]) {
	struct node *headref = head; 
	while(head != NULL) {
		if(strcmp(head->name, name) == 0) {
			head->quantity = head->quantity - 1; 
			
			if(head->quantity == 0) {
				deleteNode(headref, head->name); 
				printf("Product has decreased by one and is now sold out. Product has been deleted from list. \n \n"); 
				free(headref); 
				return; 
			}
			
			printf("Product quantity decreased by one. \n \n"); 
			return; 
		}
		else {
			head = head->next; 
		}
	}
	printf("Product not found. \n \n"); 
}

int numProducts(struct node *head) {
	struct node *current = head->next; 
	int count = 0; 
	while(current != NULL) {
		count++; 
		current = current->next; 
	}
	return count; 
}