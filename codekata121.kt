class Solution {
    fun solution(weights: IntArray): Long {
        var answer: Long = 0

        val weightList = MutableList(1001) { 0 }
        for(weight in weights) {
            answer += weightList[weight]

            answer += if(weight*2<=1000) weightList[weight*2] else 0
            if(weight%2==0) {
                answer += if(weight/2*3<=1000) weightList[weight/2*3] else 0
                answer += weightList[weight/2]
            }
            if(weight%3==0) {
                answer += weightList[weight/3*2]
                answer += if(weight/3*4<=1000) weightList[weight/3*4] else 0
            }
            if(weight%4==0) {
                answer += weightList[weight/4*3]
            }

            weightList[weight]++
        }

        return answer
    }
}