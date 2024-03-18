import kotlin.math.min

class Solution {
    fun solution(X: String, Y: String): String {
        val xNumArr = Array(10) { 0 }
        val yNumArr = Array(10) { 0 }

        for(c in X) {
            xNumArr[c.digitToInt()]++
        }

        for(c in Y) {
            yNumArr[c.digitToInt()]++
        }

        var charList = mutableListOf<Char>()
        for(i in 9 downTo 0) {
            for(j in 0 until min(xNumArr[i], yNumArr[i])) charList.add(i.digitToChar())
        }

        var answer = charList.joinToString("")

        if(answer.isEmpty()) {
            answer = "-1"
        }else if(answer[0]=='0') {
            answer = "0"
        }

        return answer
    }
}