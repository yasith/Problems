public class PasswordXGuessing {

	public long howMany(String[] guesses) {
		int ans = 0;
		String base = guesses[0];
		
		for(int i = 0; i < base.length(); i++){
			String t_base = base;
			for(int j = 0; j < 10; j++){
				
				t_base = base.substring(0, i) + (char)('0' + j) + base.substring(i+1, base.length());
			
				boolean compatible = true;
				for(int k = 0; k < guesses.length; k++){
					int dCount = 0;
					for(int l = 0; l < base.length(); l++){
						if(t_base.charAt(l) != guesses[k].charAt(l)){
							dCount ++;
						}
					}
					if(dCount != 1){
						compatible = false;
						break;
					}
				}
				
				if(compatible){
					ans ++;
				}
			}
		}
		
		return ans;
	}

}
