import math

class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)

        maxLen = int(math.log2(num)+1)

        for i in range(maxLen,0,-1):
            base, poss = self.possible(i,num)
            if poss:
                return str(base)



    def possible(self, oneLen: int, value: int) -> bool:
        lo = 1
        hi = value

        while hi - lo > 1:
            base = lo + (hi - lo) // 2
            if ((1-base**(oneLen+1))//(1 - base) < value):
                lo = base
            else:
                hi = base

        return hi, (1-hi**(oneLen+1))//(1 - hi) == value



s = Solution()
smallest = s.smallestGoodBase("1000000000000000000")
print(smallest)