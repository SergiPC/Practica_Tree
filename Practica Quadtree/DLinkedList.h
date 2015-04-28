// --------------------------------------------
//             DLinkedList Class
// --------------------------------------------

#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#define NULL 0 // for not carrying the entire library

// node from a Double Linked List ----------------------
template<class kdata>
struct DListNode
{
	kdata				data;
	DListNode<kdata>*	next;
	DListNode<kdata>*	prev;

	// Constructor -----------------------------------------
	inline DListNode(const kdata& new_data)
	{
		data = new_data;
		next = prev = NULL;
	}

	// Destructor ------------------------------------------
	~DListNode()
	{}
};


// Manages a double linked list ------------------------
template<class kdata>
class DLinkedList
{
public:

	DListNode<kdata>*	head;
	DListNode<kdata>*	bottom;

private:

	unsigned int	size;

public:

	// Constructor -----------------------------------------
	DLinkedList()
	{
		head = bottom = NULL;
		size = 0;
	}

	// Destructor ------------------------------------------
	~DLinkedList()
	{
		delAll();
	}

	// Get size counter ------------------------------------
	unsigned int count()
	{
		return(size);
	}

	// Add new node at bottom ------------------------------
	unsigned int addNode(const kdata& new_data)
	{
		DListNode<kdata>*	new_node;
		new_node = new DListNode<kdata>(new_data);
		if (head == NULL)
		{
			head = bottom = new_node;
		}
		else
		{
			new_node->prev = bottom;
			bottom->next = new_node;
			bottom = new_node;
		}
		return(++size); // ++size increments size and returns the incremented number
	}

	// Deletes an item -------------------------------------
	bool delNode(const DListNode<kdata>* node)
	{
		if (node == NULL)
		{
			return false;
		}

		if (node->prev != NULL)
		{
			node->prev->next = node->next;
			if (node->next != NULL)
			{
				node->next->prev = node->prev;
			}
			else
			{
				bottom = node->prev;
			}
		}
		else
		{
			if (node->next) // only get in if node->next != NULL
			{
				node->next->prev = NULL;
				head = node->next;
			}
			else
			{
				head = bottom = NULL;
			}
		}
		delete node;
		--size;
		return true;
	}


	// Delete some nodes -----------------------------------
	unsigned int delNodes(int posicio, int num_nodes)
	{
		unsigned int deletedNodes = 0;
		DListNode<kdata>*	tmp_node;
		DListNode<kdata>*	tmp_next;
		tmp_node = head;
		unsigned int needed_size = num_nodes + posicio;

		for (int i = 0; i < posicio; i++) // per trobar el node
		{
			tmp_node = tmp_node->next;
		}

		if (tmp_node == NULL)
		{
			return deletedNodes;
		}

		if (needed_size > size)
		{
			num_nodes = size - posicio;
		}

		for (int p = 0; p < num_nodes; p++)
		{
			if (tmp_node->prev != NULL)
			{
				tmp_node->prev->next = tmp_node->next;
				if (tmp_node->next != NULL)
				{
					tmp_node->next->prev = tmp_node->prev;
				}
				else
				{
					bottom = tmp_node->prev;
				}
			}
			else
			{
				if (tmp_node->next) // only get in if tmp_node->next != NULL
				{
					tmp_node->next->prev = NULL;
					head = tmp_node->next;
				}
				else
				{
					head = bottom = NULL;
				}
			}
			tmp_next = tmp_node->next;
			delete tmp_node;
			tmp_node = tmp_next;
			--size;
		}
		return deletedNodes;
	}

	// Destroy and free for all! ---------------------------
	void delAll()
	{
		DListNode<kdata>*	tmp_data;
		DListNode<kdata>*	tmp_next;
		tmp_data = head;

		while (tmp_data != NULL)
		{
			tmp_next = tmp_data->next;
			delete tmp_data;
			tmp_data = tmp_next;
		}
		head = bottom = NULL;
		size = 0;
	}

	// read / write operator access directly to a position in the list
	kdata& operator  [](const unsigned int number)
	{
		long                position;
		DListNode<kdata>*	position_number;
		position = 0;
		position_number = head;

		while (position_number != NULL)
		{
			if (position == number)
			{
				break;
			}

			++position;
			position_number = position_number->next;
		}
		return(position_number->data);
	}

	// returns the first apperance of data as count (-1 if not found)
	int find(const kdata& old_data)
	{
		DListNode<kdata>* tmp = head;
		int count = 0;

		while (tmp != NULL)
		{
			if (tmp->data == old_data)
			{
				return(count);
			}
			++count;
			tmp = tmp->next;
		}
		return (-1);
	}
};

#endif // __DLINKEDLIST_H__