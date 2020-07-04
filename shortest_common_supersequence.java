import java.util.*;

class shortest_common_supersequence{
    public static String scs(int[][] dp, String s, String t, int m, int n){
        String result = "";
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(s.charAt(i - 1) == t.charAt(j - 1)){
                result = s.charAt(i - 1) + result;
                i--;
                j--;
            }
            else{
                if(dp[i][j] == dp[i - 1][j]){
                    result = s.charAt(i - 1) + result;
                    i--;
                }
                else{
                    result = t.charAt(j - 1) + result;
                    j--;
                }
            }
        }
        if(i == 0 && j != 0){
            while(j > 0){
                result = t.charAt(j - 1) + result;
                j--;
            }
        }
        if(j == 0 && i != 0){
            while(i > 0){
                result = s.charAt(i - 1) + result;
                i--;
            }
        }

        return result;
    }
    public static void lcs(int[][] dp, String s, String t, int m, int n){
        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s.charAt(i - 1) == t.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first string : ");
        String s = sc.nextLine();
        System.out.println("Enter second string : ");
        String t = sc.nextLine();
        // ArrayList<ArrayList<Integer>> dp = new ArrayList<ArrayList<Integer>>();
        
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m + 1][n + 1];
        lcs(dp, s, t, m, n);
        System.out.println("Longest common subsequence length : " + dp[m][n]);
        // System.out.println(dp);
        System.out.println("Shotest common superstring : " + scs(dp, s, t, m, n));
    }
}