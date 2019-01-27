// Importing Libraries
#include <iostream>

using namespace std;

class Node{
	public:
	//data members
	int data;
	Node * next;
	// constructor to assign the value and set next null
	Node(int val){
		data = val;
		next = NULL;
	}
};

class cll{
	public:
	Node * head;
	cll(){
		head = NULL;
	}
	
	void insert(int val){
		Node *temp=new Node(val);
		// create first element if list is empty
		if(head==NULL){
			head = temp;
			head -> next = head;
		}
		// add element to the "end" if list exits
		else{
			Node * cur =head;
			// make cur point to the last item
			while(cur->next!=head)	
				cur=cur->next;
			// add the new item to the list
			temp ->next= cur->next;
			cur->next = temp;
		}
	}
	void insertAt(int pos, int val){
		Node *temp=new Node(val);
		if(pos==1){
			temp->next=head->next;
			Node * cur =head;
			// make cur point to the last item
			while(cur->next!=head)	
				cur=cur->next;
			cur->next=temp;
			head = temp;
		}
		else{
			Node * cur =head;
			// make cur point to the item one before the pos 
			for (int i = 1;i<pos-1;i++)	
				cur=cur->next;
			// insert the item in the list
			temp->next=cur->next;
			cur->next=temp;
		}
	}
	//displays the list.
 	void display(){
 	       Node * cur = head;
 	       if(cur == NULL){
 	       		cout << "No elements " << endl;
 			return;
 	       }
 	       while(cur->next != head){ 
 	       //stop at head
 	       cout << cur -> data << "->";
 	       cur = cur -> next; 
 	       }
		//print the last element
		cout << cur -> data ;
		cout << endl;
	    }
	void delet(){
		Node*last=head;
		Node*cur=head;
		// make last point to the last item
		while(last->next!=head)	
			last=last->next;
		// make cur point to one before the last item
		while(cur->next!=last)	
			cur=cur->next;
		cur->next = head;
		last->next=NULL;
		delete last;	
	}
	void deleteAt(int pos){
		if(pos==1){
			Node * temp = head;
			head = head->next;
			Node*last=head;
			// make last point to the last item
			while(last->next!=head)	
				last=last->next;
			last ->next = head;
			temp->next=NULL;
			delete temp;			
		}
		else{
			Node * cur =head;
			// make cur point to the item one before the pos 
			for (int i = 1;i<pos-1;i++)	
				cur=cur->next;
			Node*temp=cur->next;
			cur->next=cur->next->next;
			temp->next=NULL;
			delete temp;
		}
	}
	int count(){
		Node * cur = head;
		if(head==NULL){
			return 0;
		}
		else{
			int n=1;
			while(cur->next!=head){
				n++;
				cur=cur->next;
			}
			return n;
		}
	}	
};


// Main Function
int main(){
	// To-Do
	cll cll1;
	for(int i = 1; i<6;i++)
		cll1.insert(i*i);
	cll1.display();
	cll1.delet();
	cll1.display();
	cll1.insertAt(2,0);
	cll1.display();
	cll1.deleteAt(2);
	cll1.display();
	cout<<"\nNumber of items = "<<cll1.count()<<endl;
	return 0;
}
