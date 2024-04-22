import java.util.Stack

class Solution {
    fun solution(numbers: IntArray): IntArray {
        var answer: IntArray = IntArray(numbers.size)

        val st = Stack<Int>()

        for(i in numbers.lastIndex downTo 0) {
            while(st.isNotEmpty()&&st.peek()<=numbers[i]) {
                st.pop()
            }
            answer[i] = if(st.isEmpty()) -1 else st.peek()
            st.push(numbers[i])
        }
        return answer
    }
}