class Solution {
    fun solution(citations: IntArray): Int {
        var answer = 0

        val accSum = IntArray(10001) { 0 }

        for(cit in citations) {
            accSum[cit]++
        }

        for(i in 10000 downTo 0) {
            if(accSum[i]>=i) {
                return i
            }else {
                accSum[i-1] += accSum[i]
            }
        }
        return answer
    }
}