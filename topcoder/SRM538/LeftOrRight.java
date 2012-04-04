public class LeftOrRight {
	
	public int maxDistance(String program) {
		
		int lmax = 0;
		int rmax = 0;
		
		for(int i = 0; i < program.length(); i++){
			char c = program.charAt(i);
			lmax = c == 'R' ? lmax - 1 : lmax + 1;
			rmax = c == 'L' ? rmax - 1 : rmax + 1;
		}
		
		return Math.max(lmax, rmax);
	}

}
