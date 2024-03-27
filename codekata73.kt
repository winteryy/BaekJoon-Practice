class Solution {
    fun solution(park: Array<String>, routes: Array<String>): IntArray {
        var curX = 0
        var curY = 0
        val xLen = park[0].length
        val yLen = park.size

        for((y, str) in park.withIndex()) {
            for((x, ch) in str.withIndex()) {
                if(ch=='S') {
                    curX = x
                    curY = y
                }
            }
        }

        for(route in routes) {
            val cmd = route.split(" ")
            val op = cmd[0][0]
            val dist = cmd[1].toInt()
            when(op) {
                'E' -> {
                    if(curX+dist<xLen) {
                        var flag = true
                        for(i in 1 .. dist) {
                            if(park[curY][curX+i]=='X') {
                                flag = false
                                break
                            }
                        }

                        if(flag) {
                            curX += dist
                        }
                    }
                }

                'W' -> {
                    if(curX-dist>=0) {
                        var flag = true
                        for(i in 1 .. dist) {
                            if(park[curY][curX-i]=='X') {
                                flag = false
                                break
                            }
                        }

                        if(flag) {
                            curX -= dist
                        }
                    }
                }

                'N' -> {
                    if(curY-dist>=0) {
                        var flag = true
                        for(i in 1 .. dist) {
                            if(park[curY-i][curX]=='X') {
                                flag = false
                                break
                            }
                        }

                        if(flag) {
                            curY -= dist
                        }
                    }
                }

                'S' -> {
                    if(curY+dist<yLen) {
                        var flag = true
                        for(i in 1 .. dist) {
                            if(park[curY+i][curX]=='X') {
                                flag = false
                                break
                            }
                        }

                        if(flag) {
                            curY += dist
                        }
                    }
                }
            }
        }

        return intArrayOf(curY, curX)
    }
}