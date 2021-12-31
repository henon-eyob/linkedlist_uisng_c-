#include <iostream>
#include <stdlib.h>
#include <string.h>
//this is maximum number of client that ethiopian electric and corporation can handle in daily working time
#define SIZE 20
using namespace std;

/*
    programmed by Henon Eyob
    section RD2CE1 REGULAR COMPUTER ENGINEERING
    Datastrucre and Algorithm assignment
    id 13,177/19
*/
class ElectricService
{
	private:
	    long id;
	struct node
	{
		char userName[20];
		long userId;
		struct node* next;
		struct node* prev;
	};
	public:
		ElectricService()
		{
			id = 0;	
		}
	
	struct node* head = NULL;
	struct node* end = NULL;
		
	//check if it is full by comparing the id with the constant SIZE 
	bool isFull()
	{
		if( id == SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//check if it is empty by comparing the id with the constant SIZE
	bool isEmpty()
	{
		if(id == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//this function will add the client on the linked list and has two parameter name and the length of the name
	void addClient(char name[20], int lenName)
	{
		if(isFull())
		{
			cout<<"the queue is full for daily service "<<endl;
		}
		else
		{
			id++;
			struct node* newClient = (struct node*)malloc(sizeof(struct node));
			for(int i=0;i<lenName;i++)
			{
				newClient->userName[i]=name[i];	
			}
			newClient->userId = id;
			newClient->prev = end;
			newClient->next = NULL;
			if(end == NULL)
			{
				head = newClient;
			}
			else
			{
				end->next= newClient;
			}
			end = newClient;
			cout<<"your id number is "<<id<<endl;
		}
	}
	
	//this function will remove the first client 
	void removeFirstClient()
	{
		head = head -> next;
	}
	
	//this function will display the all cient in the queue
	void display()
	{
		if(isEmpty())
		{
			cout<<"the queue is empty there is no one"<<endl;
		}
		else
		{
			struct node* temp;
		cout<<"clients in the queue in order"<<endl;
		temp = head;
		while(temp!=NULL)
		{
			cout<<temp->userName<<endl;
			cout<<temp->userId<<endl;
			temp = temp ->next;
		}
		}
	}
	
	//this function will search if the client is on the queue or not and it will take the name as parameter
	void searchClient(string name)
	{
		struct node *temp;
		temp = head;
		long found = 0;
		int foundedClient=0;
	
		do
		{
			if(name == temp->userName)
			{
				found = 1;
				cout<<"the client is found and its id number is "<<temp->userId<<endl;
				break;
			}
			else
			{
				temp = temp ->next;
			}
		}while(temp != NULL);
		if(found == 0)
		{
			cout<<"there is no client with the name "<<name<<" in the queue"<<endl;
		}
	}
	
	//this will display the first client
	void displayFirstClient()
	{
		if(isEmpty())
		{
			cout<<"the queue is empty"<<endl;
		}
		else
		{
			cout<<"first person on the queue "<<endl;
			cout<<head->userName<<endl;
			cout<<head->userId<<endl;
		}
		
	}
};

int main()
{
	ElectricService elecBill;
	ElectricService elecCardBill;
	ElectricService maintenance;
	char clientName[20];
	char firstChoice;
	int lenName;

	while(firstChoice != 'x')
	{
		cout<<"  Enter which service do you want"<<endl;
		cout<<"          A.For lightning counter bill"<<endl;
		cout<<"          B.For lightning counter card bill"<<endl;
		cout<<"          C.For maintenance"<<endl;
		cout<<"*************************"<<endl;
		cout<<"     enter x to quit     "<<endl;
		cin>>firstChoice;
		switch(firstChoice)
		{
			case 'a':
				cout<<"enter your name"<<endl;
				cin>>clientName;
				lenName = strlen(clientName);
				elecBill.addClient(clientName,lenName);
				break;
			
			case 'b':
				cout<<"enter your name"<<endl;
				gets(clientName);
				lenName = strlen(clientName);
				elecBill.addClient(clientName,lenName);
				break;
				
			case 'c':
				cout<<"enter your name"<<endl;
				gets(clientName);
				lenName = strlen(clientName);
				elecBill.addClient(clientName,lenName);
				break;
				
			default:
				cout<<"invalid input"<<endl;
		}
	}
	
	
	elecBill.display();
	elecBill.displayFirstClient();
	elecBill.searchClient("henon");
	elecBill.removeFirstClient();
	/*
	elecCardBill.display();
	elecCardBill.displayFirstClient();
	elecCardBill.searchClient("abebe");
	
	maintenance.display();
	maintenance.displayFirstClient();
	maintenance.searchClient("adf");
	*/
}
