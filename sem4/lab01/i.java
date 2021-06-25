import java.util.Arrays;
import java.util.Scanner;

public class i {
    static class Poly {
        private final static long MOD = 104857601;
        private long[] arr = new long[]{0};

        public Poly(long... arr) {
            this.arr = arr;
        }

        public Poly(Poly other) {
            this.arr = other.arr;
        }

        public long get(int ind) {
            return arr[ind];
        }

        public void add(Poly x) {
            arr = Arrays.copyOf(arr, Math.max(x.arr.length, arr.length));
            for (int i = 0; i < x.arr.length; i++) {
                arr[i] = (arr[i] + x.arr[i]) % MOD;
            }
        }

        public void negate() {
            for (int i = 0; i < arr.length; i++) {
                arr[i] = (MOD - arr[i]) % MOD;
            }
        }

        public void subtract(Poly x) {
            negate();
            add(x);
        }

        public void multiply(Poly x) {
            long[] prevArr = arr;
            arr = new long[arr.length + x.arr.length];
            for (int i = 0; i < prevArr.length; i++) {
                for (int j = 0; j < x.arr.length; j++) {
                    arr[i + j] += (prevArr[i] * x.arr[j]) % MOD;
                    arr[i + j] %= MOD;
                }
            }
        }

        public Poly copy() {
            Poly x = new Poly();
            x.arr = Arrays.copyOf(arr, arr.length);
            return x;
        }

        public Poly multiplyOnConstAndCopy(long x) {
            long[] newArr = Arrays.copyOf(arr, arr.length);
            for (int i = 0; i < arr.length; i++) {
                newArr[i] = (newArr[i] * x) % MOD;
            }
            return new Poly(newArr);
        }

        public void multiplyAndTruncate(Poly x, int m) {
            multiply(x);
            truncate(m);
        }

        public void divide(Poly x, int m) {
            long[] res = new long[m];
            res[0] = arr[0] / x.arr[0];
            for (int i = 1; i < m; i++) {
                long sum = 0;
                for (int j = Math.max(0, i - x.arr.length); j < i; j++) {
                    long cur = 0;
                    if (i - j < x.arr.length) {
                        cur = x.arr[i - j];
                    }
                    sum += ((cur % MOD) * (res[j]) % MOD) % MOD;
                    sum %= MOD;
                }
                long cur = ((MOD + (i < arr.length ? arr[i] : 0) - sum + MOD) % MOD) / x.arr[0];
                res[i] = cur;
            }
            arr = res;
        }

        public void truncate(int m) {
            arr = Arrays.copyOf(arr, m);
        }

        static long binPow(long a, long n) {
            if (n == 0) {
                return 1;
            } else if (n == 1) {
                return a % MOD;
            } else if (n % 2 == 0) {
                long x = binPow(a, n / 2);
                return (x * x) % MOD;
            } else if (n % 2 == 1) {
                long x = binPow(a, n - 1);
                return (a * x) % MOD;
            }
            return 1;
        }

        long getReverseElement(long x) {
            return binPow(x, MOD - 2);
        }

        public void exp(int m) {
            Poly res = new Poly(1);
            Poly pow = new Poly(arr);
            long fact = 1;
            for (int i = 1; i <= m; i++) {
                long coefficient = getReverseElement(fact);
                fact *= (i + 1);
                fact %= MOD;
                res.add(pow.multiplyOnConstAndCopy(coefficient));
                pow.multiplyAndTruncate(this, m);
            }
            arr = res.arr;
        }

        public void log(int m) {
            Poly res = new Poly(0);
            Poly pow = new Poly(arr);
            for (int i = 1; i <= m; i++) {
                long coefficient = (((MOD + (i % 2 == 1 ? 1 : -1)) % MOD) * getReverseElement(i)) % MOD;
                res.add(pow.multiplyOnConstAndCopy(coefficient));
                pow.multiplyAndTruncate(this, m);
            }
            arr = res.arr;
        }

        public void sqrt(int m) {
            Poly res = new Poly(1);
            Poly pow = new Poly(arr);
            long lastCoefficient = 1;
            for (int i = 0; i <= m - 1; i++) {
                long coefficient = ((((lastCoefficient * (MOD + 1 - 2L * i) % MOD) % MOD)) * getReverseElement(2L * i + 2)) % MOD;
                res.add(pow.multiplyOnConstAndCopy(coefficient));
                pow.multiplyAndTruncate(this, m);
                lastCoefficient = coefficient;
            }
            arr = res.arr;
        }

        public String toString() {
            StringBuilder res = new StringBuilder();
            for (long l : arr) {
                res.append(l);
                res.append(' ');
            }
            return res.toString();
        }

        public int deg() {
            int ind = arr.length - 1;
            while (ind >= 0 && arr[ind] == 0) {
                ind--;
            }
            return ind + 1;
        }

        public void truncateToDeg() {
            int deg = deg();
            truncate(deg);
        }
        public void printWithDeg() {
            System.out.println(deg() - 1);
            System.out.println(this);
        }

        public void alternate() {
            for (int i = 0; i < arr.length; i++) {
                if (i % 2 == 1) {
                    arr[i] = (MOD - arr[i]) % MOD;
                }
            }
        }
        public Poly getEvensPlusOne() {
            long[] newArr = new long[arr.length / 2];
            for (int i = 2; i < arr.length; i += 2) {
                newArr[i / 2] = arr[i];
            }
            newArr[0] = 1;
            return new Poly(newArr);
        }
    }

    public static long getNth(long n, long[] a, Poly q, int k) {
        while(n >= k) {
            a = Arrays.copyOf(a, 2 * a.length);
            for (int i = k; i <= 2 * k - 1; i++) {
                long sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += (((Poly.MOD - q.get(j)) % Poly.MOD) * (a[i - j])) % Poly.MOD;
                    sum %= Poly.MOD;
                }
                a[i] = sum;
            }
            //System.out.println(Arrays.toString(a));
            Poly altQ = q.copy();
            altQ.alternate();
            Poly r = altQ;
            r.multiply(q);
            int count = 0;
            for (int j = 0; j < a.length; j++) {
                if ((j % 2) == (n % 2)) {
                    count++;
                }
            }
            long[] newA = new long[count];
            count = 0;
            for (int j = 0; j < a.length; j++) {
                if ((j % 2) == (n % 2)) {
                    newA[count++] = a[j];
                }
            }
            a = newA;
            q = r.getEvensPlusOne();
            n /= 2;
        }
        return a[(int) n];
    }

    public static Poly ONE = new Poly(1);
    public static Poly X = new Poly(0, 1);
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        long n = scanner.nextLong();
        long[] a = new long[k];
        long[] c = new long[k + 1];
        for (int i = 1; i <= k; i++) {
            a[i - 1] = scanner.nextLong();
        }
        for (int i = 1; i <= k; i++) {
            c[i] = scanner.nextLong();
        }
        c[0] = -1;
        Poly q = new Poly(c);
        q.negate();
        long ans = getNth(n - 1, a, q, k);
        System.out.println(ans);
    }
}
        /*

        579775618 197315329 162175106 358317576 430837158 45939878 622502036 612937987 578975574 386608931
        971368123 518086844 452304728 673583894 66425899 889903268 160663415 758982973 957443685 680274951
        941597948 2 11 665496306 383 199650613 665503118 713055711 499197659 887544216

        */
