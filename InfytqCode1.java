import java.lang.Math;
import java.util.HashMap;
 
public class MyClass {
    public static void main(String args[]) {
      String instr="999 ss 22ss";
      HashMap<Character,Integer> mp=new HashMap<Character,Integer>();
      Integer digitCnt=1,alphaCnt=1;
      for(int i=0;i<instr.length();i++)
      {
          Character c=instr.charAt(i);
          if(Character.isDigit(instr.charAt(i)))
          {
              if(mp.containsKey(c))
              {
                  Integer newVal=mp.get(c)+1;
                  mp.put(c,newVal);
                  digitCnt = digitCnt<newVal ? newVal:digitCnt;
              }
              else
                mp.put(c,1);
          }
          else if( ( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
          {
              if(mp.containsKey(c))
              {
                  Integer newVal=mp.get(c)+1;
                  mp.put(c,newVal);
                  alphaCnt = alphaCnt<newVal ? newVal:alphaCnt;
              }
              else
                mp.put(c,1);
          }
      }
      
      int val=Math.abs(digitCnt-alphaCnt);
      char ch=instr.charAt(val);
      String outStr="";
      for(int i=0;i<instr.length();i++)
      {
          if(instr.charAt(i)!=ch)
          {
              if(instr.charAt(i)==' ')
              {
                  outStr+="$";
              }
              else
                outStr+=instr.charAt(i);
          }
      }

      System.out.println(outStr);
    }
}