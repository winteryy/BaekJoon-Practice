class Solution {
    fun solution(ingredient: IntArray): Int {
        var answer: Int = 0
        
        var current = mutableListOf<Int>()

        for(num in ingredient) {
            current.add(num)

            if(current.size > 3 && current[current.size-1]==1 && current[current.size-2]==3 &&
                current[current.size-3]==2 && current[current.size-4]==1) {
                answer++
                for(i in 1..4) {
                    current.removeAt(current.lastIndex)
                }
            }
        }

        return answer
    }
}