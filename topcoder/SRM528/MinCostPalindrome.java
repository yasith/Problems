public class MinCostPalindrome {

	public int getMinimum(String s, int oCost, int xCost) {
	  int sum = 0;
	  int n = s.length() - 1;
	  
	  for(int i = 0; i < s.length() / 2; i++) {
	    if(s.charAt(i) == '?' && s.charAt(n - i) == '?') {
	      sum += Math.min(oCost, xCost) * 2;
	    }else if(s.charAt(i) == '?' || s.charAt(n-i) == '?') {
	      if(s.charAt(i)  == 'o' || s.charAt(n-i) == 'o') {
	        sum += oCost;
	      }else {
	        sum += xCost;
	      }
	    }else if(s.charAt(i) != s.charAt(n-i)) {
	      return -1;
	    }
	  }
	  
	  return sum;
	}

}
