#define scd second
#define fst first
#define pb push_back
#define mkp make_pair
#define all(x) x.begin(), x.end()
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vint> vvint;
typedef vector<vlong> vvlong;
typedef list<int> lint;
typedef list<ll> llong;
typedef list<pii> lpii;
typedef list<pll> lpll;
typedef list<lint> llint;
typedef list<llong> lllong;

/**
 * Binary Tree Maximum Path Sum
 * problem description : https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * 
 * Algorithm (brief):
 * - we can dynamically solve it. we first solve it for left and right trees.
 * - we use values calculated for left and right tree to calculate for the current node.
 * 
 * How to calculate for a subtree : 
 * 1. lets consider a subtree rooted at v
 * 2. lets maintain two variables x, y such that 
 *  x is max path in subtree rooted at v and y is max path starting from v in subtree rooted at v.
 * 3. lets p be subtree root and l and r be left and right subtree respectively
 *  then
 *      p.y=max(l.y, r.y, p.val, p.val+l.x, p.val+r.x, p.val+l.x+r.x)
 *      p.x=max(p.val, p.val+l.x, p.val+r.x) 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pii max_path(TreeNode* root){
        if(root==NULL) return {-1e9,-1e9};
        auto lp=max_path(root->left);
        auto rp=max_path(root->right);
        int max_st=root->val;
        max_st=max(max_st,root->val+lp.fst);
        max_st=max(max_st,root->val+rp.fst);
        max_st=max(max_st,root->val+rp.fst+lp.fst);
        int max_p=root->val+max(lp.fst,rp.fst);
        max_p=max(max_p,root->val);
        return {max_p,max(max_st,max(lp.scd,rp.scd))}; 
    }
    
    int maxPathSum(TreeNode* root) {
        auto ret=max_path(root);
        return ret.scd;    
    }
};