class Solution {
    fun solution(elements: IntArray): Int {
        var answer: Int = 0

        val lengthSet = mutableSetOf<Int>()
        val accSum = elements.toMutableList()

        accSum.forEach {
            lengthSet.add(it)
        }

        for(i in 1..elements.lastIndex) {
            for(j in 0..elements.lastIndex) {
                accSum[j] += elements[(i+j)%elements.size]
                lengthSet.add(accSum[j])
            }
        }

        return lengthSet.size
    }
}