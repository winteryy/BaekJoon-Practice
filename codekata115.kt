import java.util.PriorityQueue
import kotlin.math.max

class Solution {
    fun solution(book_time: Array<Array<String>>): Int {
        val pq = PriorityQueue<Pair<Int, Int>> { a, b -> a.second - b.second }
        val sortedBookTime = book_time.map {
            timeStrToInt(it[0]) to timeStrToInt(it[1])
        }.sortedBy { it.first }

        var maxNum = 0
        for(bookTime in sortedBookTime) {
            while(pq.isNotEmpty()&&pq.peek().second+10<=bookTime.first) {
                pq.poll()
            }
            pq.add(bookTime)
            maxNum = max(maxNum, pq.size)
        }

        return maxNum
    }

    fun timeStrToInt(str: String): Int {
        val timeArr = str.split(":")

        return timeArr[0].toInt()*60 + timeArr[1].toInt()
    }
}
