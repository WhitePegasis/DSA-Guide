/*
Replace Character Recursively
Send Feedback
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)
Output Format :
Updated string
Constraints :
1 <= Length of String S <= 10^6
Sample Input :
abacd
a x
Sample Output :
xbxcd
*/

#include <iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    if(input[0]=='\0')
        return;
    
    if(input[0]==c1)
    {
        input[0]=c2;
    }
    
    replaceCharacter(input+1,c1,c2);
    
}

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

/*
Java code:
public class Solution 
{ 
public static String replaceCharacter(String input, char c1, char c2) 
{ 
	if(input.length() == 0) 
	{ return ""; } 
	char c; 
	if(input.charAt(0) == c1)
	{ 
		c = c2; 
	} 
	else 
	{ 
		c = input.charAt(0); 
	} 
	String ans = replaceCharacter(input.substring(1), c1, c2);
	return (c + ans); 
} 
}

//main
import java.util.Scanner;

public class Runner {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String input = s.next();
		char c1 = s.next().charAt(0);
		char c2 = s.next().charAt(0);
		System.out.println(Solution.replaceCharacter(input, c1, c2));
	}
}
*/