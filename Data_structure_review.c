// ELEC 278 Data Structures Exam Review Algorithm Implementation
// Binary Search Tree and AVL Tree analysis
//Find minimum of a Binary Search Tree:
BinaryTreeNode* FindMin(BinaryTreeNode* node) //RECURSIVE FUNCTION
{
	if(node==NULL)
	{
		return NULL; //this means there is an empty tree
	}
	else if(node ->left!=null) //if the left subtree has a left subtree that isnt empty
		return FindMin(node -> left); //go thru the function again
	else
		return node; //if the subtree does has a left subtree with nothing in it this means its the minimum
}


//Find maxmimum of a Binary Search Tree:
BinaryTreeNode* FindMax(BinaryTreeNode* node)
{
		if(node==NULL)
		{
			return NULL; // if the tree is empty ur done
		}
		else if(node->right!=null) //if the right child has another right subtree you gotta keep going
			return FindMax(node -> right);
		else
			return node; //if the subtree has no right subtrees you know it is the maximum so ur good!!
}

//PRINT A TREE USING RECURSION:
print printTree(BinaryTree *node)
{ //use recursion inside of the function to go through entire tree but to input in different orders look at print statements
	// to print from lowest to highest
	//INORDER
	left child
	root
	rightchild

	// to print from highest to lowest
	//POSTORDER
	rightchild
	left child
	root

	//to do like root left right child
	//PREORDER
	root
	left child
	right child

	return;
}


//Finding a specific node of a binary tree:
BinaryTreeNode *find(BinaryTreeNode *node, int data)
{
		if(node==NULL)
			return NULL; //not the thing were looking for because its a null

		if (data -> node -> data)
			return Find(node ->right, data); //searching the right subtree
		else if(data <- node -> data)
			return FInd(node -> left, data); //search left subtree
		else
			return node; //good we found the one we were looking for
}



BinaryTreeNode* Insert(BinaryTreeNode *node, int data) // i do not understand this function
{
	if(node==NULL)
	{
		BinaryTreeNode *temp; //assigning a pointer temp
		temp = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));// opening a space to store the temporary variable
		temp -> data = data; // making temporary pointer equal to data point
		temp ->left = temp -> right =NULL;
		return temp;
	}
	if (data>(node -> data))
	{
		node -> right= Insert(node ->right,data);
	}
	else if (data<(node ->data))
	{
		node ->left = Insert(node ->left, data);
	}
}

BinaryTreeNode * Delete(BinaryTreeNode *node, int data)
{
	BinaryTreeNode *temp;
	if(node==NULL)
		return NULL;
	else if(data < node ->data)
		node -> left = Delete(node-> left, data);
	else if(data> node -> data)
		node ->right = Delete(node->right,data);
	else
	{ //Now we can delete this node and replace it with either min element in right subtree or max element n eft subtree

		if(node -> right && node -> left)
		{
			// replace with minimum element in right subtree
			temp =FindMin(node ->right);
			node -> data = temp -> data;
			// as we replace it with some other node we have to delete that node
			node ->right = Delete(node-> right, temp-> data);
		}
	else
	{
	// if thre is only one or zero children then we can directly remove it from the tree and connect its parent to its child
		temp = node;
		if(node ->left == NULL)
			node = node -> right;
		else if(node -> right == NULL)
			node = node -> left;
		free(temp); //temp no longer required
	}
	}
	return node;
}

//AVL Trees:
// function to get the balance factor

int getBalanceFactor(Node* root)
//get balance factor- difference between left height and right height
{
	int hr= -1, hl = -1;	// Default values
	hr = (root-> rightChild) ? root -> rightChild -> height : -1;
	hl = (root-> leftChild) ? root -> leftChild -> height : -1;
	return hl-hr;
}getBalanceFactor()

int calcHeight(Node* root)
// calculate height of this node by adding 1 to max of left, right
{
	int hrl= -1, hll= -1;
	if (root->rightChild) hrl = root -> rightChild ->height;
	if(root->leftChild) hll= root -> leftChild ->height;
	return maxint(hrl, hll) +1;
}calcHeight();

Node* rebalance(Node* root)
// check balance factor to see if balancing required (bf > 1 or bf < -1)
//if balancing required, perform necessary rotations
{
	int bf= getBalanceFactor(root);
	if (bf > 1) {
		int left_bf = getBalanceFactor(root -> leftChild);
		if (left_bf >= 0) {
			printf("Node %d is unbalanced, left of left: ", root -> key);
			root -> rightChild = rotateRight(root -> rightChild);
			return rotateLeft(root);
		} else if (right_bf < 0) {
			printf("Node %d is unbalanced. Right of Right: ", root -> key);
			return rotateLeft(root);
		}

	}
retrun root;
}rebalance()

Node* rotateRight(Node* root)
{
	printf("Rotate Right\n");
	if (root != NULL)
		Node* left = root -> leftChild;
		Node* leftRight = left -> rightChild;
		root ->leftChild = leftRight;
		left ->rightChild = root;

		root -> height = calcHeight(root);
		left ->height = calcHeight(left);
		return left;
}
}
