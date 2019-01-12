// Importing Libraries
#include <iostream>
using namespace std;

class Node{
	public:
	//data
	int data;
	//pointer to next node
	Node * next;
	//constructor to make pointer null
	Node(){
		next=NULL;
	}
};


class LinkedList{
	public:
	//head and tail
	Node * head;
	Node * tail;
	//constructor to make head and tail null
	LinkedList(){
		head=NULL;
		tail=NULL;	
	}
	//insert
	void insert(int val){
		//create a node
		Node * temp = new Node;
		//assign value
		temp->data=val;
		//if its the 1st item, make it the head
		if(head==NULL)
			head = temp;
		//if not link it to the last item
		else
			tail->next=temp;
		//update the tail	
		tail = temp;
	}
	//delete
	void delet(){
		//point to the node just before the tail
		Node * current=head;		
		while(current->next!=tail)
			current=current->next;
		//remove the tail from the list
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
			temp->next = NULL;
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
		Node * temp = new Node;
		// store the value in the node
		temp -> data = val;
		// for adding at the 1st pos,link the node to the head and make it the new head
		if(pos==1){
			temp -> next = head;
   			head = temp;
  		}
  		//add the node to the list
  		else{
  			temp -> next = current -> next;
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
	LinkedList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(2);
	ll.insert(4);
	ll.display();
	ll.deleteAt(2);
	ll.display();
	ll.insertAt(3,3);
	ll.display();
	ll.delet();
	ll.display();
	cout<<"Number of items = "<<ll.countItems();
	return 0;
}


