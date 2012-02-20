import java.util.Arrays;
import java.util.HashMap;

public class MagicalGirl {

  class Witch implements Comparable<Witch> {
    double win;
    int gain;
    int day;

    public Witch(int day, double win, int gain) {
      this.day = day;
      this.win = win;
      this.gain = gain;
    }

    public int compareTo(Witch a) {
      return this.day - a.day;
    }
  }

  Witch witches[];
 
  HashMap<Integer, Double> [] dp = new HashMap[50];
  
  int M;

  public double rec(int index, int health) {
    
    if (index == witches.length) {
      return (double)health;
    }
    
    Witch w = witches[index]; 
    
    if (w.day >= health) {
      return (double)health;
    }
    
    Double answer = dp[index].get(health);
    
    if (answer == null) {

      int new_health = Math.min(health + w.gain, M + w.day);
      double win = w.win * rec(index + 1, new_health);
      double loss = (1.00 - w.win) * w.day;
      
      double fight = win + loss;
      
      double pass = rec(index + 1, health);
      
      answer = Math.max(fight, pass);

      dp[index].put(health, answer);
    }
   
    return answer;
  }

  public double maxExpectation(int M, int[] day, int[] win, int[] gain) {

    this.M = M;
    witches = new Witch[day.length];

    for (int i = 0; i < day.length; i++) {
      witches[i] = new Witch(day[i], (double) win[i] / 100.00, gain[i]);
    }

    Arrays.sort(witches);
    Arrays.fill(dp, new HashMap<Integer, Double>());

    return rec(0, M);
  }
}