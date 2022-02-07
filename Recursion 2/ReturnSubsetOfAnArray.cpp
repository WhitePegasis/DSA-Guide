/*
Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include <iostream>
using namespace std;

int subset(int input[], int n, int startIndex, int output[][20]) 
{ 
	if(startIndex == n) { output[0][0] = 0; 
		return 1; 
	} 
	int smallSize = subset(input, n, startIndex+1, output); 
	for(int i = 0; i < smallSize; i++) 
	{ 
			output[i+smallSize][0] = output[i][0] + 1; 
			output[i+smallSize][1] = input[startIndex]; 
			for(int j = 1; j <= output[i][0]; j++) 
			{ 
				output[i+smallSize][j+1] = output[i][j]; 
			} 
	} 
			return 2 * smallSize; 
} 
int subset(int input[], int n, int output[][20]) 
{ 
	return subset(input, n, 0, output); 
}


int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


/*
Java code:

public class solution { 
	public static int[][] subsetsHelper(int[] input, int startIndex)
	{ 
		if(startIndex == input.length)
		{ 
			int[][] output = new int[1][0]; 
			return output; 
		} 
		int[][] smallerOutput = subsetsHelper(input, startIndex + 1); 
		int[][] output = new int[2*smallerOutput.length][]; 
		int k = 0; 
		for(int i = 0; i < smallerOutput.length; i++)
		{ 
			output[k] = new int[smallerOutput[i].length]; 
			for(int j = 0; j<smallerOutput[i].length; j++)
			{ 
				output[k][j] = smallerOutput[i][j]; 
			} 
			k++; 
		} 
		for(int i = 0; i < smallerOutput.length; i++)
		{ 
			output[k] = new int[smallerOutput[i].length+1]; 
			output[k][0] = input[startIndex]; 
			for(int j = 1; j <= smallerOutput[i].length; j++)
			{ 
				output[k][j] = smallerOutput[i][j-1]; 
			} 
			k++; 
		} 
		return output; 
	} 
	public static int[][] subsets(int input[]) 
	{ 
		return subsetsHelper(input, 0); 
	} 
}

//main file
import java.util.Scanner;

public class runner {
	
	public static int[] takeInput() {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		int arr[] = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = s.nextInt();
		}
		return arr;
	}
	
	public static void main(String[] args) {
		int[] input = takeInput();
		int output[][] = solution.subsets(input);
		for(int i = 0; i < output.length; i++) {
			for(int j = 0; j < output[i].length; j++) {
				System.out.print(output[i][j] + " ");
			}
			System.out.println();
		}
	}
}
*/