class Solution {
    fun solution(s: String, skip: String, index: Int): String {
        val answer = StringBuilder()

        val alphabet = ('a'..'z').map {
            if(skip.contains(it)) {
                '-'
            }else {
                it
            }
        }

        s.forEach {
            var ind = it-'a'
            for(i in 0 until index) {
                ind = (ind+1)%26
                while(alphabet[ind]=='-') {
                    ind = (ind+1)%26
                }
            }

            answer.append(alphabet[ind])
        }

        return answer.toString()
    }
}