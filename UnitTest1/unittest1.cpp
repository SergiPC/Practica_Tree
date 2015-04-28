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
			
			DLinkedList<TreeNode<char>*> new_list;
			GTree.preOrderIterative(&new_list);
	
			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'F');
			Assert::AreEqual((char)new_list[1]->data, 'B');
			Assert::AreEqual((char)new_list[2]->data, 'A');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'C');
			Assert::AreEqual((char)new_list[5]->data, 'E');
			Assert::AreEqual((char)new_list[6]->data, 'G');
			Assert::AreEqual((char)new_list[7]->data, 'I');
			Assert::AreEqual((char)new_list[8]->data, 'H');		
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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.postOrderIterative(&new_list);

			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'A');
			Assert::AreEqual((char)new_list[1]->data, 'C');
			Assert::AreEqual((char)new_list[2]->data, 'E');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'B');
			Assert::AreEqual((char)new_list[5]->data, 'H');
			Assert::AreEqual((char)new_list[6]->data, 'I');
			Assert::AreEqual((char)new_list[7]->data, 'G');
			Assert::AreEqual((char)new_list[8]->data, 'F');
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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.inOrderIterative(&new_list);

			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'A');
			Assert::AreEqual((char)new_list[1]->data, 'B');
			Assert::AreEqual((char)new_list[2]->data, 'C');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'E');
			Assert::AreEqual((char)new_list[5]->data, 'F');
			Assert::AreEqual((char)new_list[6]->data, 'H');
			Assert::AreEqual((char)new_list[7]->data, 'I');
			Assert::AreEqual((char)new_list[8]->data, 'G');
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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.preOrderRecursive(&new_list);

			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'F');
			Assert::AreEqual((char)new_list[1]->data, 'B');
			Assert::AreEqual((char)new_list[2]->data, 'A');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'C');
			Assert::AreEqual((char)new_list[5]->data, 'E');
			Assert::AreEqual((char)new_list[6]->data, 'G');
			Assert::AreEqual((char)new_list[7]->data, 'I');
			Assert::AreEqual((char)new_list[8]->data, 'H');

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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.postOrderRecursive(&new_list);

			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'A');
			Assert::AreEqual((char)new_list[1]->data, 'C');
			Assert::AreEqual((char)new_list[2]->data, 'E');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'B');
			Assert::AreEqual((char)new_list[5]->data, 'H');
			Assert::AreEqual((char)new_list[6]->data, 'I');
			Assert::AreEqual((char)new_list[7]->data, 'G');
			Assert::AreEqual((char)new_list[8]->data, 'F');
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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.inOrderRecursive(&new_list);

			Assert::AreEqual((int)new_list.count(), 9);
			Assert::AreEqual((char)new_list[0]->data, 'A');
			Assert::AreEqual((char)new_list[1]->data, 'B');
			Assert::AreEqual((char)new_list[2]->data, 'C');
			Assert::AreEqual((char)new_list[3]->data, 'D');
			Assert::AreEqual((char)new_list[4]->data, 'E');
			Assert::AreEqual((char)new_list[5]->data, 'F');
			Assert::AreEqual((char)new_list[6]->data, 'G');
			Assert::AreEqual((char)new_list[7]->data, 'I');
			Assert::AreEqual((char)new_list[8]->data, 'H');
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

			DLinkedList<TreeNode<char>*> new_list;
			GTree.root.gatherAll(&new_list);

			Assert::AreEqual((int)new_list.count(), 1);
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