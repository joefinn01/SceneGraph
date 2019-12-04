#pragma once

class Planet;

struct TreeNode
{
	TreeNode(Planet* _data)
	{
		data = _data;
		child = nullptr;
		sibling = nullptr;
	}

	TreeNode(Planet* _data, TreeNode* _child)
	{
		data = _data;
		child = _child;
		sibling = nullptr;
	}

	TreeNode(Planet* _data, TreeNode* _child, TreeNode* _sibling)
	{
		data = _data;
		child = _child;
		sibling = _sibling;
	}

	Planet* data;
	TreeNode* child;
	TreeNode* sibling;
};

class LeftChildTree
{
public:
	LeftChildTree(Planet* _data);
	LeftChildTree();
	~LeftChildTree();

	void Delete(TreeNode* node);

	TreeNode* AddChild(Planet* _data, TreeNode* node);
	TreeNode* AddSibling(Planet* _data, TreeNode* node);

	TreeNode* GetRoot();

	void PreOrder(TreeNode* node);

	void Update(TreeNode* node);
	void DisplayPlanets(TreeNode* node);

private:
	TreeNode* root;
};

