class Solution {
    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        val termMap = terms.associate {
            val chunks = it.split(" ")
            chunks[0][0] to chunks[1].toInt() * DAYS_IN_MONTH
        }

        val todayDays = dateToDays(today)
        val answer = mutableListOf<Int>()
        for((ind, privacy) in privacies.withIndex()) {
            val chunks = privacy.split(" ")
            if(todayDays - dateToDays(chunks[0]) >= termMap[chunks[1][0]]!!) {
                answer.add(ind+1)
            }
        }
        return answer.toIntArray()
    }

    fun dateToDays(date: String): Int {
        val dateList = date.split(".")

        return (dateList[0].toInt())*DAYS_IN_MONTH*12 + dateList[1].toInt()*DAYS_IN_MONTH + dateList[2].toInt()
    }
    
    companion object {
        const val DAYS_IN_MONTH = 28
    }
}