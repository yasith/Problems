import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Cut {

  class EelSorter implements Comparator<Integer>{

    public int compare(Integer o1, Integer o2) {
      if(o1 % 10 == 0 && o2 % 10 == 0) {
        return o1 - o2;
      }
      if(o1 % 10 == 0 || o2 % 10 == 0) {
        return o1 % 10 - o2% 10;
      }
      return o1 - o2;
    }
    
  }
  
	public int getMaximum(int[] eelLengths, int maxCuts) {
	  List eels = new ArrayList<Integer>(eelLengths.length);
	  int cut_eels = 0;
	  
	  for(int e: eelLengths) {
	    if(e == 10) {
	      cut_eels ++;
	    }else if(e > 10) {
	      eels.add(e);
	    }
	  }
	  
	  int cuts = maxCuts;
	  
	  while(!eels.isEmpty() && cuts > 0) {
	   
	    Collections.sort(eels, new EelSorter());
	   	    
	    int first = (Integer) eels.get(0);
	    eels.remove(0);
	    
	    int c = Math.min((first-1)/10, cuts);
	    cuts -= c;
	    
	    if(first % 10 == 0 && c == (first-1)/10) {
	      c ++;
	    }
	    
	    cut_eels += c;
	  }
	  
	  return cut_eels;
	}

}
