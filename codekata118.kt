import java.util.Stack

class Solution {
    fun solution(places: Array<Array<String>>): IntArray {
        var answer: IntArray = intArrayOf(1,1,1,1,1)

        for((ind, place) in places.withIndex()) {
            val peopleList = mutableListOf<Pair<Int, Int>>()

            for(y in 0..4) {
                for(x in 0 .. 4) {
                    if(place[y][x]=='P') {
                        peopleList.add(y to x)
                    }
                }
            }
            var flag = false

            for(person in peopleList) {
                val visited = List(5) { MutableList(5) { false } }
                val st = Stack<Triple<Int, Int, Int>>()
                st.push(Triple(person.first, person.second, 0))

                while(st.isNotEmpty()) {
                    val curY = st.peek().first
                    val curX = st.peek().second
                    val depth = st.peek().third
                    st.pop()

                    if(visited[curY][curX]) continue
                    if(place[curY][curX]=='P' && depth!=0) {
                        flag = true
                        break
                    }else if(place[curY][curX]=='X' || depth==2) continue
                    visited[curY][curX] = true

                    for(i in 0..3) {
                        val newY = curY+dy[i]
                        val newX = curX+dx[i]

                        if(newY in 0..4 && newX in 0..4 && visited[newY][newX].not()) {
                            st.push(Triple(newY, newX, depth+1))
                        }
                    }
                }
                if(flag) break
            }
            if(flag) {
                answer[ind] = 0
            }
        }
        return answer
    }

    companion object {
        val dy = intArrayOf(0, 1, 0, -1)
        val dx = intArrayOf(1, 0, -1, 0)
    }
}