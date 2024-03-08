class Solution {
    fun solution(a: Int, b: Int): String {
        val dayOfWeek = listOf("FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU")
        var daysSum = b-1
        for(i in 1 until a) daysSum += getDays(i)

        return dayOfWeek[daysSum%7]
    }

    fun getDays(month: Int): Int {
        return when(month) {
            1, 3, 5, 7, 8, 10, 12 -> 31
            2 -> 29
            else -> 30
        }
    }
}