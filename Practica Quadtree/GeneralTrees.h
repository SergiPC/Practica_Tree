// --------------------------------------------
//               Generic Tree
// --------------------------------------------
// http://www.rsbauer.com/class/dsa2/slides/General%20Trees.pdf


#ifndef __Tree_H__
#define __Tree_H__

#include "DLinkedList.h"
#include "Stack.h"

// Tree node -------------------------------------------
template<class kdata>
class TreeNode
{
public:
	kdata					data;
	TreeNode*				parent; // pointer for parent node
	DLinkedList<TreeNode*>	childs; // pointer for childs node

public:
	TreeNode(const kdata& new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void addChild(TreeNode* new_node)
	{
		childs.addNode(new_node);
		new_node->parent = this;
	}

	bool removeChild(TreeNode* old_node)
	{
		bool exit = false;
		DListNode<TreeNode*>* tmp = childs.head; // create a tmp to point to the first node

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;

			if (old_node == child)
			{
				childs.delNode(tmp);
				old_node->parent = NULL;
				exit = true;
				break;
			}
		}
		return exit;
	}

	// Pre order recursive ---------------------------------
	// 1) process root
	// 2) recursively process children from "left to right"
	void preOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		new_list->addNode(this);
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			tmp->data->preOrderRecursive(new_list);
		}
	}

	// Post order recursive --------------------------------
	// 1) no node is processed until all of its children have been processed
	// 2) process root
	void postOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			tmp->data->postOrderRecursive(new_list);
		}
		new_list->addNode(this);
	}

	// In order recursive ----------------------------------
	// half of the children, the root and the other half of the children
	void inOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		DListNode<TreeNode*>* tmp = childs.head;
		unsigned int middle = childs.count() / 2;

		for (unsigned int i = 0; i < middle; ++i, tmp = tmp->next)
		{
			tmp->data->inOrderRecursive(new_list);
		}
		new_list->addNode(this);

		for (; tmp != NULL; tmp = tmp->next)
		{
			tmp->data->inOrderRecursive(new_list);
		}
	}

	TreeNode<kdata>* findRecursive(const kdata& new_node)
	{
		if (new_node == data)
		{
			return this;
		}
		TreeNode<kdata>* result = NULL;
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;
			result = child->findRecursive(new_node);

			if (result != NULL)
			{
				break;
			}
		}
		return result;
	}

	void gatherAll(DLinkedList<TreeNode*>* new_list)
	{
		new_list->addNode(this);

		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;
			child->gatherAll(new_list);
		}
	}
};

// Tree class ------------------------------------------
template<class kdata>
class Tree
{
public:

	TreeNode<kdata>	root;

public:

	// Constructor -----------------------------------------
	Tree(const kdata& new_data) : root(new_data)
	{}

	// Destructor ------------------------------------------
	virtual ~Tree()
	{}

	void preOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		root.preOrderRecursive(new_list);
	}

	void postOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		root.postOrderRecursive(new_list);
	}

	void inOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		root.inOrderRecursive(new_list);
	}


	// Pre order iterative ---------------------------------
	// 1) process root
	// 2) recursively process children from "left to right"
	void preOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		Stack<TreeNode<kdata>*>	new_stack;
		TreeNode<kdata>*		new_node = &root;

		while (new_node != NULL || new_stack.pop(new_node))
		{
			new_list->addNode(new_node);
			DListNode<TreeNode<kdata>*>* tmp = new_node->childs.bottom;

			for (; tmp != new_node->childs.head; tmp = tmp->prev)
			{
				new_stack.pushBack(tmp->data);
			}

			if (tmp != NULL)
			{
				new_node = tmp->data;
			}
			else
			{
				new_node = NULL;
			}
		}
	}

	// Post order iterative --------------------------------
	// 1) no node is processed until all of its children have been processed
	// 2) process root
	void postOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		Stack<TreeNode<kdata>*>	new_stack;
		TreeNode<kdata>*		new_node = &root;

		while (new_node != NULL || new_stack.pop(new_node))
		{
			DListNode<TreeNode<kdata>*>* tmp = new_node->childs.bottom;

			if (tmp != NULL && new_list->find(tmp->data) == -1)
			{
				new_stack.pushBack(new_node);

				for (; tmp != new_node->childs.head; tmp = tmp->prev)
				{
					new_stack.pushBack(tmp->data);
				}
				new_node = tmp->data;
			}
			else
			{
				new_list->addNode(new_node);
				new_node = NULL;
			}
		}
	}

	// In order iterative ----------------------------------
	void inOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list)
	{
		bool work = true;
		Stack<TreeNode<kdata>*>	new_stack;
		TreeNode<kdata>*		new_node = &root;		

		while (work)
		{
			if (new_node != NULL)
			{
				if (new_list->find(new_node) == -1)
				{
					new_stack.pushBack(new_node);
				}
				if (new_node->childs.count() != 0)
				{
					new_node = new_node->childs.head->data;
				}
				else
				{
					new_node = NULL;
				}
			}

			else if (new_stack.count() > 0)
			{
				new_stack.pop(new_node);
				new_list->addNode(new_node);
				if (new_node->childs.count() != 0)
				{
					new_node = new_node->childs.bottom->data;
				}
				else
				{
					new_node = NULL;
				}
			}
			else
			{
				work = false;
			}
		}
	}
	
	void add(const kdata& new_data, const kdata& new_parent)
	{
		TreeNode<kdata>* p = root.findRecursive(new_parent);
		TreeNode<kdata>* new_node = new TreeNode<kdata>(new_data);
		p->addChild(new_node);
	}

	void add(const kdata& new_data)
	{
		TreeNode<kdata>* new_node = new TreeNode<kdata>(new_data);
		root.addChild(new_node);
	}

	void clear()
	{
		DLinkedList<TreeNode<kdata>*> results;
		root.gatherAll(&results);
		DListNode<TreeNode<kdata>*>* tmp = results.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode<kdata>* child = tmp->data;
			if (child->parent)
			{
				child->parent->removeChild(child);
			}
		}
	}
};

#endif // __Tree_H__