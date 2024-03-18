class Solution {
    fun solution(babbling: Array<String>): Int {
        var answer: Int = 0
        val words = listOf("aya", "ye", "woo", "ma")
        val duplicatedWords = listOf("ayaaya", "yeye", "woowoo", "mama")

        for(babblingStr in babbling) {
            var dupFlag = false
            for(dupWord in duplicatedWords) {
                if(babblingStr.contains(dupWord)) {
                    dupFlag = true
                    break
                }
            }

            if(dupFlag) continue
            var convertStr = babblingStr

            for(word in words) {
                convertStr = convertStr.replace(word, " ")
            }
            if(convertStr.isBlank()) answer++
        }
        return answer
    }
}