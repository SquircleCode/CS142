// Importing Libraries
#include <iostream>
using namespace std;

class Node{
	public:
	//data
	int data;
	//pointer to next node
	Node * next;
	//pointer to previos node
	Node * prev;
	//constructor to make pointer null
	Node(int value){
		next=NULL;
		data = value;
		prev = NULL;
	}
};


class DLL{
	public:
	//head 
	Node * head;
	//constructor to make head null
	DLL(){
		head=NULL;
	}
	//insert
	void insert(int val){
		//create a node
		Node * temp = new Node(val);
		//if its the 1st item, make it the head
		if(head==NULL){
			head = temp;
		}
		//if not link it to the last item
		else{
			Node * current = head;
			while(current->next!=NULL)
				current = current->next;
			current->next=temp;
			temp->prev=current;
		}
	}
	//delete
	void delet(){
		//point to the node just before the end
		Node * current=head;		
		Node * tail=head;
		while(tail->next!=NULL)
			tail=tail->next;
		while(current->next!=tail)
			current=current->next;
		//remove the tail from the list
		tail->prev=NULL;
		current->next=NULL;
		delete tail;
		// set the new tail
		tail = current;	
		
	}
	//display
	void display(){
		Node * current = head;
		while(current!=NULL){
			cout << current->data << " -> " ;
			current = current->next;
		}
		cout<<"NULL"<<endl;
	}
	//deleteAt
	void deleteAt(int pos){
		// get to the item before the one to be deleted
		Node * current = head;
		for(int i =1; i<pos-1;i++)
			current = current->next;
		// if pos is 1
		Node * temp;
		if(pos==1){
			head = head->next;
			current ->next = NULL;
			delete current;
		}
		// otherwise
		else{
			temp = current->next;
			current->next=temp->next;
			temp->next->prev=current;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
		}
	}
	//insertAt
	 void insertAt(int pos, int val){
		// reach one before pos
		Node * current = head;
		for(int i = 1 ; i<pos-1; i++)
			current = current -> next;
		// create new node
		Node * temp = new Node(val);
		// for adding at the 1st pos,link the node to the head and make it the new head
		if(pos==1){
			temp -> next = head;
			head->prev = temp;
   			head = temp;
  		}
  		//add the node to the list
  		else{
  			temp -> next = current -> next;
  			current->next->prev=temp;
   			current -> next = temp;
  		}
	}
	int countItems(){
		int n =0;
		Node * cur = head;
		for(;cur!=NULL;n++)
			cur=cur->next;
		return n;
	}
	
};

// Main Function
int main(){
	// To-Do
	DLL dll;
	dll.insert(1);
	dll.insert(2);
	dll.insert(2);
	dll.insert(4);
	dll.display();
	dll.deleteAt(2);
	dll.display();
	dll.insertAt(3,3);
	dll.display();
	dll.delet();
	dll.display();
	cout<<"Number of items = "<<dll.countItems();
	return 0;
}


