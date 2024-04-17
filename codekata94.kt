class Solution {
    fun solution(numbers: IntArray, target: Int): Int {

        val dp = List(2001) { MutableList(numbers.size+1) { 0 } }
        dp[1000][0] = 1

        for(i in 1..numbers.size) {
            for(j in 0..2000) {
                val prevNum = dp[j][i-1]
                if(prevNum>0) {
                    dp[j+numbers[i-1]][i] += prevNum
                    dp[j-numbers[i-1]][i] += prevNum
                }
            }
        }

        return dp[target+1000][numbers.size]
    }
}