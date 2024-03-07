class Solution {
    fun solution(k: Int, score: IntArray): IntArray {
        
        var answer: IntArray = intArrayOf()
        var fame = mutableListOf<Int>()
        
        for(v in score) {
            val curMin = fame.minOrNull()?:0
            
            if(fame.size < k) {
                fame.add(v)
            }else if(curMin<=v) {
                fame.remove(curMin)
                fame.add(v)
            }
            answer += fame.minOrNull()!!
        }
        
        return answer
    }
}