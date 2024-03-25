class Solution {
    fun solution(survey: Array<String>, choices: IntArray): String {
        val answer = StringBuilder()
        val typeMap = mutableMapOf('R' to 0, 'T' to 0, 'C' to 0, 'F' to 0, 'J' to 0, 'M' to 0, 'A' to 0, 'N' to 0)
        val types = listOf('R' to 'T', 'C' to 'F', 'J' to 'M', 'A' to 'N')

        for((ind, type) in survey.withIndex()) {
            val choiceValue = choices[ind]
            if(choices[ind]<4) {
                typeMap[type[0]] = typeMap[type[0]]!! + 4-choiceValue
            }else {
                typeMap[type[1]] = typeMap[type[1]]!! + choiceValue-4
            }
        }

        for(typePair in types) {
            answer.append(if(typeMap[typePair.first]!!>=typeMap[typePair.second]!!) typePair.first else typePair.second)
        }

        return answer.toString()
    }
}