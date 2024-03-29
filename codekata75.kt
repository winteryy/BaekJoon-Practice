class Solution {
    fun solution(s: String): String {
        val numList = s.split(" ").map { it.toInt() }.sorted()

        return "${numList.first()} ${numList.last()}"
    }
}