#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int _value;
    BinaryTreeNode *_pLeft;
    BinaryTreeNode *_pRight;
};

void FindPathRecuresively(BinaryTreeNode* root, int target, vector<int>& path, int sum )
{
    //检查参数有效性，结合递归基准情形
    if ( NULL == root || NULL == path)
        return;
    //入栈、加和sum
    path.push_back(root->_value );
    sum += root->_value;

    //如果是叶子节点 且 sum值与要求的相同，则打印；否则，遍历子节点
    if ( NULL == root->_pLeft && NULL == root->_pRight && target == sum )
    {
        cout << "Path found: " << endl;
        vector<int>::iterator iter = path.begin();
        for ( ; iter != path.end(); iter++ )
            cout << *iter << '\t';
        cout << endl << endl;
    }
    else
    {
        //是否为空的判断在进入递归后判断
        FindPathRecuresively(root->_pLeft, target, path, sum );
        FindPathRecuresively(root->_pRight, target, path, sum );
    }

    //出栈
    path.pop_back();
}

void FindPath( BinaryTreeNode* root, int target )
{
    //检查参数有效性
    if ( NULL == root )
        throw "Invalid input.";

    //声明栈（用vector代替），用于存储路径
    vector<int> path;
    //声明sum，用于存储总和
    int sum = 0;
    //调用递归
    FindPathRecuresively( root, target, path, sum );
}

int main()
{
    cout<<"Hello, World!"<<endl;
    return 0;
}