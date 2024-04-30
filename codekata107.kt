import java.util.Stack

class Solution {
    fun solution(number: String, k: Int): String {
        val st = Stack<Char>()
        var remain = k
        var ind = 0

        while(ind<number.length) {
            if(st.empty()||st.peek()>=number[ind]) {
                st.push(number[ind])
                ind++
            }else {
                while(st.isNotEmpty()&&st.peek()<number[ind]&&remain>0) {
                    st.pop()
                    remain--
                }
                st.push(number[ind])
                ind++
            }
        }
        while(remain>0) {
            st.pop()
            remain--
        }

        val sb = StringBuilder()
        while(st.isNotEmpty()) {
            sb.insert(0, st.peek())
            st.pop()
        }

        return sb.toString()
    }
}