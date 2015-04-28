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
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Tree_preOrderIterative)
		{
			Tree<char> GTree('F');
			
			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');
			
			DLinkedList<TreeNode<char>*> list;
			GTree.preOrderIterative(&list);
	
			Assert::AreEqual((int)list.count(), 9);
			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');		
		}

		TEST_METHOD(Tree_postOrderIterative)
		{
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			GTree.postOrderIterative(&list);

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
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			GTree.inOrderIterative(&list);

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
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			GTree.preOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);
			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');

		}

		TEST_METHOD(Tree_postOrder)
		{
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			GTree.postOrderRecursive(&list);

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
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			GTree.inOrderRecursive(&list);

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
			Tree<int> GTree(0);

			GTree.add(100, 0);
			GTree.add(200, 0);
			GTree.add(300, 0);
			GTree.add(101, 100);
			GTree.add(102, 100);
			GTree.add(103, 100);
			GTree.add(210, 200);
			GTree.add(220, 200);
			GTree.add(221, 220);

			DLinkedList<TreeNode<int>*> list;
			GTree.root.gatherAll(&list);

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
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			GTree.clear();

			DLinkedList<TreeNode<char>*> list;
			GTree.root.gatherAll(&list);

			Assert::AreEqual((int)list.count(), 1);
		}

		TEST_METHOD(Tree_find)
		{
			Tree<char> GTree('F');

			GTree.add('B', 'F');
			GTree.add('G', 'F');
			GTree.add('A', 'B');
			GTree.add('D', 'B');
			GTree.add('C', 'D');
			GTree.add('E', 'D');
			GTree.add('I', 'G');
			GTree.add('H', 'I');

			TreeNode<char>* p = GTree.root.findRecursive('I');
			TreeNode<char>* p2 = GTree.root.findRecursive('Z');

			Assert::AreEqual((char)p->data, 'I');
			Assert::IsNull(p2);
		}
	};
}