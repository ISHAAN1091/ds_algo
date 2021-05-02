#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
    Node(int data)
    {
        this->data = data;
    }
    ~Node()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

Node *takeInput(vector<int> &arr)
{
    stack<Node *> s;
    Node *root = new Node(0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            s.pop();
        }
        else
        {
            Node *temp = new Node(arr[i]);
            if (s.size() == 0)
            {
                root = temp;
            }
            else
            {
                s.top()->children.push_back(temp);
            }
            s.push(temp);
        }
    }
    return root;
}

void display(Node *root)
{
    queue<Node *> mq;
    mq.push(root);
    queue<Node *> cq;
    while (!mq.empty())
    {
        Node *front = mq.front();
        mq.pop();
        cout << front->data << " ";
        for (auto i : front->children)
        {
            cq.push(i);
        }
        if (mq.size() == 0)
        {
            queue<Node *> temp;
            mq = cq;
            cq = temp;
            cout << endl;
        }
    }
}

void iterativePreorderPostorder(Node *root)
{
    stack<pair<Node *, int>> s;
    s.push(make_pair(root, -1));
    string pre = "";
    string post = "";
    while (!s.empty())
    {
        pair<Node *, int> top = s.top();
        if (top.second == -1)
        {
            pre += to_string(top.first->data) + " ";
            s.top().second++;
        }
        else if (top.second == top.first->children.size())
        {
            post += to_string(top.first->data) + " ";
            s.pop();
        }
        else
        {
            s.top().second++;
            s.push(make_pair(top.first->children[top.second], -1));
        }
    }
    cout << "PRE : " << pre << endl;
    cout << "POST : " << post << endl;
}

int main()
{
    vector<int> arr1 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1};
    vector<int> arr3 = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1};
    Node *root1 = takeInput(arr1);
    Node *root2 = takeInput(arr2);
    Node *root3 = takeInput(arr3);
    iterativePreorderPostorder(root2);
    delete root1;
    delete root2;
    delete root3;
    return 0;
}