class Solution {
    fun solution(k: Int, m: Int, score: IntArray): Int {
        var answer: Int = 0
        score.sortDescending()

        var ind = m-1
        while(ind<score.size) {
            answer += score[ind]*m
            ind += m
        }
        return answer
    }
}