/*
Given 4 strings inarr1="q,e,u", inarr2="e,l,q,a,u", instr1="equal",instr2="queue".
Create a list from all possible permutation of inarr1(after removal of comas) and instr1 and instr2.
Sort this list according to inarr2.
Print number of elements between instr1 and instr2 after sorting.
*/

import java.util.*;
public class MyClass {
    
   static void permute(String s , String answer , ArrayList<String> list)
    {  
    if (s.length() == 0)
    {
        list.add(answer);
        return;
    }
     
    for(int i = 0 ;i < s.length(); i++)
    {
        char ch = s.charAt(i);
        String left_substr = s.substring(0, i);
        String right_substr = s.substring(i + 1);
        String rest = left_substr + right_substr;
        permute(rest, answer + ch,list);
    }
}
    private static void sort(ArrayList<String> strArr, String str)
    {
    Comparator<String> myComp = new Comparator<String>()
    {
        @Override
        public int compare(String a, String b)
        {
            for(int i = 0;
                    i < Math.min(a.length(),
                                 b.length()); i++)
            {
                if (str.indexOf(a.charAt(i)) ==
                    str.indexOf(b.charAt(i)))
                {
                    continue;
                }
                else if(str.indexOf(a.charAt(i)) >
                        str.indexOf(b.charAt(i)))
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            return 0;
        }
    };
    Collections.sort(strArr, myComp);
}


    public static void main(String args[]) {
        
      Scanner sc=new Scanner(System.in);
      String arr1=sc.nextLine();
      String arr2=sc.nextLine();
      String instr1=sc.nextLine();
      String instr2=sc.nextLine();
      
      String inarr1=arr1.replace(",","");
      String inarr2=arr2.replace(",","");
      
      ArrayList<String> list=new ArrayList<>();
      permute(inarr1,"",list);
      list.add(instr1);
      list.add(instr2);
      
     sort(list,inarr2);
     System.out.println(list);
     
     int count=0,check=0;
     String next="";
     for(int i=0;i<list.size();i++)
     {
         if(list.get(i).equals(instr1) && check==0)
         {
                next=instr2;
                check=1;
         }
         else if(list.get(i).equals(instr2) && check==0)
         {

             next=instr1;
             check=1;
         }
        
        else if(check==1)
        {
            if(list.get(i).equals(next) )
            {
                break;
            }
            count++;
        }
         
     }
     System.out.println("elements between "+instr1+" and "+instr2+" = "+count);
     
    }
}