// Importing Libraries
#include <iostream>

using namespace std;
	

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition(int*arr,int l,int h){
	int j = h-1;
	for(int i = l;i<=h;i++){
		if(*(arr+i)>*(arr+h)){
			swap(arr+i,arr+j);
			j--;	
		}	
	}
	swap(arr+h,arr+j+1);
	return j+1;
}

//quicksort
void qs(int *arr, int l, int h){
	if(l<h){
	//pivot
		int p;
		//partiton
		p = partition(arr,l,h);
		qs(arr,l,p-1);
		qs(arr,p+1,h);
	}
}

// Main Function
int main(){
	// To-Do
	int arr[]={2,8,5,4,0,2,7};
	for(int i = 0; i<7;i++)
		cout<<arr[i]<<" ";
	qs(arr,0,6);
	cout<<endl;
	for(int i = 0; i<7;i++)
		cout<<arr[i];
	
	return 0;
}


