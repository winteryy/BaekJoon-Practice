class Solution {
    fun solution(topping: IntArray): Int {
        var answer: Int = 0
        
        val map1 = mutableMapOf<Int, Int>()
        val map2 = mutableMapOf<Int, Int>()
        topping.forEach {
            if(map2.containsKey(it)) {
                map2[it] = map2[it]!!+1
            }else{
                map2[it] = 1
            }
        }

        topping.forEach {
            if(map1.containsKey(it)) {
                map1[it] = map1[it]!!+1
            }else{
                map1[it] = 1
            }
            
            map2[it] = map2[it]!!-1
            if(map2[it]==0) map2.remove(it)
            
            if(map1.size == map2.size) answer++
        }
        
        return answer
    }
}