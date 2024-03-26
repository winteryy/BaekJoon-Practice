class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {

        val ratingMap: HashMap<String, Int> = hashMapOf()
        players.forEachIndexed { ind, name ->
            ratingMap[name] = ind
        }

        var target = 0
        var forwardPair = 0 to ""

        for(call in callings) {
            target = ratingMap[call]!!
            forwardPair = target to players[target-1]
            target--

            ratingMap[call] = target
            ratingMap[forwardPair.second] = forwardPair.first
            players[forwardPair.first] = forwardPair.second
            players[target] = call
        }

        return players
    }
}