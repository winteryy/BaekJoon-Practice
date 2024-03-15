class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        var numOfWinNum = 0
        var numOfLoseNum = 0
        for(num in lottos) {
            if(num!=0) {
                if(num in win_nums) numOfWinNum++ else numOfLoseNum++
            }
        }
        var answer: IntArray = intArrayOf(
            if(numOfLoseNum<5) 1+numOfLoseNum else 6,
            if(numOfWinNum>1) 7-numOfWinNum else 6
            )
        return answer
    }
}