import java.util.*;
import java.lang.*;
import java.io.*;

public class RectArea
{
    
    //Function to find largest rectangular area possible in a given histogram.
    public static int getMaxArea(int arr[], int n)
    {
        // your code here
        //we create an empty stack here.
        Stack<Integer> s = new Stack<>();
        //we push -1 to the stack because for some elements there will be no previous
        //smaller element in the array and we can store -1 as the index for previous smaller.
        s.push(-1);
        int max_area = arr[0];
        //We declare left_smaller and right_smaller array of size n and initialize them with -1 and n as their default value.
        //left_smaller[i] will store the index of previous smaller element for ith element of the array.
        //right_smaller[i] will store the index of next smaller element for ith element of the array.
        int left_smaller[] = new int[n];
        int right_smaller[] = new int[n];
        for (int i = 0; i < n; i++){
            left_smaller[i] = -1;
            right_smaller[i] = n;
        }

        int i = 0;
        while (i < n)
        {
            while(!s.empty()&&s.peek()!=-1&&arr[i]<arr[s.peek()]){
                //if the current element is smaller than element with index stored on the
                //top of stack then, we pop the top element and store the current element index
                //as the right_smaller for the poped element.
                right_smaller[s.peek()] = (int)i;
                s.pop();
            }
            if(i>0&&arr[i]==arr[(i-1)]){
                //we use this condition to avoid the unnecessary loop to find the left_smaller.
                //since the previous element is same as current element, the left_smaller will always be the same for both.
                left_smaller[i] = left_smaller[(int)(i-1)];
            }else{
                //Element with the index stored on the top of the stack is always smaller than the current element.
                //Therefore the left_smaller[i] will always be s.top().
                left_smaller[i] = s.peek();
            }
            s.push(i);
            i++;
        }

        for(i = 0; i<n; i++){
            //here we find area with every element as the smallest element in their range and compare it with the previous area.
            // in this way we get our max Area form this.
            max_area = Math.max(max_area, arr[i]*(right_smaller[i] - left_smaller[i] - 1));
        }

        return max_area;
    }
    
    public static int maximum(int input[][]){
        int temp[] = new int[input[0].length];
        int maxArea = 0;
        int area = 0;
        for(int i=0; i < input.length; i++){
            for(int j=0; j < temp.length; j++){
                if(input[i][j] == 0){
                    temp[j] = 0;
                }else{
                    temp[j] += input[i][j];
                }
            }
            area = getMaxArea(temp,temp.length);

            if(area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
        
    }
    
    public static void main(String[] args)
    {
         int m, n, i, j;   
        Scanner sc=new Scanner(System.in);   

        //taking row as input  
        m = sc.nextInt();   
        
        //taking column as input  
        n = sc.nextInt(); 
        
        // Declaring the two-dimensional matrix   
        int input[][] = new int[m][n];   
   
        //loop for row  
        for (i = 0; i < m; i++){   
            //inner for loop for column  
            for (j = 0; j < n; j++){   
                input[i][j] = sc.nextInt();
            }
        }
        System.out.println("Maximum area is " + maximum(input));
    }
}
