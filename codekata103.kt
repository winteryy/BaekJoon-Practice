class Solution {
    fun solution(numbers: IntArray): String {
        val sb = StringBuilder()

        numbers.map {
            it.toString()
        }.sortedWith {str1, str2 ->
            val bd1 = (str1+str2).toBigDecimal()
            val bd2 = (str2+str1).toBigDecimal()
            if(bd1>bd2) {
                -1
            } else if(bd1==bd2) {
                0
            } else {
                1
            }
        }.forEach {
            sb.append(it)
        }
        return if(sb.toString().startsWith("0")) "0" else sb.toString()
    }
}