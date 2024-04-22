class Solution {
    fun solution(word: String): Int {
        var answer = 0

        word.forEachIndexed { ind, c ->
            val prevNum = when(ind) {
                0 -> 781
                1 -> 156
                2 -> 31
                3 -> 6
                4 -> 1
                else -> 0
            }
            val charNum = when(c) {
                'A' -> 0
                'E' -> 1
                'I' -> 2
                'O' -> 3
                'U' -> 4
                else -> 0
            }
            answer += prevNum*charNum+1
        }
        return answer
    }
}