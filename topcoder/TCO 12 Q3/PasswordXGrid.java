import java.util.HashMap;

public class PasswordXGrid {

	public String[] h;
	public String[] v;
	
	int dp[][] = new int[50][50];
	
	int getMax(int x, int y){
		
		if(dp[x][y] == -1){
			
			int a = x > 0 ? (int)(h[y].charAt(x-1)-'0') + getMax(x-1, y) : 0;
			int b = y > 0 ? (int)(v[y-1].charAt(x)-'0') + getMax(x, y-1) : 0;
			
			dp[x][y] = Math.max(a, b);
		}
		
		return dp[x][y];
	}
	
	public int minSum(String[] horizontal, String[] vertical) {
		this.h = horizontal;
		this.v = vertical;
		
		for(int i = 0; i < 50; i++)
			for(int j = 0; j < 50; j++)
				dp[i][j] = -1;
		
		int ans = getMax(h[0].length(), h.length - 1);
		
		return ans;
	}

}
