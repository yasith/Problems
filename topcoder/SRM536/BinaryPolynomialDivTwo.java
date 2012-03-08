import java.math.*;
import java.util.*;
import java.io.*;

public class BinaryPolynomialDivTwo {

	public int countRoots(int[] a) {
	  int count = 0;
	  
	  for(int i = 0; i < 2; i++) {
	    int total = 0;
	    for(int j = 0; j < a.length; j++) {
	      total += a[j] * (int)Math.pow((double)i, (double)j);
	    }
	    
	    if(total % 2 == 0) {
	      count ++;
	    }
	  }
	  
		return count;
	}
}
