class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        val reserveArr = BooleanArray(n+2) { false }
        reserve.forEach { reserveArr[it] = true }
        val newLost = lost.filter {
            val isContain = reserve.contains(it)
            if(isContain) {
                reserveArr[it] = false
            }
            isContain.not()
        }.sorted()
        var answer = n-newLost.size

        for(std in newLost) {
            if(reserveArr[std-1]) {
                answer++
            }else if(reserveArr[std+1]) {
                reserveArr[std+1] = false
                answer++
            }
        }

        return answer
    }
}