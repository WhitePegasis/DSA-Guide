/*
Pair Star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

#include <iostream>
using namespace std;

int length(char input[]) 
{ 
	int len = 0; 
	for (int i = 0; input[i] != '\0'; i++) 
		{ len++; } 
	return len; 
} 
void pairStar(char input[], int start) 
{ 
	if (input[start] == '\0') 
		{ return; } 
	pairStar(input, start + 1); 
	if (input[start] == input[start + 1]) 
		{ 
			int l = length(input); 
			input[l + 1] = '\0'; 
			int i; 
			for (i = l - 1; i >= start + 1; i--) 
			{ 
				input[i + 1] = input[i]; 
			} 
			input[i + 1] = '*'; 
		} 
	} 
void pairStar(char input[]) 
{ 
	pairStar(input, 0); 
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

/*
Java Code:
public class solution { 
	public static String addStars(String s) 
	{ 
		if(s.length() <= 1) 
			{ return s; } 
		String out = addStars(s.substring(1)); 
		if(s.charAt(0) == s.charAt(1)) 
			{ 
				out = s.charAt(0) + "*" + s.charAt(1) + out.substring(1); 
			} 
else 
	{ 
		out = s.charAt(0) + out; 
	} 
	return out; 
} 
}

//main file
import java.util.Scanner;

public class runner {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String input = s.nextLine();
		System.out.println(solution.addStars(input));
	}
}
*/