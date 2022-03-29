#include<stdio.h>

int login();
void checkbalance(int);
void withdraw(int);
void deposite(int);
void thanku(int);
void thank();

int id[5]={1,2,3,4,5};
int pin[6]={0,111,222,333,444,555};
int balance[6]={0,1000,2000,3000,4000};

int main()
{
	int op;
	int u=login();
	if(u>0)
	{
		printf("user %d logged in\n\n", u);
		do
		{
			printf("\nWhat do you want to do\nEnter 1 for balance enquiry\nEnter 2 for cash widraw\nEnter 3 for cash deposite\nEnter 4 for exit\n");
			scanf("%d",&op);
			if(op==1)
			{
				checkbalance(u);
			}
			else if(op==2)
			{
				withdraw(u);
			}
			else if(op==3)
			{
				deposite(u);
			}
			else if(op==4)
			{
				thanku(u);
			}	
			else
			{
				printf("Invalid input\n");
			}
		}while(op!=4);
	}
	else
	{
		printf("Card Blocked\n");
	}
return 0;
}

int login()
{
	int id, pass, chance=3;
	printf("Enter your account id\n");
	scanf("%d",&id);
	if(id<6)
	{
		do
		{
			printf("Enter pin\n");
			scanf("%d", &pass);
			if(pass!=pin[id])
			chance--;
		}
		while(pass!=pin[id] && chance>0);
		if(chance==0)
		{
			return 0;
		}
		else
		{
			return id;		
		}	
	}
	else
	{
		printf("Invalid User\n");
		thank();
		return 0;
	}
}


void checkbalance(int a)
{
	printf("Balance of user %d id %d\n", a, balance[a]);	
}

void withdraw(int a)
{
	int amount;
	printf("Enter amount:\n");
	scanf("%d", &amount);
	if(balance[a]<amount)
	{
		printf("insufficient balance\n");	
	}
	else
	{
		balance[a]=balance[a]-amount;
		printf("withdraw successfull\n");
	}
}


void deposite(int a)
{
	int amount;
	printf("enter amount \n");
	scanf("%d", &amount);
	balance[a]=balance[a]+amount;
}

void thanku(int a)
{
	printf("Thank You for banking with us %d\nVisit Again\n", a);	
}
	
void thank()
{
	printf("Thank You for banking with us \nVisit Again\n");
}
