import java.math.*;
import java.util.*;
import java.io.*;

public class KingXNewCurrency {
  
  public int gcd(int a, int b) {
    if(b == 0) {
      return a;
    }
    return gcd(b, a%b);
  }

	public int howMany(int A, int B, int X) {    
    if(A % X == 0 && B % X == 0) {
	    return -1;
	  }
	  
    Set<Integer> set  = new TreeSet<Integer>();
    
    if(A % X == 0 && B % X != 0) {
      int num = B;
      while(num > 0) {
        for(int i = 1; i*i <= num; i++) {
          if(num % i == 0) {
            set.add(new Integer(i));
            set.add(new Integer(num / i));
          }
        }
        num -= X;
      }
      return set.size();
    }
    
    int temp = A;
    A = B;
    B = temp;
    if(A % X == 0 && B % X != 0) {
      int num = B;
      while(num > 0) {
        for(int i = 1; i*i <= num; i++) {
          if(num % i == 0) {
            set.add(new Integer(i));
            set.add(new Integer(num / i));
          }
        }
        num -= X;
      }
      return set.size();
    }
	  
    for(int i = A; i > 0; i -= X) {
      for(int j = B; j > 0; j -= X) {
        int target = gcd(i, j);
        
        for(int x = 1; x*x <= target; x++) {
          if(target % x == 0) {
            set.add(new Integer(x));
            set.add(new Integer(target/x));
          }
        }
      }
    }
	  
	  return set.size();
	}
}
