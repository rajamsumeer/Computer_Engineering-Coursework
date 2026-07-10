// 1.4
// import java.lang.Math;

// public class N {
//     public static void main(String[] args) {
//         for (int i = 1; i <= 1024; i*=2) {
//             System.out.println("N:" + i);
//             System.out.println("Power:" + Math.pow(i, 2));
//             int log2result = (int)(Math.log(i) / Math.log(2));
//             System.out.println("log2N:"+ log2result);
//             int nlogn = i * log2result;
//             System.out.println("Nlog2N:" + nlogn);
//         }
//     }
// }

import java.lang.Math;

public class N {
    public static void main(String[] args) {
        for (int i = 1; i <= 1024; i*=2) {
            int log2result = (int)(Math.log(i) / Math.log(2));
            int nlogn = i * log2result;
            System.out.println(i + " " + Math.pow(i, 2) + " " + log2result + " " + nlogn);
        }
    }
}