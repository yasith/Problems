import java.util.Arrays;
import java.util.Comparator;

public class KingSort {

  class RomanComparator implements Comparator<String> {

    private int roman(String a) {
      a += '0';
      int sum = 0;

      for (int i = 0; i < a.length() - 1; i++) {
        char c = a.charAt(i);
        char n = a.charAt(i + 1);
        switch (c) {
        
          case 'I':
            if (n == 'V') {
              sum += 4;
              i++;
            } else if (n == 'X') {
              sum += 9;
              i++;
            } else {
              sum += 1;
            }
            break;
          
          case 'V':
            sum += 5;
            break;
          
          case 'X':
            if (n == 'L') {
              sum += 40;
              i++;
            } else {
              sum += 10;
            }
            break;
          case 'L':
            sum += 50;
            break;
        }
      }

      return sum;
    }

    public int compare(String a, String b) {
      String[] n1 = a.split(" ");
      String[] n2 = b.split(" ");

      int status = n1[0].compareTo(n2[0]);

      if (status == 0) {
        status = roman(n1[1]) - roman(n2[1]);
      }

      return status;
    }
  }

  public String[] getSortedList(String[] kings) {
    Arrays.sort(kings, new RomanComparator());
    return kings;
  }

}
