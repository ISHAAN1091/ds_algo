#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

void display(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        cout << root->left->data << " - ";
    }
    else
    {
        cout << ". - ";
    }
    cout << root->data << " - ";
    if (root->right)
    {
        cout << root->right->data << endl;
    }
    else
    {
        cout << "." << endl;
    }
    display(root->left);
    display(root->right);
}

Node *takeInput(vector<int> &arr)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int index = 1;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (arr[index] != -1)
        {
            front->left = new Node(arr[index]);
            q.push(front->left);
        }
        index++;
        if (index == arr.size())
            break;
        if (arr[index] != -1)
        {
            front->right = new Node(arr[index]);
            q.push(front->right);
        }
        index++;
        if (index == arr.size())
            break;
    }
    return root;
}

void printSingleChildNodes(Node *root, Node *parent)
{
    if (root == NULL)
        return;
    if (parent != NULL && ((parent->left == root && parent->right == NULL) || (parent->right == root && parent->left == NULL)))
    {
        cout << root->data << endl;
    }
    printSingleChildNodes(root->left, root);
    printSingleChildNodes(root->right, root);
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, -1, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    printSingleChildNodes(root1, NULL);
    delete root1;
    return 0;
}