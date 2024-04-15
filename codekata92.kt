import java.util.*

class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        var answer = 0

        val q: Queue<Pair<Int, Int>> = LinkedList()

        val sortedPriorities = priorities.toList().sortedDescending()
        priorities.forEachIndexed { ind, i ->
            q.offer(ind to i)
        }
        while(q.isNotEmpty()) {
            if(q.peek().second==sortedPriorities[answer]) {
                answer++
                if(q.peek().first==location) break
                q.poll()
            }else {
                q.offer(q.poll())
            }
        }
        
        return answer
    }
}