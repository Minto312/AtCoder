
import java.util.Scanner;

public class D {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        long N = input.nextInt();
        long low = 1;
        long hi = N;

        long mid = (low + hi) / 2;

        long response;

        while (low <= hi){
            System.out.println("? " + mid);
            response = input.nextInt();

            if (response == 1){
                hi = mid - 1;
            }else{
                low = mid + 1;
            }
            mid = (low + hi) / 2;
        }
        System.out.println("! " + mid);
    }
    
}