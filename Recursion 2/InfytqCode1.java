import java.lang.Math;
import java.util.HashMap;
 
public class MyClass {
    public static void main(String args[]) {
      String instr="Hi there";
      HashMap<Character,Integer> mp=new HashMap<Character,Integer>();
      Integer digitCnt=0,alphaCnt=0;
      for(int i=0;i<instr.length();i++)
      {
          Character c=instr.charAt(i);
          if(Character.isDigit(instr.charAt(i)))
          {
              Integer newVal=1;
              if(mp.containsKey(c))
              {
                  newVal=mp.get(c)+1;
                  mp.put(c,newVal);
                  
              }
              else
                mp.put(c,1);
                
            digitCnt = digitCnt<newVal ? newVal:digitCnt;
          }
          else if( ( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
          {
              Integer newVal=1;
              if(mp.containsKey(c))
              {
                  newVal=mp.get(c)+1;
                  mp.put(c,newVal);
              }
              else
                mp.put(c,1);
            
            alphaCnt = alphaCnt<newVal ? newVal:alphaCnt;
          }
      }
      
      int val=Math.abs(digitCnt-alphaCnt);
      char ch=instr.charAt(val);
      String outStr="";
      for(int i=0;i<instr.length();i++)
      {
          if(instr.charAt(i)==' ')
            {
                 outStr+="$";
             }
          else if(instr.charAt(i)!=ch)
          {
            outStr+=instr.charAt(i);
          }
      }

      System.out.println(outStr);
    }
}