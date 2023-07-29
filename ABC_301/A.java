

import java.util.Scanner;
public class A{
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        String strings = input.next();

        int T = 0;
        int A = 0;
        int countT = 0;
        int countA = 0;

        for (int i = 0;i < N;i++){
            if (strings.charAt(i) == "T".charAt(0)){
                T++;
                countT = i;
                System.err.println("T = " + countT);
            }else{
                A++;
                countA = i;
                System.err.println("A = " + countA);
            }
        }

        String res = "";
        if (T == A){
            if (countT < countA){
                res = "T";
                e("T < A = " + countT + " < " + countA);
            }else{
                res = "A";
                e("T > A = " + countT + " > " + countA);
            }
        }
        if (T > A){
            res = "T";
            e("T >> A = " + T + " >> " + A);
        }else if (T < A){
            res = "A";
            e("T << A = " + T + " << " + A);
        }

        System.out.println(res);
    }
    static void e(String text){System.err.println(text);}
}