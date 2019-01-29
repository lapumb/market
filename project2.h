#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#ifndef PROJECT2_H
#define PROJECT2_H

struct node {
	char name[100];
	char unit[100];
	int price; 
	int quantity; 
	struct node *next;
}; 

struct node *init (); //initialize: create an empty head node (whose "data" is intentionally missing); This head node will not be used to store any data;

void insert(struct node *head, char inputName[], char inputUnit[], int price, int quantity); //Create a new node to store data and insert it to the end of current linked list; the head node will still be empty and data in the array in "main.c" are not stored in head node

void display (struct node *head); //print data for all nodes in the linked list except the head node (which is empty)

void deleteAll (struct node *head); //delete the entire linked list including the head node

void deleteNode(struct node *head, char name[]); //delete a specified product

void searchProduct(struct node *head, char name[]); //see if a product exists

void purchaseProduct(struct node *head, char name[]); //increase a products quantity by one

void sellProduct(struct node *head, char name[]); //decrease a products quantity by one (if quantity > 0)

int numProducts(struct node *head); //gets the number of products in the linked list (purpose is to get number to write to file) 

#endif

