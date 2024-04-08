import java.util.Stack

class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0

        for(i in 0..s.lastIndex) {
            val st = Stack<Char>()
            var flag = true
            for(j in 0..s.lastIndex) {
                when(val c =  s[(j+i)%s.length]) {
                    '}' -> {
                        if(st.isEmpty() || st.peek()!='{') {
                            flag = false
                            break
                        }else {
                            st.pop()
                        }
                    }
                    ']' -> {
                        if(st.isEmpty() || st.peek()!='[') {
                            flag = false
                            break
                        }else {
                            st.pop()
                        }
                    }
                    ')' -> {
                        if(st.isEmpty() || st.peek()!='(') {
                            flag = false
                            break
                        }else {
                            st.pop()
                        }
                    }
                    else -> st.push(c)
                }
            }

            if(flag&&st.isEmpty()) {
                answer++
            }
        }


        return answer
    }
}