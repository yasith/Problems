import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class EllysJuice {

	class Player implements Comparable<Player>{
		
		String name;
		int drinks;
		
		public Player(String name, int drinks){
			this.name = name;
			this.drinks = drinks;
		}
		
		public int compareTo(Player o) {
			return this.drinks - o.drinks;
		}
		
	}
	
	double f(int n){
		return 1.0/(Math.pow(2, Math.ceil( ((double)(n+1))/2.0 ) ) );
	}
	
	HashMap<String, Integer>map = new HashMap<String, Integer>();
	
	public String[] getWinners(String[] players) {
		for(String player: players){
			if(map.containsKey(player)){
				map.put(player, new Integer(map.get(player) + 1));
			}else{
				map.put(player, 1);
			}
		}
	
		ArrayList<Player> plist = new ArrayList<EllysJuice.Player>();
		
		Object[] pnames = map.keySet().toArray();
		Object[] pvals = map.values().toArray();
		
		for(int i = 0; i < pnames.length; i++){
			plist.add(new Player((String)pnames[i], (Integer)pvals[i]));
		}
		
		Collections.sort(plist);
		
		ArrayList<String> wlist = new ArrayList<String>();
		
		if(plist.size() == 1){
			return new String[]{plist.get(0).name};
		}
		
		for(int i = 0; i < plist.size(); i++){
			if(i == 0){
				double total = 0;
				for(int j = 0; j < plist.get(i).drinks; j++){
					total += f(j);
				}
				double other = 0;
				for(int j = 0; j < plist.get(i+1).drinks; j++){
					other += f(j + plist.get(i).drinks);
				}
				
				
				if(total > other){
					wlist.add(plist.get(i).name);
				}
			} else{
				double total = 0;
				for(int j = 0; j < plist.get(i).drinks; j++){
					total += f(j);
				}
				double other = 0;
				for(int j = 0; j < plist.get(0).drinks; j++){
					other += f(j + plist.get(i).drinks);
				}
				
				
				if(total > other){
					wlist.add(plist.get(i).name);
				}
			}
		}
		
		Collections.sort(wlist);
		String arr[] = new String[wlist.size()];
		
		int i = 0;
		for(String name: wlist){
			arr[i++] = name;
		}
		
		return arr;
	}

}
