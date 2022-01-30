class Solution {
    public int mostWordsFound(String[] sentences) {
        int maxNumWords= 0;

        for (String sentence : sentences) {
            String[] words = sentence.split(" ");
            maxNumWords= Math.max(maxNumWords, words.length);
        }
        
        return maxNumWords;
    }
}
