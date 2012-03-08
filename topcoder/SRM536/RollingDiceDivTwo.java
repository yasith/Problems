import java.math.*;
import java.util.*;
import java.io.*;

public class RollingDiceDivTwo {

	public int minimumFaces(String[] rolls) {
	  int dice[] = new int[rolls[0].length()];
	  
	  for(int i = 0; i < dice.length; i++) {
	    dice[i] = 0;
	  }
	  
	  for(int i = 0; i < rolls.length; i++) {
	    int new_set[] = new int[rolls[0].length()];
	    
	    for(int j = 0; j < new_set.length; j++) {
	      new_set[j] = (int)rolls[i].charAt(j) - (int)'0';
	    }
	    
	    Arrays.sort(new_set);
	    
	    for(int j = 0; j < new_set.length; j++) {
	      dice[j] = Math.max(new_set[j], dice[j]);
	    }
	  }
	  
	  
	  int total = 0;
	  for(int i = 0; i < dice.length; i++) {
	    total += dice[i];
	  }
	  return total;
	}
}
