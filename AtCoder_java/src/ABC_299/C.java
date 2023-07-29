
import java.util.Scanner;

public class C{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int length = input.nextInt();
        String strings = input.next();

        boolean has_o = false;
        int oCount = 0;
        int oMax = 0;
        boolean has_flg = false;
        char c;
        char o = "o".charAt(0);
        for (int i = 0;i < strings.length();i++){
            c = strings.charAt(i);
            if (c == o){
                has_o = true;
                oCount++;
            }else{
                has_flg = true;
                if (oCount > oMax){
                    oMax = oCount;
                }
                oCount = 0;
            }
        }

        if (has_flg && has_o){
            if (oCount > oMax){
                oMax = oCount;
            }
            System.out.println(oMax);
        }else{
            System.out.println(-1);
        }
    }
}