import java.util.PriorityQueue

class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        val sizeMap = mutableMapOf<Int, Int>()

        for(tSize in tangerine) {
            sizeMap[tSize] = 1+(sizeMap[tSize]?:0)
        }
        val pq = PriorityQueue<Int>()
        for(sizeCount in sizeMap.values) {
            pq.add(sizeCount)
        }

        var tNum = tangerine.size
        var answer = sizeMap.size
        while(pq.isNotEmpty()) {
            tNum -= pq.peek()
            if(tNum > k) {
                pq.poll()
                answer--
            }else if(tNum == k) {
                answer--
                break
            }else {
                break
            }
        }

        return answer
    }
}