#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Practica Quadtree/GeneralTrees.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// Tree ------------------------------------------------
		TEST_METHOD(Tree_add)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);

			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);

			tree.add(210, 200);
			tree.add(220, 200);

			tree.add(221, 220);

			// Just do not test that we run forever because of the recursion
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Tree_preOrderIterative)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('X', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.preOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_postOrderIterative)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.postOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(Tree_inOrderIterative)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.inOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Tree_preOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('X', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.preOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_postOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.postOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(Tree_inOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.inOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Tree_gather)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			DLinkedList<TreeNode<int>*> list;
			tree.root.gatherAll(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((int)list[0]->data, 0);
			Assert::AreEqual((int)list[1]->data, 100);
			Assert::AreEqual((int)list[2]->data, 101);
			Assert::AreEqual((int)list[3]->data, 102);
			Assert::AreEqual((int)list[4]->data, 103);
			Assert::AreEqual((int)list[5]->data, 200);
			Assert::AreEqual((int)list[6]->data, 210);
			Assert::AreEqual((int)list[7]->data, 220);
			Assert::AreEqual((int)list[8]->data, 221);
			Assert::AreEqual((int)list[9]->data, 300);

		}

		TEST_METHOD(Tree_clear)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			tree.clear();

			DLinkedList<TreeNode<int>*> list;
			tree.root.gatherAll(&list);

			Assert::AreEqual((int)list.count(), 1);
		}

		TEST_METHOD(Tree_find)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			TreeNode<int>* p = tree.root.findRecursive(210);
			TreeNode<int>* p2 = tree.root.findRecursive(999);

			Assert::AreEqual((int)p->data, 210);
			Assert::IsNull(p2);
		}
	};
}