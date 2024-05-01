class Solution {
    fun solution(n: Int): IntArray {
        val triList = List(n) {
            MutableList(it+1) { 0 }
        }

        var dir = 0
        var lenNum = n
        var curNum = 1
        var curX = 0
        var curY = 0

        while(lenNum>0) {

            if(dir==0) {
                for(i in 0 until lenNum) {
                    triList[curY+i][curX] = curNum
                    curNum++
                }
                curY += lenNum-1
                curX++
            }else if(dir==1) {
                for(i in 0 until lenNum) {
                    triList[curY][curX+i] = curNum
                    curNum++
                }
                curX += lenNum-2
                curY--
            }else {
                for(i in 0 until lenNum) {
                    triList[curY-i][curX-i] = curNum
                    curNum++
                }
                curY -= lenNum-2
                curX -= lenNum-1
            }

            lenNum--
            dir = (dir+1)%3
        }

        val answer = IntArray((1+n)*n/2)
        var arrInd = 0
        for(li in triList) {
            for(num in li) {
                answer[arrInd] = num
                arrInd++
            }
        }

        return answer
    }
}