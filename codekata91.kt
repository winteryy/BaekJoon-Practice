class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        var answer = mutableListOf<Int>()

        var ind = 0
        var day = 0
        while(ind<progresses.size) {
            var cnt = 0
            while(ind<progresses.size && progresses[ind]+speeds[ind]*day>=100) {
                ind++
                cnt++
            }
            if(cnt!=0) {
                answer.add(cnt)
            }
            day++
        }

        return answer.toIntArray()
    }
}