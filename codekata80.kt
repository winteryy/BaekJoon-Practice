class Solution {
    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 0
        var aNum = a
        var bNum = b

        while(true) {
            answer++
            
            aNum = (aNum+1)/2
            bNum = (bNum+1)/2

            if(aNum==bNum) {
                break
            }
        }

        return answer
    }
}