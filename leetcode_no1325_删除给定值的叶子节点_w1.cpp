/* ------------------------------------------------------------------|
给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

 

示例 1：



输入：root = [1,2,3,2,null,2,4], target = 2
输出：[1,null,3,null,4]
解释：
上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
示例 2：



输入：root = [1,3,3,3,2], target = 3
输出：[1,3,null,null,2]
示例 3：



输入：root = [1,2,null,2,null,2], target = 2
输出：[1]
解释：每一步都删除一个绿色的叶子节点（值为 2）。
示例 4：

输入：root = [1,1,1], target = 1
输出：[]
示例 5：

输入：root = [1,2,3], target = 1
输出：[1,2,3]
 

提示：

1 <= target <= 1000
每一棵树最多有 3000 个节点。
每一个节点值的范围是 [1, 1000] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-leaves-with-a-given-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	递归
*
*	执行用时：12 ms, 在所有 C++ 提交中击败了97.72%的用户
*	内存消耗：21.3 MB, 在所有 C++ 提交中击败了49.11%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

    //这里要加引用，不然是不会对原树进行修改的
    void dfs(TreeNode* &root, const int& target) {
        if (!root) {
            return;
        }
        dfs(root->left, target);
        dfs(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            root = nullptr;
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        return root;
    }

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root = removeLeafNodes(root, 2);
}