public class GogoXBallsAndBinsEasy {

	public int solve(int[] T) {
	  int a = 0;
	  
	  for(int i = 0; i < T.length / 2; i++) {
	    a += T[T.length - 1 - i] - T[i];
	  }
	  
	  return a;
	}

}
