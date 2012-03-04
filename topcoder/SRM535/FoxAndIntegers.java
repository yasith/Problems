import java.math.*;
import java.util.*;
import java.io.*;

public class FoxAndIntegers {

	public int[] get(int AminusB, int BminusC, int AplusB, int BplusC) {
		int a = (AminusB + AplusB)/2;
		int b = (BminusC + BplusC)/2;
		int c = BplusC - b;
		
		if(AplusB - b == b && AminusB + b == a && BminusC + c == b && BplusC - b == c) {
		  return new int[] {a, b, c};
		}
		return new int[] {};
	}
}
