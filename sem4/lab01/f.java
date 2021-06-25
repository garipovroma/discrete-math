import java.util.Scanner;

public class f {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long MOD = 1000000007;
        long[] c = new long[n];
        long[] was = new long[m + 1];
        long[][] dp = new long[m + 1][2];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
            dp[i][1] = 0;
            was[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
            was[(int) c[i]] = 1;
        }
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 0;
            dp[i][1] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i][0] += (dp[i - j][1] * was[j]) % MOD;
                dp[i][0] %= MOD;
            }
            System.out.print(dp[i][0] + " ");
            for (int j = 0; j <= i; j++) {
                dp[i][1] += (dp[j][0] * dp[i - j][0]) % MOD;
                dp[i][1] %= MOD;
            }
        }
    }
}
