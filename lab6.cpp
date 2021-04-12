
#include <iostream>
#include <string>
using namespace std;

struct DATA
{
    int code;
    string lastname;
    int numOfGarbage;
    int weight;
};
class NODE {
public:
    DATA data;
    NODE* Left;
    NODE* Right;
};
class Tree {
    NODE* root;
    int Count;
    void print(NODE* leaf)
    {
        if (leaf != 0)
        {
            cout << leaf->data.code << " " << leaf->data.lastname << " " << leaf->data.numOfGarbage << " " << leaf->data.weight << endl;
            print(leaf->Left);
            print(leaf->Right);
        }
    }
    void addByLastname(DATA data, NODE* leaf)
    {
        if (data.lastname < leaf->data.lastname)
        {
            if (leaf->Left != 0) addByLastname(data, leaf->Left);
            else
            {
                leaf->Left = new NODE;
                leaf->Left->data = data;
                leaf->Left->Left = 0;
                leaf->Left->Right = 0;
                Count++;
            }
        }
        else
        {
            if (leaf->Right != NULL)
            {
                addByLastname(data, leaf->Right);
            }
            else
            {
                leaf->Right = new NODE;
                leaf->Right->data = data;
                leaf->Right->Right = NULL;
                leaf->Right->Left = NULL;
                Count++;
            }
        }
    }
    void Clear_Tree(NODE* leaf)
    {
        if (leaf != 0)
        {
            Clear_Tree(leaf->Left);
            Clear_Tree(leaf->Right);
            delete leaf;
            Count--;
        }
    }
    void addByCode(DATA data, NODE* leaf)
    {
        if (data.code < leaf->data.code)
        {
            if (leaf->Left != 0) addByCode(data, leaf->Left);
            else
            {
                leaf->Left = new NODE;
                leaf->Left->data = data;
                leaf->Left->Left = 0;
                leaf->Left->Right = 0;
                Count++;
            }
        }
        else
        {
            if (leaf->Right != NULL)
            {
                addByCode(data, leaf->Right);
            }
            else
            {
                leaf->Right = new NODE;
                leaf->Right->data = data;
                leaf->Right->Right = NULL;
                leaf->Right->Left = NULL;
                Count++;
            }
        }
    }
public:
    Tree()
    {
        root = 0;
    }
    ~Tree()
    {
        Clear_Tree();
    }
    void addBySurname(DATA data)
    {
        if (root != 0)
        {
            addByLastname(data, root);
        }
        else
        {
            root = new NODE;
            root->data = data;
            root->Left = 0;
            root->Right = 0;
            Count++;
        }
    }
    void addByCode(DATA data)
    {
        if (root != 0)
        {
            addByCode(data, root);
        }
        else
        {
            root = new NODE;
            root->data = data;
            root->Left = 0;
            root->Right = 0;
            Count++;
        }
    }
    void print()
    {
        print(root);
    }

    void Clear_Tree()
    {
        Clear_Tree(root);
        root = 0;
    }

    bool isEmpty()
    {
        if (root == 0) return true;
        return false;
    }

    int calculate(NODE* leaf)
    {
        if (leaf == 0) return 0;
        return calculate(leaf->Right) + calculate(leaf->Left) + leaf->data.weight;
    }
    double calculate()
    {
        return (double)calculate(root) / (double)Count;
    }
    NODE* getRoot()
    {
        return root;
    }
};
Tree tree, tree2;
DATA input()
{
    int a, c, d;
    string b;
    cin >> a >> b >> c >> d;
    return { a, b, c, d };
}
void change(NODE* leaf)
{
    if (leaf == 0) return;
    tree2.addByCode(leaf->data);
    change(leaf->Left);
    change(leaf->Right);
}
int main()
{
    cout << "Be careful all field must be inputed like 'code lastname number of baggage weight" << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "Type the " << i + 1 << " element" << endl;
        tree.addBySurname(input());
    }
    tree.addBySurname({ 5, "gafaf", 4, 10 });
    tree.addBySurname({ 3, "zfafds", 4, 5 });
    tree.addBySurname({ 21, "cgfdgrt", 4, 1 });
    tree.addBySurname({ 63, "whgffd", 4, 4 });
    tree.addBySurname({ 72, "agddfgdf", 4, 1 });
    cout << "Tree by Lastname: " << endl;
    tree.print();
    cout << endl << "Average weight: " << tree.calculate() << endl << endl;
    change(tree.getRoot());
    tree.Clear_Tree();
    cout << "Tree by code: " << endl;
    tree2.print();
    return 0;    
}


