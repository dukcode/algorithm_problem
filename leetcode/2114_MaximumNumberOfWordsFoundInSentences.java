class Solution {
    public int mostWordsFound(String[] sentences) {
        int maxNumWordsInSentences = 0;

        for (String sentence : sentences) {
            int numWords = 1;
            for (int pos = 0; pos < sentence.length(); ++pos) {
                if (sentence.charAt(pos) == ' ') {
                    numWords++;
                }
            }
            maxNumWordsInSentences = Math.max(maxNumWordsInSentences, numWords);

        }
        
        return maxNumWordsInSentences;
    }
}
