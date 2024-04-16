import kotlin.math.max

class Solution {
    fun solution(k: Int, dungeons: Array<IntArray>): Int {
        dungeonInfo = dungeons
        
        solve(k, 0, dungeons.lastIndex)
        
        return answer
    }

    fun solve(fatigue: Int, curDepth: Int, targetDepth: Int) {
        answer = max(curDepth, answer)

        for(i in 0..targetDepth) {
            if(!isVisited[i] && fatigue>=dungeonInfo[i][0]) {
                isVisited[i] = true
                solve(fatigue-dungeonInfo[i][1], curDepth+1, targetDepth)
                isVisited[i] = false
            }
        }
    }

    companion object {
        private val isVisited = BooleanArray( 8 ) { false }
        private lateinit var dungeonInfo: Array<IntArray>
        private var answer = -1
    }
}