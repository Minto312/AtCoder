
import java.util.Scanner;

public class B {
    public static void main(String[] args){
        
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();
        String winColor = input.next();

        input.nextLine();

        String[] colorArr = input.nextLine().split(" ");

        int[] numbers = new int[N];
        String [] numbersStr = input.nextLine().split(" ");
        for (int i = 0;i < numbersStr.length;i++){
            numbers[i] = Integer.parseInt(numbersStr[i]);
        }

        String firstColor = colorArr[0];
        
        if (hasColor(winColor,colorArr)){
            printMaxIndex(winColor,colorArr,numbers);
        }else{
            printMaxIndex(firstColor,colorArr,numbers);
        }
        input.close();
    }

    public static boolean hasColor(String color,String[] colorArr){
        for (String c : colorArr){
            if (c.equals(color)) return true;
        }
        return false;
    }

    public static void printMaxIndex(String color,String[] colorArr,int[] numbers){
        int max = 0;
        int maxIndex = 0;
        for (int i = 0;i < numbers.length;i++){
            
            if (color.equals(colorArr[i]) && numbers[i] > max){
                max = numbers[i];
                maxIndex = i;
            }
        }
        System.out.println(maxIndex + 1);
    }
}
// public class B {
//     public static void main(String[] args){
        
//         Scanner input = new Scanner(System.in);

//         int N = input.nextInt();
//         String winColor = input.next();

//         input.nextLine();
//         String[] colorArr = input.nextLine().split(" ");

//         int[] numbers = new int[N];
//         String [] numbersStr = input.nextLine().split(" ");
//         for (int i = 0;i < numbersStr.length;i++){
//             numbers[i] = Integer.parseInt(numbersStr[i]);
//         }

//         int winColorMax = 0;
//         int winIndex = 0;

//         String firstColor = colorArr[0];
//         int firstColorMax = 0;
//         int firstIndex = 0;

//         for (int i = 0;i < N;i++){
            
//             if (colorArr[i].equals(winColor) && numbers[i] > winColorMax){
//                 winColorMax = numbers[i];
//                 winIndex = i;
//             }

//             if (colorArr[i].equals(firstColor) && numbers[i] > firstColorMax){
//                 firstColorMax = numbers[i];
//                 firstIndex = i;
//             }
//         }

//         if (winColorMax != 0){
//             System.out.println(winIndex + 1);
//         }else{
//             System.out.println(firstIndex + 1);
//         }
//     }
// }
