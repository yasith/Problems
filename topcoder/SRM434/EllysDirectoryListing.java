import java.math.*;
import java.util.*;
import java.io.*;

public class EllysDirectoryListing {

	public String[] getFiles(String[] files) {
	  int counter = 1;
	  if((files[files.length - 1].equals(".") ||
	      files[files.length - 1].equals(".."))
	      && (files[files.length - 2].equals(".") ||
	          files[files.length - 2].equals(".."))) {
	    counter += 2;
	  }
	  int i = 0;
	  while(counter < 3) {
	    if(files[i].equals(".") || files[i].equals("..")) {
	      String t = files[i];
	      files[i] = files[files.length - counter];
	      files[files.length - counter] = t;
	      
	      counter ++;
	    }else {
	    i++;
	    }
	  }
	  
	  System.out.println(files[files.length - 1]);
	  return files;
	}
}
