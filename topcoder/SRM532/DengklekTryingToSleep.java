public class DengklekTryingToSleep {

	public int minDucks(int[] ducks) {
	  int mx = -1, mn = 101;
	  
	  for(int i = 0; i < ducks.length; i++) {
	    mx = Math.max(mx, ducks[i]);
	    mn = Math.min(mn, ducks[i]);
	  }
	  
	  return (mx - mn) + 1 - ducks.length;
	}

}
