class Solution {
    fun solution(answers: IntArray): IntArray {
        var answer = intArrayOf()

        val num1 = listOf(1, 2, 3, 4, 5)
        val num2 = listOf(2, 1, 2, 3, 2, 4, 2, 5)
        val num3 = listOf(3, 3, 1, 1, 2, 2, 4, 4, 5, 5)

        var num1Score = 0
        var num2Score = 0
        var num3Score = 0

        for((ind, correctNum) in answers.withIndex()) {
            if(num1[ind%5]==correctNum) num1Score++
            if(num2[ind%8]==correctNum) num2Score++
            if(num3[ind%10]==correctNum) num3Score++
        }

        var max = -1
        if(max<num1Score) {
            answer += 1
            max = num1Score
        }
        if(max<num2Score) {
            answer = intArrayOf(2)
            max = num2Score
        }else if(max==num2Score) {
            answer += 2
        }
        if(max<num3Score) {
            answer = intArrayOf(3)
        }else if(max==num3Score) {
            answer += 3
        }

        return answer
    }
}