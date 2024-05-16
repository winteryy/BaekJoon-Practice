class Solution {
    fun solution(data: Array<IntArray>, col: Int, row_begin: Int, row_end: Int): Int {
        var answer: Int = 0

        val sortedData = data.sortedWith(
            compareBy(
                { it[col-1] },
                { -it[0] }
            )
        )

        for(i in row_begin-1 until row_end) {
            var sum = 0
            for(element in sortedData[i]) {
                sum += element%(i+1)
            }
            answer = answer.xor(sum)
        }

        return answer
    }
}