import java.math.*;
import java.util.*;

public class H{
  public static void main(String[] args) {
    
    Scanner in = new Scanner(System.in);

    int radix = in.nextInt();
    in.close();
    
    for(int i = 1; i < radix; i++){
      for(int j = 1; j < radix; j++){
        System.out.print(Integer.toString(i*j, radix) + " ");
      }
      System.out.println();
    }
    
    System.exit(0);
  }
}
