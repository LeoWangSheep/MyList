#include "pch.h"
#include <iostream>
using namespace std;

struct myList {
	int val;
	myList* next;
	int length;
	myList(int num) :val(num),next(NULL),length(0) {};

	void create_list() {
		myList *tmp_node = this;
		int this_val = 0;
		cout << "please input the element of the list." << endl;
		while (cin >> this_val) {
			tmp_node->next = new myList(this_val);
			tmp_node = tmp_node->next;
			length++;
		}
	}

	int get_length() {
		return length;
	}

	void list_print_all() {
		myList *p = this->next;
		cout << "The elements of list is ";
		while (p != NULL) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void insert(int match_num,int new_num) {
		cout << "start to insert" << endl;
		myList *p = this;
		while (p != NULL) {
			if (p->val == match_num) {
				myList *new_node = new myList(new_num);
				new_node->next = p->next;
				p->next = new_node;
				length++;
				break;
			}
			else if (p->next == NULL) {
				p->next = new myList(new_num);
				length++;
				break;
			}
			p = p->next;
		}
	}

	void delete_node(int match_num) {
		cout << "start to delete" << endl;
		myList *p = this; // fast pointer
		myList *p2 = p; //slow pointer
		while (p != NULL) {
			if (p->val == match_num) {
				p2->next = p2->next->next;
				length--;
			}
			p2 = p;
			p = p->next;
		}
	}

	void reverse() {
		if (this == NULL) return;
		myList *next_node = this->next->next, *cur_node = this->next, *tmp_node;
		while (next_node != NULL) {
			tmp_node = next_node->next;
			next_node->next = cur_node;
			cur_node = next_node;
			next_node = tmp_node;
		}
		this->next->next = NULL;
		this->next = cur_node;
	}
};



int main()
{
	myList* dump = new myList(0);
	dump->create_list();
	dump->list_print_all();
	cout << "The length of the list is " << dump->get_length() << endl;
	dump->insert(2,100);
	dump->list_print_all();
	cout << "The length of the list is " << dump->get_length() << endl;
	dump->delete_node(1);
	dump->list_print_all();
	cout << "The length of the list is " << dump->get_length() << endl;
	dump->reverse();
	dump->list_print_all();
	cout << "The length of the list is " << dump->get_length() << endl;
	return 0;
}


