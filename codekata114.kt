import java.util.PriorityQueue
import kotlin.math.min

class Solution {
    fun solution(N: Int, road: Array<IntArray>, k: Int): Int {
        var answer = 0
        val INF = 987654321

        val adjacentList = List(N+1) { MutableList(N+1 ) { INF } }

        for(roadInfo in road) {
            val v1 = roadInfo[0]
            val v2 = roadInfo[1]
            val dist = roadInfo[2]

            adjacentList[v1][v2] = min(adjacentList[v1][v2], dist)
            adjacentList[v2][v1] = min(adjacentList[v2][v1], dist)
        }

        val pq = PriorityQueue<Pair<Int, Int>> { a, b -> a.first - b.first }
        val isVisited = IntArray(N+1) { INF }
        isVisited[1] = 0
        pq.add(1 to 0)

        while(pq.isNotEmpty()) {
            val cur = pq.peek().first
            val dist = pq.peek().second
            pq.poll()

            if(isVisited[cur]!=dist) continue

            for(i in 1..N) {
                val nextDist = adjacentList[cur][i]
                if(nextDist!=INF && isVisited[i]>dist+nextDist) {
                    isVisited[i] = dist+nextDist
                    pq.add(i to dist+nextDist)
                }
            }
        }

        for(i in 1..N) {
            if(isVisited[i]<=k) answer++
        }

        return answer
    }
}