import kotlin.math.min

class Solution {
    fun solution(rows: Int, columns: Int, queries: Array<IntArray>): IntArray {
        val answer = mutableListOf<Int>()

        val matrix = Array(rows) { rowNum->
            IntArray(columns) { colNum ->
                rowNum*columns+colNum+1
            }
        }

        for(query in queries) {

            val y1 = query[0]-1
            val x1 = query[1]-1
            val y2 = query[2]-1
            val x2 = query[3]-1

            var prev = matrix[y1][x1]
            var minNum = prev
            for(x in x1+1 .. x2) {
                minNum = min(minNum, matrix[y1][x])
                val temp = matrix[y1][x]
                matrix[y1][x] = prev
                prev = temp
            }

            for(y in y1+1 .. y2) {
                minNum = min(minNum, matrix[y][x2])
                val temp = matrix[y][x2]
                matrix[y][x2] = prev
                prev = temp
            }

            for(x in x2-1 downTo x1) {
                minNum = min(minNum, matrix[y2][x])
                val temp = matrix[y2][x]
                matrix[y2][x] = prev
                prev = temp
            }

            for(y in y2-1 downTo y1) {
                minNum = min(minNum, matrix[y][x1])
                val temp = matrix[y][x1]
                matrix[y][x1] = prev
                prev = temp
            }

            answer.add(minNum)
        }

        return answer.toIntArray()
    }
}