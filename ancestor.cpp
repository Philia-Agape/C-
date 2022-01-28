/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if(root->val == o1) return o1;
        else if(root->val == o2) return o2;
        else if((root->left->val == o1 && root->right->val == o2)
        || (root->left->val == o2 && root->right->val == o1)) 
            return root->val; 
        int ans = -1, res = -1;
        dfs(root->left, o1, o2, ans, &res);
        
        if(res!= -1) return res;
        else dfs(root->right, o1, o2, -1, &res);
        if(res!= -1) return res;
        return root->val;
    }
    
    int dfs(TreeNode* root, int o1, int o2, int ans, int* res){
        //not found both o1, o2 but reach the end
        
        if(*res != -1) return -1;
        if(!root) return -1; 
        //not found for both, empty, so no!
        
        //else if(ans != -1) return ans;
        else if(root->val == o1){
            if(ans == o2){ 
                *res = ans;
                return -1;
            }    
            ans = o1;
            return ans;
        }    
        else if(root->val == o2){ 
            if(ans == o1){
                *res = ans;
                return -1;
            }    
            ans = o2;
            return ans;
        }
        
        int l = dfs(root->left, o1, o2, ans, res); 
        int r = dfs(root->right, o1, o2, ans, res);
        
        if(*res != -1) return -1;
        //if(l == -1 && r == -1) return -1;
        if(l != -1 && r != -1 && *res == -1){
            *res = root->val;
        }    
        return -1;
    }
};
