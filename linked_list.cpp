#include <iostream>

class NODE
{
public:
	NODE()
	{
		data = 0;
	}

	NODE(int x)
	{
		data = x;
	}

private:
	int data;
	NODE* next = NULL;
};

class 
linked_list
{
private:
	NODE* head = new NODE();
	NODE* tail = new NODE(0);
	NODE* temp; 
	NODE* temp2;

public:
	// constructor, links tail to head
	linked_list() 
	{
		head->data = 0;
		tail->next = head;
		head->next = NULL;
	}

	// parametered constructor
	linked_list(int num) 
	{
		head->data = num;
		tail->next = head;
		head->next = NULL;
	}


	/*
	// Function that prints every nodes value. O(n)
	*/
	void 
	print_ll()
	{
		temp = tail;

		while (temp != head)
		{
			std::cout << temp->next->data << std::endl;
			temp = temp->next;
		}
	}	


	/*
	// Function adds a new node to top of linkedlist, makes it new head. O(1)
	// @param value is new nodes value
	*/
	void 
	add_node(int value)
	{
		NODE* node = new NODE(value);
		head->next = node;
		head = node;	
	}


	/* 
	// Function inserts a new node to choosen index. O(n)
	// @param index is new nodes index, @param value is new nodes value
	*/
	void 
	insert_node(int index, int value)
	{
		NODE* node = new NODE(value);

		temp = tail;
		while(index-- != 0)
		{
			temp = temp->next;
		}

		temp2 = temp->next;
		temp->next = node; 

		node->next = temp2;

	}
};

int 
main()
{
    linked_list exp(3);
    
    exp.insert_node(0, 1);  // index, num
    
    exp.add_node(5);
    exp.add_node(7);

    exp.print_ll();

    return 0;
}

