class Solution {
    fun solution(keymap: Array<String>, targets: Array<String>): IntArray {
        var answer: IntArray = IntArray(targets.size)

        for(case in targets.indices) {
            val engList = MutableList(26) { 0 }

            keymap.forEach { key ->
                key.forEachIndexed { ind, ch ->
                    val chNum = ch-'A'
                    if(engList[chNum] == 0 || engList[chNum] > ind+1) engList[chNum] = ind+1
                }
            }

            targets.forEachIndexed { ind, target ->
                var requireNum = 0
                for(ch in target) {
                    if(engList[ch-'A']==0) {
                        requireNum = -1
                        break
                    }else {
                        requireNum += engList[ch-'A']
                    }
                }
                answer[ind] = requireNum
            }
        }

        return answer
    }
}