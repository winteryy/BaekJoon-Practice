class Solution {
    fun solution(wallpaper: Array<String>): IntArray {
        var answer: IntArray = intArrayOf(wallpaper.size, wallpaper[0].length, -1, -1)

        for((yInd, str) in wallpaper.withIndex()) {
            for((xInd, ch) in str.withIndex()) {
                if(ch=='#') {
                    if(answer[0]>yInd) answer[0]=yInd
                    if(answer[1]>xInd) answer[1]=xInd
                    if(answer[2]<yInd+1) answer[2]=yInd+1
                    if(answer[3]<xInd+1) answer[3]=xInd+1
                }
            }
        }
        
        return answer
    }
}