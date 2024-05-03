class Solution {
    fun solution(queue1: IntArray, queue2: IntArray): Int {
        val circularQueue = queue1.plus(queue2)
        var q1Sum = queue1.sumOf { it.toLong() }
        var q2Sum = queue2.sumOf { it.toLong() }

        if((q1Sum+q2Sum)%2!=0L) return -1
        var q1Ind = 0
        var q2Ind = queue1.size
        var flag = false

        while(q1Ind<queue1.size || q2Ind<queue1.size*2) {
            if(q1Sum==q2Sum) {
                flag = true
                break
            }

            val convertedQ1Ind = q1Ind%circularQueue.size
            val convertedQ2Ind = q2Ind%circularQueue.size

            if(q1Sum<q2Sum) {
                q1Sum+=circularQueue[convertedQ2Ind]
                q2Sum-=circularQueue[convertedQ2Ind]
                q2Ind++
            }else {
                q1Sum-=circularQueue[convertedQ1Ind]
                q2Sum+=circularQueue[convertedQ1Ind]
                q1Ind++
            }
        }

        if(flag) {
            return q1Ind+q2Ind-queue1.size
        }else {
            return -1
        }
    }
}