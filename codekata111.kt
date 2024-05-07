import java.util.Stack

class Solution {
    fun solution(maps: Array<String>): IntArray {
        var answer = mutableListOf<Int>()

        val newMaps = maps.map {
            it.toCharArray()
        }

        for(y in 0 until newMaps.size) {
            for(x in 0 until newMaps[0].size) {
                val st = Stack<Pair<Int, Int>>()
                var sum = 0
                if(newMaps[y][x]!='X') {
                    st.push(y to x)
                }

                while(st.isNotEmpty()) {
                    val curY = st.peek().first
                    val curX = st.peek().second
                    st.pop()

                    if(newMaps[curY][curX]=='X') continue

                    sum+=newMaps[curY][curX]-'0'
                    newMaps[curY][curX] = 'X'

                    for(i in 0 .. 3) {
                        val newY = curY + dy[i]
                        val newX = curX + dx[i]

                        if(newY>=0&&newY<newMaps.size&&newX>=0&&newX<newMaps[0].size&&newMaps[newY][newX]!='X') {
                            st.push(newY to newX)
                        }
                    }
                }

                if(sum!=0) answer.add(sum)
            }
        }

        return if(answer.isEmpty()) intArrayOf(-1) else answer.toIntArray().sortedArray()
    }

    companion object {
        val dx = intArrayOf(1, 0, -1, 0)
        val dy = intArrayOf(0, 1, 0, -1)
    }
}