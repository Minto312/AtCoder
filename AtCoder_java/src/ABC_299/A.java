import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class A {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int charCount = scanner.nextInt();
        String strings = scanner.next();

        Pattern pattern = Pattern.compile("\\.*\\|\\.*\\*\\.*\\|\\.*");
        Matcher matcher = pattern.matcher(strings);

        if (matcher.find()){
            System.out.println("in");
        }else{
            System.out.println("out");
        }
        scanner.close();
        // System.out.println("count = " + charCount);
        // System.out.println("strings = " + strings);
    }
}
