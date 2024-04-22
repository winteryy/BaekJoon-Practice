import kotlin.math.min

class Solution {
    fun solution(x: Int, y: Int, n: Int): Int {
        val dp = IntArray(y+1) { 987654321 }
        dp[x] = 0

        for(i in x until y) {
            if(i+n<=y) {
                dp[i+n] = min(dp[i+n], dp[i]+1)
            }
            if(i*2<=y) {
                dp[i*2] = min(dp[i*2], dp[i]+1)
            }
            if(i*3<=y) {
                dp[i*3] = min(dp[i*3], dp[i]+1)
            }
        }

        return if(dp[y]==987654321) -1 else dp[y]
    }
}