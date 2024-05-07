import java.util.LinkedList
import java.util.Queue
import kotlin.math.*

class Solution {
    fun solution(n: Int, wires: Array<IntArray>): Int {
        var answer: Int = -1

        adjacentList = List(n+1) { mutableListOf() }
        nSize = n

        for(wire in wires) {
            val v1 = wire[0]
            val v2 = wire[1]

            adjacentList[v1].add(v2)
            adjacentList[v2].add(v1)
        }

        var minDiff = 987654321
        for(wire in wires) {
            val v1 = wire[0]
            val v2 = wire[1]

            val diff = abs(bfs(v1, v2) - bfs(v2, v1))
            minDiff = min(minDiff, diff)
        }

        return minDiff
    }

    private fun bfs(start: Int, except: Int): Int {
        val q: Queue<Int> = LinkedList()
        val isVisited = BooleanArray(nSize+1) { false }
        var nodeNum = 1
        isVisited[start] = true

        for(node in adjacentList[start]) {
            if(node!=except) q.add(node)
        }

        while(q.isNotEmpty()) {
            val front = q.poll()!!

            if(isVisited[front]) continue
            isVisited[front] = true
            nodeNum++

            for(node in adjacentList[front]) {
                if(!isVisited[node]) {
                    q.add(node)
                }
            }
        }

        return nodeNum
    }

    companion object {
        var adjacentList: List<MutableList<Int>> = emptyList()
        var nSize = 0
    }
}