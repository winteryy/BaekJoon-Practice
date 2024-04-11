class Solution {
    fun solution(n: Int, left: Long, right: Long): IntArray {
        val answer = mutableListOf<Int>()

        for(i in left .. right) {
            val rowNum = i/n+1

            if(rowNum>i%n) {
                answer.add(rowNum.toInt())
            }else {
                answer.add((i%n+1).toInt())
            }

        }
        return answer.toIntArray()
    }
}