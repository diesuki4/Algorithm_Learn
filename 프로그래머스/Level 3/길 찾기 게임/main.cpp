#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<vector<int>> result);
struct Point;
class Tree;
vector<vector<int>> solution(vector<vector<int>> nodeinfo);

int main(int argc, char* argv[])
{
    print(solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}}));

    return 0;
}

void print(vector<vector<int>> result)
{
    for (vector<int>& v : result)
    {
        for (int e : v)
            cout << e << " ";

        cout << endl;
    }
}

struct Point
{
    int id;
    int x;
    int y;

    friend bool operator < (const Point& A, const Point& B)
    {
        if (A.y == B.y)
            return A.x < B.x;
        else
            return A.y > B.y;
    }
};

class Tree
{
private:
    struct Node
    {
        int id;
        int x;

        Node* left  = nullptr;
        Node* right = nullptr;
    };

    Node* root;

public:
    Tree() : root(nullptr) {}

    void add(const Point& point)
    {
        if (root == nullptr)
        {
            root = new Node;

            root->id = point.id;
            root->x  = point.x;
        }
        else
        {
            Node* p = findParent(root, point.x);
            Node* child = new Node;

            if (p->x < point.x)
                p->right = child;
            else
                p->left = child;

            child->id = point.id;
            child->x  = point.x;
        }
    }

private:
    Node* findParent(Node* p, int x)
    {
        if (p->x < x)
            if (p->right)
                return findParent(p->right, x);
            else
                return p;
        else
            if (p->left)
                return findParent(p->left, x);
            else
                return p;
    }

    void preOrder(Node* p, vector<int>& result)
    {
        if (p == nullptr)
            return;

        result.emplace_back(p->id);
        preOrder(p->left, result);
        preOrder(p->right, result);
    }

    void postOrder(Node* p, vector<int>& result)
    {
        if (p == nullptr)
            return;

        postOrder(p->left, result);
        postOrder(p->right, result);
        result.emplace_back(p->id);
    }

    void deleteAll(Node* p)
    {
        if (p == nullptr)
            return;

        deleteAll(p->left);
        deleteAll(p->right);
        delete p;
    }

public:
    vector<int> preOrder()
    {
        vector<int> result;

        preOrder(root, result);

        return result;
    }

    vector<int> postOrder()
    {
        vector<int> result;

        postOrder(root, result);

        return result;
    }

    ~Tree()
    {
        deleteAll(root);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    set<Point> st;

    for (int i = 0; i < nodeinfo.size(); ++i)
        st.insert({i + 1, nodeinfo[i][0], nodeinfo[i][1]});

    Tree tr;

    for (const Point& p : st)
        tr.add(p);

    answer.emplace_back(tr.preOrder());
    answer.emplace_back(tr.postOrder());

    return answer;
}
