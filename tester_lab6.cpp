#include <iostream>
#include <vector>
#include <string>
#include "mylist_tpt_lab6.h"

// Abdul Wahab
// Lab 6

using namespace std;

template <typename T>
void printVec(vector<T>& v)
{
	cout << "( "; 
	for(unsigned i=0; i<v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout<<")";
}

int main(void)
{
	int errors=0;
	// Single-linked list methods using RECURSION
	cout << boolalpha <<"TESTING LINKED LIST RECURSIVE METHODS" << endl;
	mylist<string> l;
	
	// test AT
	cout << "\nTESTING AT METHOD" << endl;
	try {
		l.at(0);
		++errors;
		cout << "\tAT for empty list does NOT throw out of range exception. (INCORRECT)" << endl;
	}
	catch (out_of_range &oor) {
		cout << "\tAT for empty list throws out of range exception. (CORRECT)" << endl;
	}
	
	cout << "\tPushing 3 elements on to list. ( Orlando, jane, joe )" << endl;
	l.push_front("joe");
	l.push_front("jane");
	l.push_front("Orlando");
		
	cout <<endl<< "\tThe list created was "; 
	l.print_all();
	cout<<endl;
	
	if (l.at(0) == "Orlando")
		cout << "\tElement at index 0 == \"Orlando\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tElement at index 0 is " << l.at(0) <<" != \"Orlando\". (INCORRECT)" << endl;
	}
	if (l.at(1) == "jane")
		cout << "\tElement at index 1 == \"jane\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tElement at index 1 is " << l.at(1) <<" != \"jane\". (INCORRECT)" << endl;
	}
	if (l.at(2) == "joe")
		cout << "\tElement at index 2 == \"joe\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tElement at index 2 is " << l.at(2) <<" != \"joe\". (INCORRECT)" << endl;
	}	
		
	// test SUM_ALL
	cout << "\nTESTING SUM_ALL METHOD" << endl;
	l.del_list(l.head_ptr);
	l.head_ptr = nullptr;
	
	if (l.sum_all() == "")
		cout << "\tSum of empty list of strings is empty string. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tSum of empty list of strings is "<< l.sum_all() << " != empty string. (INCORRECT)" << endl;
	}
	cout << "\tPushing 3 elements on to list." << endl;
	l.push_front("joe");
	l.push_front("jane");
	l.push_front("Orlando");
	
	cout <<endl<< "\tThe list created was "; 
	l.print_all();
	cout<<endl;
		
	if (l.sum_all() == "Orlandojanejoe")
		cout << "\tSum of list of strings == \"Orlandojanejoe\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tSum of list of strings " << l.sum_all() <<" != \"Orlandojanejoe\". (INCORRECT)" << endl;
	}
	
	// test CONTAINS
	cout << "\nTESTING CONTAINS METHOD" << endl;
	l.del_list(l.head_ptr);
	l.head_ptr = nullptr;
	
	if (l.contains("joe"))
	{
		++errors;
		cout << "\tEmpty list of strings contains \"joe\" == TRUE. (INCORRECT)" << endl;
	}
	else
		cout << "\tEmpty list of strings does not contain \"joe\" == FALSE. (CORRECT)" << endl;
		
	cout << "\tPushing 3 elements on to list." << endl;
	l.push_front("joe");
	l.push_front("jane");
	l.push_front("Orlando");
	
	cout <<endl<< "\tThe list created was "; 
	l.print_all();
	cout<<endl;
	
	if (l.contains("joe"))
		cout << "\tList of strings contains \"joe\" == TRUE. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tList of strings does not contain \"joe\" == "<<l.contains("joe") << " != FALSE. (INCORRECT)" << endl;
	}
	if (l.contains("john"))
	{
		++errors;
		cout << "\tList of strings contains \"john\" == "<<l.contains("john") << " != TRUE. (INCORRECT)" << endl;
	}
	else
		cout << "\tList of strings does not contain \"john\" == FALSE. (CORRECT)" << endl;
	
	
	
	// test LARGEST
	cout << "\nTESTING LARGEST METHOD" << endl;
	l.del_list(l.head_ptr);
	l.head_ptr = nullptr;
	
	try {
		l.largest();
		++errors;
		cout << "\tLARGEST for empty list does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tLARGEST for empty list throws domain error exception. (CORRECT)" << endl;
	}
	cout << "\tPushing 3 elements on to list." << endl;
	l.push_front("Orlando");
	l.push_front("joe");
	l.push_front("jane");
	
	cout <<endl<< "\tThe list created was "; 
	l.print_all();
	cout<<endl;
	
	if (l.largest() == "joe")
		cout << "\tLargest element of list == \"joe\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tLargest element of list is " << l.largest() << " != \"joe\". (INCORRECT)" << endl;
	}
	
	// test SMALLEST
	cout << "\nTESTING SMALLEST METHOD" << endl;
	l.del_list(l.head_ptr);
	l.head_ptr = nullptr;
	
	try {
		l.smallest();
		++errors;
		cout << "\tSMALLEST for empty list does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tSMALLEST for empty list throws domain error exception. (CORRECT)" << endl;
	}
	cout << "\tPushing 3 elements on to list." << endl;
	l.push_front("Orlando");
	l.push_front("joe");
	l.push_front("jane");

	cout <<endl<< "\tThe list created was "; 
	l.print_all();
	cout<<endl;
	
	if (l.smallest() == "Orlando")
		cout << "\tSmallest element of list == \"Orlando\". (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tSmallest element of list is " << l.smallest() << " != \"Orlando\". (INCORRECT)" << endl;
	}
	

	cout<<endl<<"Failed "<<errors<<" out of the total test cases"<<endl;
	system("pause");
}
