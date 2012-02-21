public class DengklekMakingChains {

	public int maxBeauty(String[] chains) {
	  
	  int l, r, m, total;
	  l = r = m = total = 0;
	  String[] o = new String[chains.length]; // Others -> #.#
	  int ol = 0; // number of others
	  
	  for(int i = 0; i < chains.length; i++) {
	    int t = 0;
	    boolean rusty = false;
	    for(int j = 0; j < 3; j++) {
	      if(chains[i].charAt(j) != '.') {
	        t += (int) chains[i].charAt(j) - '0';
	      }else {
	        rusty = true;
	      }
	    }
	    
	    if(! rusty) {
	      m += t;
	    }else if(chains[i].charAt(0) == '.' && chains[i].charAt(2) == '.'){
	      total = Math.max(total, t); // Individual necklace
	    }else if(chains[i].charAt(0) == '.') {
	      l = Math.max(l, t);
	      System.out.println("Left " + chains[i]);
	    }else if(chains[i].charAt(2) == '.') {
	      r = Math.max(r, t);
	    }else if(chains[i].charAt(1) == '.') {
	      o[ol++] = chains[i];
	      System.out.println("Other " + chains[i]);
	    }
	  }
	  
	  System.out.println("l " + l + " r " + r + " m " + m);
	 
	  int extras[][] = new int[ol+1][2];
	  extras[ol][0] = extras[ol][1] = 0; // Add to just one side
	  
	  for(int i = 0; i < ol; i++) {
	    extras[i][0] = ((int) o[i].charAt(2) - '0') - l;
	    extras[i][1] = ((int) o[i].charAt(0) - '0') - r;
	  }
	  
	  int me = 0; // maximum extras
	  for(int i = 0; i <= ol; i ++) {
	    for(int j = 0; j <= ol; j ++) {
	      if( i == j)
	        continue;
	      
	      me = Math.max(extras[i][0] + extras[j][1], me);
	    }
	  }
	  
	  System.out.println("l " + l + " r " + r + " m " + m);
	  
	  total = Math.max(total, l+m+r+me);
	  return total;
	}

}

// Interesting test case: chains = {"..1", "9.8", "567", "24.", "8.6", ".42"}