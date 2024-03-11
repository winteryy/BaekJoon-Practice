import java.util.LinkedList
import java.util.Queue

class Solution {
    fun solution(cards1: Array<String>, cards2: Array<String>, goal: Array<String>): String {

        val q: Queue<Triple<Int, Int, Int> > = LinkedList()
        var answer = "No"

        if(cards1[0]==goal[0]) {
            q.add(Triple(1, 0, 1))
        }
        if(cards2[0]==goal[0]) {
            q.add(Triple(0, 1, 1))
        }

        while(q.isNotEmpty()) {
            val top = q.poll()

            if(top!!.third==goal.size) {
                answer = "Yes"
                break
            }

            if(top.first<cards1.size && cards1[top.first]==goal[top.third]) {
                q.add(Triple(top.first+1, top.second, top.third+1))
            }
            if(top.second<cards2.size && cards2[top.second]==goal[top.third]) {
                q.add(Triple(top.first, top.second+1, top.third+1))
            }
        }

        return answer
    }
}