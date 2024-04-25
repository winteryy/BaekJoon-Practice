import java.util.LinkedList
import java.util.Queue

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        val q: Queue<Pair<Int, Int>> = LinkedList()
        var weightSum = 0
        var truckInd = 0
        var arrived = 0
        var time = 0

        while(arrived<truck_weights.size) {
            time++
            if(q.isNotEmpty()) {
                if(bridge_length==time-q.peek().first) {
                    weightSum-=q.peek().second
                    arrived++
                    q.poll()
                }
            }
            
            if(truckInd<truck_weights.size && weightSum+truck_weights[truckInd]<=weight) {
                val nextWeight = truck_weights[truckInd]
                q.offer(time to nextWeight)
                weightSum+=nextWeight
                truckInd++
            }
        }

        return time
    }
}