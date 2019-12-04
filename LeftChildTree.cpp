#include "LeftChildTree.h"
#include <iostream>
#include "Planet.h"

LeftChildTree::LeftChildTree(Planet* _data)
{
	root = new TreeNode(_data);
}

LeftChildTree::LeftChildTree()
{
	root = nullptr;
}

LeftChildTree::~LeftChildTree()
{

}

TreeNode* LeftChildTree::GetRoot()
{
	return root;
}

void LeftChildTree::Delete(TreeNode* node)
{
	if (node->child != nullptr)
	{
		Delete(node->child);
	}

	if (node->sibling != nullptr)
	{
		Delete(node->sibling);
	}

	delete node;
}

TreeNode* LeftChildTree::AddChild(Planet* _data, TreeNode* node)
{
	TreeNode* temp = new TreeNode(_data);

	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->child != nullptr)
	{
		return AddSibling(_data, node->child);
	}
	else
	{
		node->child = temp;

		temp = nullptr;
	}
}

TreeNode* LeftChildTree::AddSibling(Planet* _data, TreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->sibling != nullptr)
	{
		node = node->sibling;
	}

	return node->sibling = new TreeNode(_data);
}

void LeftChildTree::PreOrder(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	while (node != nullptr)
	{
		std::cout << node->data << std::endl;	//Just move this statement for in and post order

		if (node->child != nullptr)
		{
			PreOrder(node->child);
		}

		node = node->sibling;
	}
}

void LeftChildTree::Update(TreeNode* node)
{
	while (node != nullptr)
	{
		if (node->child != nullptr)
		{
			Update(node->child);
		}

		node->data->Update();

		node = node->sibling;
	}
}

void LeftChildTree::DisplayPlanets(TreeNode* node)
{
	glPushMatrix();
	while (node != nullptr)
	{
		glTranslatef(node->data->GetPosition().x, node->data->GetPosition().y, node->data->GetPosition().z);
		glScalef(node->data->GetScale().x, node->data->GetScale().y, node->data->GetScale().z);
		glRotatef(node->data->GetRotationAroundObject(), 0, 1, 0);

		node->data->Display();

		if (node->child != nullptr)
		{
			DisplayPlanets(node->child);
		}

		node = node->sibling;
	}

	glPopMatrix();
}
