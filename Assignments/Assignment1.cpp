
/* 
	-------   Practical no 1 : Arrays--------------

	Name : Nikheel C Khadakabhavi
	PRN : 202401110020
	Batch : A1

	-----------------------------------------------
*/
#include<iostream>
using namespace std;

void menu();
void marks_init();
void Insertion();
void updation();
void deletion();
void result();
void Display();


const int no_of_Assignment = 10;
int marks[no_of_Assignment];
int size = 0;

void menu(){
	cout << "----Student Marks Analysis System----" << endl ;
	cout << "	1. Insert marks " << endl;
	cout << "	2. Update marks" << endl;
	cout << "	3. Delete marks" << endl;
	cout << "	4. Display Student marks and result" <<endl;
	cout << "	5. Exit" << endl;
	cout << "-------------------------------------"<<endl;
	cout <<endl;

	cout << "Enter your choice: ";
}

void marks_init(){
	
	cout << "Total Number of Assignments : " << no_of_Assignment << endl;
	cout << "Enter the number of Assignments Submitted (max " << no_of_Assignment << ") : " ;
	cin >> size;

	if (size > no_of_Assignment) size = no_of_Assignment;

	//input
	cout << "Enter " << size << " Assignments marks (out of 10): ";
	for (int i = 0; i < size; i++)
	{
		cin >> marks[i];
	}

	//marks display
	cout << size << " Assignments marks : " ;
	for (int i = 0; i < size; i++)
	 {
	 	cout << marks[i] << " ";
	 } 

	 cout << endl;
}

void Insertion(){
	if (size >= no_of_Assignment){
		cout << " Marks Array is Full! . cannot insert more marks."<<endl;
		return;
	}

	int mark;
	cout << "Enter recent Assignment marks to insert : ";
	cin >> mark;

	marks[size]=mark;
	size++;

	cout <<mark << " Successfully inserted into the marks Array.!" << endl;
}


void deletion(){
	int mark;
	cout << "Enter Assignment marks to delete from Marks Array: ";
	cin >> mark;

	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (marks[i] == mark)
		{
			index = i;
			break;
		}
	}

	if (index != -1){
		for (int i = index; i < size-1; i++)
		{
			marks[i] = marks[i + 1];
		}
		size--;

		cout << mark << " deleted Successfully.! From Marks Array ." << endl;
	}else{
		cout << mark <<  " marks not Obtained Yet!!!" << endl;
	}
}


void updation(){
	int mark,position;
	cout << "Enter position (0-based) and re-Assignment mark to update in marks Array : ";
	cin >> position >> mark;

	if (position < 0 || position > size)
	{
		cout << "Invalid position."<<endl;
		return;
	}

	marks[position]=mark;
	cout << "Re-Assignment marks updated at position -> " << position <<endl;
}

void result(){
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += marks[i];
	}

	cout << sum << " marks obtained out of " << size*10 << endl;
	cout << "Checking........... result "<<endl;

	double min = size*10*0.4; // min marks 40%

	if (sum < min && sum >= 0)
	{
		cout << "Student Failed!!!!!!!!! , Give the re-Assignment to pass." << endl;
	}else{
		cout << "Student Passed in all Assignments. Congrats...."<< endl;
	}
}
void Display(){

	if (size == 0)
	{
		cout << "Marks Array is Empty!!."<<endl;
		return;
	}

	cout << "Student Marks In "<< size << " Assignments : ";

	for (int i = 0; i < size; i++)
	{
		cout << marks[i] << " ";	
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	marks_init();
	int choice;
	do
	{
		cout << endl;
		menu();
		cin >> choice;

		switch (choice){
		case 1 : 
			Insertion();
			break;

		case 2 :
			updation();
			break;

		case 3 :
			deletion();
			break;

		case 4 :
			Display();
			result();
			break;

		case 5 :
			cout << "\nProgram Terminated !! .." << endl;
			break;

		default :
			cout << "Invalid choice ,, !" << endl;
			break;
		}
	} while (choice != 5);


	return 0;
}



//Output

/*
	Total Number of Assignments : 10                                                                                             
	Enter the number of Assignments Submitted (max 10) : 6                                                                       
	Enter 6 Assignments marks (out of 10): 4 6 9 8 7 9                                                                           
	6 Assignments marks : 4 6 9 8 7 9                                                                                            
	                                                                                                                             
	----Student Marks Analysis System----                                                                                        
	        1. Insert marks                                                                                                      
	        2. Update marks                                                                                                      
	        3. Delete marks                                                                                                      
	        4. Display Student marks and result                                                                                  
	        5. Exit                                                                                                              
	-------------------------------------                                                                                        
	                                                                                                                             
	Enter your choice: 1                                                                                                         
	Enter recent Assignment marks to insert : 8                                                                                  
	8 Successfully inserted into the marks Array.!                                                                               
	                                                                                                                             
	----Student Marks Analysis System----                                                                                        
	        1. Insert marks                                                                                                      
	        2. Update marks                                                                                                      
	        3. Delete marks                                                                                                      
	        4. Display Student marks and result                                                                                  
	        5. Exit                                                                                                              
	-------------------------------------                                                                                        
	                                                                                                                             
	Enter your choice: 2                                                                                                         
	Enter position (0-based) and re-Assignment mark to update in marks Array : 0 8                                               
	Re-Assignment marks updated at position -> 0                                                                                 
	                                                                                                                             
	----Student Marks Analysis System----                                                                                        
	        1. Insert marks                                                                                                      
	        2. Update marks                                                                                                      
	        3. Delete marks                                                                                                      
	        4. Display Student marks and result                                                                                  
	        5. Exit                                                                                                              
	-------------------------------------                                                                                        
	                                                                                                                             
	Enter your choice: 3                                                                                                         
	Enter Assignment marks to delete from Marks Array: 6                                                                         
	6 deleted Successfully.! From Marks Array .                                                                                  
	                                                                                                                             
	----Student Marks Analysis System----                                                                                        
	        1. Insert marks                                                                                                      
	        2. Update marks                                                                                                      
	        3. Delete marks                                                                                                      
	        4. Display Student marks and result                                                                                  
	        5. Exit                                                                                                              
	-------------------------------------                                                                                        
	                                                                                                                             
	Enter your choice: 4                                                                                                         
	Student Marks In 6 Assignments : 8 9 8 7 9 8                                                                                 
	49 marks obtained out of 60                                                                                                  
	Checking........... result                                                                                                   
	Student Passed in all Assignments. Congrats....                                                                              
	                                                                                                                             
	----Student Marks Analysis System----                                                                                        
	        1. Insert marks                                                                                                      
	        2. Update marks                                                                                                      
	        3. Delete marks                                                                                                      
	        4. Display Student marks and result                                                                                  
	        5. Exit                                                                                                              
	-------------------------------------                                                                                        
	                                                                                                                             
	Enter your choice: 5                                                                                                         
	                                                                                                                             
	Program Terminated !! ..  
*/