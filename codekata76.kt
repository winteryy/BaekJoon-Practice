class Solution {
    fun solution(s: String): String {
        val wordList = s.split(" ")
        val sb = StringBuilder()

        for(word in wordList) {
            sb.append(word.lowercase().replaceFirstChar { it.uppercaseChar() })
            sb.append(" ")
        }
        sb.deleteCharAt(sb.lastIndex)
        return sb.toString()
    }
}