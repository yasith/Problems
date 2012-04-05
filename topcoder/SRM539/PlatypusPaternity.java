public class PlatypusPaternity {

	public int maxFamily(String[] femaleCompatibility, String[] maleCompatibility, 
			String[] siblingGroups) {

		int max_count = 0;
		for(String sib: siblingGroups){
			
			System.out.println("Sib: " + sib);
			boolean momc = false, dadc = false;
			for(String mom: femaleCompatibility){
				System.out.println("Mom: " + mom);
				momc = true;
				for(int i = 0; i < mom.length(); i++){
					if(sib.charAt(i) == 'Y' && mom.charAt(i) != 'Y'){
						momc = false;
						break;
					}
				}
				if(momc){
					break;
				}
			}
			
			for(String dad: maleCompatibility){
				System.out.println("Dad: " + dad);
				dadc = true;
				for(int i = 0; i < dad.length(); i++){
					if(sib.charAt(i) == 'Y' && dad.charAt(i) != 'Y'){
						System.out.println("failed: " + i);
						dadc = false;
						break;
					}	
				}
				
				if(dadc){
					break;
				}
			}
			
			System.out.println(momc + " " + dadc);
			
			if(momc && dadc){
				System.out.println("Passed");
				int counter = 0;
				for(int i = 0; i < sib.length(); i++){
					if(sib.charAt(i) == 'Y'){
						counter ++;
					}
				}
				max_count = Math.max(max_count, counter + 2);
			}
		}
		
		return max_count;
	}

}
