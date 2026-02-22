# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flatten(self, root):
        self.prev = None
        
        def helper(node):
            if not node:
                return
            
            # Step 1: Flatten right subtree
            helper(node.right)
            
            # Step 2: Flatten left subtree
            helper(node.left)
            
            # Step 3: Rearrange pointers
            node.right = self.prev
            node.left = None
            
            # Step 4: Move prev pointer
            self.prev = node
        
        helper(root)
