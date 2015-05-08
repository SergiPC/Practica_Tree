// --------------------------------------------
//               Generic Tree
// --------------------------------------------


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
	TreeNode*				dady;
	DLinkedList<TreeNode*>	son;

public:
	TreeNode(const kdata& new_data)
	{
		data = new_data;
		dady = NULL;
	}

	Void addChild(TreeNode* new_node)
	{
		son.addNode(new_node);
		new_node->dady = this;
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

	

	

	// In order recursive ----------------------------------
	// half of the children, the root and the other half of the children
	void inOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list)
	{}

	TreeNode<kdata>* findRecursive(const kdata& new_node)
	{}

	void gatherAll(DLinkedList<TreeNode*>* new_list)
	{}


	template<class kdata>
	class Tree
	{
	public:
		TreeNode<kdata> root;


		// Pre order recursive ---------------------------------
		// 1) process root
		// 2) recursively process children from "left to right"
		void preOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

			new_list->addNode(old_node);
			DListNode<TreeNode<kdata>*>* tmp = old_node->son.head;

			for (; tmp != NULL; tmp = tmp->next)
			{
				preOrderRecursive(new_list, tmp->data);
			}
		}
		
		// Post order recursive --------------------------------
		// 1) no node is processed until all of its children have been processed
		// 2) process root
		void postOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

			DListNode<TreeNode<kdata>*>* tmp = old_node->son.head;

			for (; tmp != NULL; tmp = tmp->next)
			{
				postOrderRecursive(new_list; tmp->data);
			}
			new_list->addNode(old_node);
		}

		// In order recursive ----------------------------------
		// half of the children, the root and the other half of the children
		void inOrderRecursive(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

			DListNode<TreeNode<kdata>*>* tmp = old_node->son.head;
			unsigned int middle = old_node->son.count() / 2;

			for (unsigned int i = middle; i > 0; i--, tmp = tmp->next)
			{
				inOrderRecursive(new_list, tmp->data);
			}
			new_list->addNode(old_node);

			for (; tmp != NULL; tmp = tmp->next)
			{
				inOrderRecursive(new_list, tmp->data);
			}
		}

		// Pre order iterative ---------------------------------
		// 1) process root
		// 2) recursively process children from "left to right"
		void preOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

		}

		// Post order iterative --------------------------------
		// 1) no node is processed until all of its children have been processed
		// 2) process root
		void postOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

		}

		// In order iterative ----------------------------------
		void inOrderIterative(DLinkedList<TreeNode<kdata>*>* new_list, TreeNode<kdata>* old_node)
		{
			if (old_node == NULL)
				old_node = root;

		}
	};
};

#endif // __Tree_H__