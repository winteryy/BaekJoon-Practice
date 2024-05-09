class Solution {
    fun solution(k: Int, d: Int): Long {
        var yCursor = 0L
        var xCursor = d.toLong()/k*k
        var dist = d.toLong()*d
        var sum = 0L

        while(yCursor<=d) {

            while(yCursor*yCursor+xCursor*xCursor>dist) {
                xCursor-=k
            }

            sum+=xCursor/k+1
            yCursor+=k
        }

        return sum
    }
}