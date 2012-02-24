import java.math.*;
import java.util.*;
import java.io.*;

public class EllysCheckers {

  Map<String, Boolean> dp = new HashMap();
  
  private boolean play(boolean p, String b) {
    boolean can_win = false;
    
    if(dp.containsKey(b)) {
      return dp.get(b);
    }
    
    boolean has_move = false;
    
    if(b.charAt(b.length() - 1) == 'o') {
      System.out.println(b);
      b = b.substring(0, b.length() - 1) + ".";
      System.out.println("Modified " + b);
    }
    
    for(int i = 0; i < b.length() - 1; i++) {
      char c = b.charAt(i);
      if(c == 'o') {
        if(b.charAt(i+1) == '.') {
          String nb = b.substring(0, i) + ".o" + b.substring(i+2);
          can_win = can_win || !(play(!p, nb));
        }else if(i < b.length()-3){
          if(b.charAt(i+1) == 'o' && b.charAt(i+2) == 'o' && b.charAt(i+3) == '.') {
            String nb = b.substring(0, i) + ".ooo" + b.substring(i+4);
            can_win = can_win || !(play(!p, nb));
          }
        }
      }
    }
    
    dp.put(b, can_win);
    return can_win;
  }
  
	public String getWinner(String board) {
		return play(true, board) ? "YES" : "NO";
	}
}
