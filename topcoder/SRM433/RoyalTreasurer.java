import java.math.*;
import java.util.*;
import java.io.*;

public class RoyalTreasurer {

	public int minimalArrangement(int[] A, int[] B) {
	  Arrays.sort(A);
	  Arrays.sort(B);
	  
	  int r = 0;
	  
	  int n = A.length;
	  for(int i = 0; i < n; i++) {
	    r += A[i] * B[n - i - 1];
	    
	  }
	  
	  return r;
	}
}
