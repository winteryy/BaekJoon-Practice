class Solution {
    fun solution(n: Int): Long {
        var answer: Long = 0
        val dp = LongArray(2002) { 0L }
        dp[0] = 1
        for(i in 0 until n) {
            dp[i+1] = (dp[i+1]+dp[i])%1234567
            dp[i+2] = (dp[i+2]+dp[i])%1234567
        }

        return dp[n]
    }
}