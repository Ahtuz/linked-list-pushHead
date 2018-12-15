#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

struct cake{
	char code[6];
	char name[25];
	int stock;
	int price;
	cake* next;
}*curr, *head = NULL;

void pushHead(char code[], char name[], int stock, int price){
	curr = (struct cake*) malloc (sizeof(struct cake));
	strcpy(curr->code,code);
	strcpy(curr->name,name);
	curr->price=price;
	curr->stock=stock;
	count++;

	if(head == NULL){
		curr->next=NULL;
		head=curr;
	}
	else{
		curr->next=head;
		head=curr;
	}
}

void view(){
	int ctr=1;
	curr=head;
	while(curr!=NULL){
		printf("%-4d | %-10s | %-25s | %-10d | Rp%d,-\n", ctr, curr->code, curr->name, curr->stock, curr->price);
		curr=curr->next;
		ctr++;
	}
}

void popAll(){
	curr=head;
	while(curr!=NULL){
		head=head->next;
		free(curr);
		curr=head;
	}
}

int main(){
	int choice;
	char codeTemp[6];
	int stockTemp;
	char nameTemp[25];
	int priceTemp;

	pushHead("CK023", "Strawberry ShortCake", 7, 17500);
	pushHead("CK017", "Mayonaise Cake", 24, 30000);
	pushHead("CK009", "Chocochip Cake", 5, 20000);
	pushHead("CK001", "Blueberry Cake", 13, 25000);

	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("BLUE CAKE SHOP CASHIER \n==========================\n\n\n");
		printf("No.  | Cake Code  | Cake Name                 | Available  | Price   \n");
		printf("------------------------------------------------------------------------\n");
		view();
		printf("------------------------------------------------------------------------\n");
		printf("Menu :\n");
		printf("1. Sell\n");
		printf("2. Add Stock\n");
		printf("3. Add Cake\n");
		printf("4. Exit\n");


		do{
			printf("Input choice :");
			scanf("%d", &choice); fflush stdin;
		}while(choice>4 || choice<1);

		

		switch(choice){
			case 1:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n");
				curr=head;
				printf("Input Cake Code [5 chars]:");
				scanf("%s", codeTemp); fflush stdin;

				for(int i=1;i<=count;i++){
					if(strcmp(codeTemp, curr->code)==0){
						printf("Input Quantity [0..%d]:", curr->stock);
						scanf("%d", &stockTemp); fflush stdin;
						curr->stock-=stockTemp;
						break;
					}
					else{
						curr=curr->next;
					}
				}

				curr=head;
				getchar();
				break;

			case 2:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n");
				curr=head;
				printf("Input Cake Code [5 chars]:");
				scanf("%s", codeTemp); fflush stdin;

				for(int i=1;i<=count;i++){
					if(strcmp(codeTemp, curr->code)==0){
						printf("Input Quantity [1..10]:");
						scanf("%d", &stockTemp); fflush stdin;
						curr->stock+=stockTemp;
						break;
					}
					else{
						curr=curr->next;
					}
				}

				curr=head;
				getchar();
				break;

			case 3:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n");

				curr=head;
				printf("Input Cake Code[6]:");
				scanf("%s", codeTemp); fflush stdin;
				printf("Input Cake Name[5..20]:");
				scanf("%s", nameTemp); fflush stdin;
				printf("Input Cake Avaliability[0..100]:");
				scanf("%d", &stockTemp); fflush stdin;
				printf("Input Cake Price[5000..100000]:");
				scanf("%d", &priceTemp); fflush stdin;

				pushHead(codeTemp, nameTemp, stockTemp, priceTemp);
				
				getchar();
				break;
		}

	}while(choice!=4);


	getchar();
	popAll();
	return 0;
}