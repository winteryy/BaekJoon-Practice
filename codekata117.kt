import java.util.LinkedList
import java.util.Queue
import kotlin.math.min

class Solution {
    fun solution(storey: Int): Int {
        var answer: Int = 987654321

        val q: Queue<Pair<Int, Int>> = LinkedList()
        q.add(storey to 0)
        while(q.isNotEmpty()) {
            val curStorey = q.peek().first
            val curNum = q.peek().second
            q.poll()
            if(curStorey==0) {
                answer = min(curNum, answer)
                continue
            }else if(curNum>=answer) continue

            val lastNum = curStorey % 10
            q.add(curStorey/10 to curNum+lastNum)
            q.add(curStorey/10+1 to curNum+(10-lastNum))
        }

        return answer
    }
}