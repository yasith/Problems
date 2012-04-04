public class MinimumLiars {

	public int getMinimum(int[] claim) {
	
		int sum = 0;
		
		for(int i = 1; i < claim.length+1; i++){
			int count = 0;
			
			for(int x: claim){
				sum += x;
				if(x > i)
					count ++;	
			}
			
			if(count == i)
				return i;
		}
		
		return sum == 0 ? 0 : -1;
	}

}
