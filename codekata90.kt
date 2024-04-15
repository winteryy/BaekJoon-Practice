class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        val clothesMap = hashMapOf<String, Int>()
        
        for(cloth in clothes) {
            val kind = cloth[1]
            if(clothesMap.containsKey(kind)) {
                clothesMap[kind] = clothesMap[kind]!!+1
            }else {
                clothesMap[kind] = 2
            }
        }
        var answer = 1
        for((_, num) in clothesMap) {
            answer *= num
        }

        return answer-1
    }
}