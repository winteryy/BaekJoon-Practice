import java.util.LinkedList
import java.util.Queue
import java.util.Stack

class Solution {
    fun solution(order: IntArray): Int {
        var answer: Int = 0

        var ind = 0
        val st = Stack<Int>()
        val q: Queue<Int> = LinkedList((1..order.size).toList())

        while(ind<order.size) {
            if(order[ind]==q.peek()) {
                q.poll()
                ind++
                answer++
            }else {
                val cur = order.size-q.size+1
                if(order[ind]>cur) {
                    st.push(q.poll())
                }else if(order[ind]<cur) {
                    if(st.isNotEmpty() && st.peek()==order[ind]) {
                        st.pop()
                        ind++
                        answer++
                    }else {
                        break
                    }
                }
            }
        }

        return answer
    }
}