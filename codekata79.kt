class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        val halfNum = (brown-4)/2

        for(height in 1..halfNum/2) {
            if(height*(halfNum-height) == yellow) {
                return intArrayOf(halfNum-height+2, height+2)
            }
        }
        return intArrayOf()
    }
}
