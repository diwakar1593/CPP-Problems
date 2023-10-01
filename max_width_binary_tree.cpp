#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int maxWidth(TreeNode *root)
{
	if (!root) return 0;

	int maxWidth = 0;
	queue<pair<TreeNode*, int>> q;
	q.push({root, 1});

	while (!q.empty())
	{
		int leftmost = q.front().second;
		int rightmost = leftmost;

		int levelSize = q.size();
		for (int i = 0; i < levelSize; i++)
		{
			TreeNode *node = q.front().first;
			int position = q.front().second;
			q.pop();

			rightmost = position;

			if (node->left) q.push({ node->left, position *2 });
			if (node->right) q.push({ node->right, position *2 + 1});
		}

		maxWidth = max(maxWidth, rightmost-leftmost+1);
	}
	return maxWidth;
}

int main()
{
	TreeNode *root = nullptr;

	cout<<"Enter the values of the binary tree nodes (-1 for empty node) : "<<endl;

	int value;
	cin>>value;
	if (value!=-1)
	{
		root = new TreeNode(value);
		queue<TreeNode*> nodes;
		nodes.push(root);

		while (!nodes.empty())
		{
			TreeNode *current = nodes.front();
			nodes.pop();

			int leftValue, rightValue;
			cin>>leftValue>>rightValue;

			if (leftValue!=-1)
			{
				current->left = new TreeNode(leftValue);
				nodes.push(current->left);
			}

			if (rightValue!=-1)
			{
				current->right = new TreeNode(rightValue);
				nodes.push(current->right);
			}
		}
	}

	int result = maxWidth(root);
	cout<<"Maximum Width : "<<result<<endl;

	return 0;
}
