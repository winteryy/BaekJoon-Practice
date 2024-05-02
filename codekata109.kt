class Solution {
    fun solution(sequence: IntArray, k: Int): IntArray {
        val answer: IntArray = intArrayOf(0, 1000001)

        var start = 0
        var end = 0
        var sum = sequence[0]

        while(end<sequence.size) {
            if(sum==k) {
                if(end-start<answer[1]-answer[0]) {
                    answer[0] = start
                    answer[1] = end
                }
                end++
                if(end<sequence.size) {
                    sum+=sequence[end]
                }
            }else if(sum>k) {
                sum-=sequence[start]
                start++
            }else {
                end++
                if(end<sequence.size) {
                    sum+=sequence[end]
                }
            }
        }
        return answer
    }
}