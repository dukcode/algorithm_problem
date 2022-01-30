class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int numJewelsInStones = 0;

        for (int stone = 0; stone < stones.length(); ++stone) {
            if (jewels.indexOf(stones.charAt(stone)) != -1) {
                numJewelsInStones++;
            }
        }
        
        return numJewelsInStones;
    }
}
