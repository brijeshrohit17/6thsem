class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root: return False
        
        res = 0       
        def dfs(node):
            if not node: return 0
            
            nonlocal res
            res += node.val
            
            # recursively check for both the left
            # and the right subtrees until we find
            # a leaf on the path and the sum matches
            # if so; we can safely return True back up
            if node.left and dfs(node.left): return True
            if node.right and dfs(node.right): return True
                
            # somewhere down the recursion, we found
            # a leaf node (a complete path), now return
            # True if the rolling sum (res) == targetSum
            if not node.left and not node.right:
                if res == targetSum:
                    return True
            
            # here, we're basically backtracking
            # up the tree, so for example, from eg 1
            # we're at node 7 (leaf) and we realise the
            # sum of this path isn't the one we're looking
            # for, we'll not return anything for the dfs
            # call for node 7, so we just remove it from
            # the rolling sum which becomes the sum until node 11
            # so we can continue fwd to node 2 and so on
            res -= node.val
                    
        return dfs(root)
