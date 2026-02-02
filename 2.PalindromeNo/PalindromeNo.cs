public class Solution {
    public bool IsPalindrome(int x) {
        var numChars = x.ToString().ToCharArray();
        for (int i = 0; i < numChars.Length; i++) {
            var start = numChars[i];
            var end = numChars[numChars.Length-(i+1)];
            if (start != end) {
                return false;
            }
        }

        return true;
    }
}
