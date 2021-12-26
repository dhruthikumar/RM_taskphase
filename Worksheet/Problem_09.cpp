// To rearrange strings in ascending order based on their lengths
// To also sort each individual string in ascending order

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sort1(string s[], int n)
{
	for (int i = 1; i < n; i++)
	{
		string temp = s[i];
		int j = i - 1;
		while (j >= 0 && temp.length() < s[j].length())
		{
			s[j+1] = s[j];
			j--;
		}
		s[j+1] = temp;
	}
}

void sort2(string s[], int n)
{
	for (int i=0 ;i<n; i++)
	{
		string temp = s[i];
		sort(temp.begin(), temp.end());
		s[i] = temp;
	}
}

void print_str(string str[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n=0;
	cout << "Enter the number of elements in the string  array: ";
	cin >> n;
	string arr[n];
	for(int i = 0; i < n; ++i)
	{
	    cout <<"Element  " << i+1 <<" :";
	    cin >> arr[i];
	}
	
	sort1(arr, n);
    cout << "Strings arranged in ascending order: " << endl;
	print_str(arr, n);
	cout << endl;
    cout << "Strings and letters in string arranged in ascending order: " << endl;
	sort2(arr, n);
	print_str(arr, n);
	return 0;
}