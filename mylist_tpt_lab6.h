// Abdul Wahab
// Lab 6

#include <stdexcept>
#include <iostream>
#include <cassert>

using namespace std;
template<class T> class mylist;

template<class T>
ostream& operator<<(ostream& out, const mylist<T>&l);

template <typename T>
class mylist {
public:

	struct node {
		T data;
		node* next_ptr;
		node(const T&d, node* n):data(d),next_ptr(n){}
	};
	node* head_ptr;
	friend ostream& operator<<  <>(ostream& out, const mylist<T>&l);

	
	class iterator {
		node* ptr;
	public:
		
		iterator(node*p):ptr(p){}
		
		iterator next(){return ptr->next_ptr;}
		
		T& operator*(){return ptr->data;}
		
		bool operator!=(const iterator& other){return ptr!=other.ptr;}
		
		iterator operator++(){ptr=ptr->next_ptr; return *this;}
	};
	
public:	
	
	unsigned length(node* n)
	{
		if(n == nullptr)
			return 0;
		return 1 + length(n->next_ptr);
	}
	
	
	void del_list(node* &h)
	{
		if(h == nullptr)
			return;	
		del_list(h->next_ptr);
		delete h;
		h = nullptr;
	}	
	
	
	mylist():head_ptr(0) {}
	
	
	iterator begin(){return iterator(head_ptr);}
	
	
	iterator end(){return iterator(nullptr);}
	
	
	unsigned length() {return length(head_ptr);}
	
	
	~mylist() {
		del_list(head_ptr);
	}

	T& at(unsigned i){
		if (!head_ptr) {
			throw out_of_range("ERROR: There are not enough elements");
		}
		return at(head_ptr, i);
	}
	
	T& at(node * head, unsigned i) {
		if (i >= length()) {
			throw out_of_range("ERROR: The index is larger than the length of list");
		}

		if (i == 0) {
			return head->data;
		}
		else {
			return at(head->next_ptr, --i);
		}
	}
	
	T& operator[](unsigned i){
		return at(i);
	}	

	T sum_all(void) const {
		return sum_all(head_ptr);
	}

	T sum_all(node *head) const {
		if (head) {
			return head->data + sum_all(head->next_ptr);
		}
		else {
			return "";
		}
	}
	
	bool contains(const T&elem) const {
		if (head_ptr) {
			return contains(elem, head_ptr);
		}
		return false;
	}

	
	bool contains(const T&elem, node *head) const {
		if (!head) {
			return false;
		}
		else {
			if (head->data == elem) {
				return true;
			}
			else {
				return contains(elem, head->next_ptr);
			}
		}
	}

	T largest(void) const {
		if (!head_ptr) {
			throw domain_error("ERROR: List is empty");
		}
		return largest(head_ptr, head_ptr);
	}


	T largest(node *first, node *second) const {
		if (first && second) {
			if (first->data.compare(second->data) == 0 || first->data.compare(second->data) > 0) {
				return largest(first, second->next_ptr);
			}
			else {
				return largest(first->next_ptr, second);
			}
		}
		else {
			if (!second) {
				return first->data;
			}
			else {
				return second->data;
			}
		}
	}
	
	T smallest(void) const {
		if (!head_ptr) {
			throw domain_error("ERROR:List is empty");
		}
		return smallest(head_ptr, head_ptr);	
	}

	

	T smallest(node *first, node *second) const {
		if (first && second) {
			if (first->data.compare(second->data) == 0 || first->data.compare(second->data) > 0) {
				return smallest(first->next_ptr, second);
			}
			else  {
				return smallest(first, second->next_ptr);
			}
		}
		else  {
			if (!second) {
				return first->data;
			}
			else  {
				return second->data;
			}
		}
	}

	void push_front(const T& data) {
		head_ptr=new node(data,head_ptr);
	}
	
	bool empty() { return head_ptr==0;}
	

	void push_back(const T&data) {
		if(empty())
			push_front(data);
		
		node* last_ptr=head_ptr;
		while(last_ptr->next_ptr != 0)
			last_ptr=last_ptr->next_ptr;
	       last_ptr->next_ptr=new node(data,0);
	}
	
	void print_all(void) {
		cout << "mylist{";
		for(node*current_ptr=head_ptr;  
				current_ptr!=0; 
				current_ptr=current_ptr->next_ptr){
			cout << current_ptr->data << " ";
		}
		cout <<"}";
	}
};
