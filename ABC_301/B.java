
import java.util.Scanner;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();

        int[] numbers = new int[N];
        for (int i = 0; i < N;i++){
            numbers[i] = input.nextInt();
        }

        StringBuilder res = new StringBuilder();
        int i = 0;
        while (i < numbers.length){
            int abs = numbers[i] - numbers[i+1];
            if (abs == 1 || abs == -1){
                res.append(numbers[i]);
            }else{
                res.append(numbers[i]);

                if (abs > 0){
                    for (int x = numbers[i] - 1;x > numbers[i+1];i--){
                        res.append(x);
                    }
                }else{
                    for (int x = numbers[i] + 1;x < numbers[i+1];i++){
                        res.append(x);
                    }
                }
            }
            i++;
        }
        res.append(numbers[i]);
        System.out.println(res);
    }
}
