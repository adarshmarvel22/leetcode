# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.mp = {}
        
    def dfs(self, root, par):
        if not root:
            return
        if not par:
            par = root

        self.mp[root] = par
        self.dfs(root.left, root)
        self.dfs(root.right, root)
        
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        self.dfs(root, None)
        q = deque()
        st = set()
        cnt = 0
        res = []

        q.append(target)

        while q:
            sz = len(q)

            if cnt > k:
                break

            for _ in range(sz):
                curr = q.popleft()

                if curr.left and curr.left not in st:
                    q.append(curr.left)
                    st.add(curr.left)
                if curr.right and curr.right not in st:
                    q.append(curr.right)
                    st.add(curr.right)

                if curr in self.mp and self.mp[curr] not in st:
                    q.append(self.mp[curr])
                    st.add(self.mp[curr])

                st.add(curr)
                if cnt == k:
                    res.append(curr.val)

            cnt += 1

        return res