#include <iostream>
#include <vector>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  // left
    root->right = buildTree(preorder); // right

    return root;
}

// preorder traversal. root->left->right

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// inorder traversal // left->root->right

void inOrder(Node *root)
{ 
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// postorder traversal    left->right->root

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// level order

void levelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// height of a tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}

// count Nodes
int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

// sum of nodes
int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

//Top view of a Binary Tree
void topview(Node* root) {
    queue<pair<Node*, int>> q; //(node, HD)
    map<int, int> m;
    q.push({root, 0});

    while(q.size() > 0) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        if(curr->left != NULL) {
            q.push({curr->left, currHD-1});
        }

        if(curr->right != NULL) {
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }

    cout << endl;
}

//kth level of tree

void kthLevel(Node* root, int k) { //tc=O(n)
    if(root == NULL){
        return;
    }
    if(k == 1) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}

//Transform to sum tree
// node = mode val + left subtree + right subtree


int sumTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}




int main()
{
    vector<int> preorder = {1, 2, 7, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    sumTree(root);
    return 0;
}