import java.math.*;
import java.util.*;
import java.io.*;

public class KingXNewBaby {

	public String isValid(String name) {
	  String vow = "aeiou";
	  String vs = "";
		
	  if(name.length() != 8) {
	    return "NO";
	  }
	  
	  int v = 0;
	  for(int i = 0; i < name.length(); i++) {
	    for(int j = 0; j < vow.length(); j++) {
	      if(vow.charAt(j) == name.charAt(i)) {
	        v ++;
	        vs += name.charAt(i);
	        break;
	      }
	    }
	  }
	  
	  if(v == 2) {
	    if(vs.charAt(0) == vs.charAt(1)) {
	      return "YES";
	    }
	  }
	  
	  return "NO";
	}
}
