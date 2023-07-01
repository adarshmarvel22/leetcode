class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        n = len(s)
        perm = [0] * (n + 1)
        max_val = n
        min_val = 0

        for i in range(n):
            if s[i] == 'I':
                perm[i] = min_val
                min_val += 1
            else:
                perm[i] = max_val
                max_val -= 1

        perm[n] = min_val  # Last element in the permutation

        return perm