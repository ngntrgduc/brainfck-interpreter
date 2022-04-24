#include <iostream>

using namespace std;

string refactor(string ss) {
	string result = "";
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] == '+') result += ss[i];
		else if (ss[i] == '-') result += ss[i];
		else if (ss[i] == '<') result += ss[i];
		else if (ss[i] == '>') result += ss[i];
		else if (ss[i] == '[') result += ss[i];
		else if (ss[i] == ']') result += ss[i];
		else if (ss[i] == '.') result += ss[i];
		else if (ss[i] == ',') result += ss[i];
	}
	return result;
}

int main() {
	while (true) {
	// Variables declarations
	int data[30000] = {0};
	data[0] = 0;
	int pointer = 0;
	int i = 0, j, bracket_count = 0;
	char tempt;
	string s = "", ss, brainfuck_code = "";
	char c;
	
	cout << "Brainfuck > ";
	getline(cin, ss);
	s = refactor(ss);
	cout << "Input after refactored : " << s << '\n';

	while (i < s.size()) {
		if (s[i] == '>') {
			if (pointer == 30000) pointer = 0;
			else pointer++;
		}
		
		if (s[i] == '<') {
			if (pointer == 0) pointer = 30000;
			else pointer--;
		}
		
		if (s[i] == '+') {
			data[pointer]++;
//			if (data[pointer] > 255) data[pointer] -= 255;
		}
		
		if (s[i] == '-') {
			data[pointer]--;
//			if (data[pointer] < 0) data[pointer] += 255;
		}
		
		if (s[i] == '.') {
			c = data[pointer];
			brainfuck_code += c;
		}
		
		if (s[i] == '[') {
			if (data[pointer] == 0) {
				bracket_count = 1;
//				j = i + 1;
				j = i;
				while (s[j] != ']' or bracket_count != 0) {
					j++;
					if (s[j] == '[') bracket_count++;
					else if (s[j] == ']') bracket_count--;
				}
				i = j;
			}
		}
		
		if (s[i] == ']') {
			if (data[pointer] != 0) {
				bracket_count = 1;
//				j = i - 1;
				j = i;
				while (s[j] != '[' or bracket_count != 0) {
					j--;
					if (s[j] == '[') bracket_count--;
					else if (s[j] == ']') bracket_count++;	
				}
				i = j;
			}
		}
		
		if (s[i] == ',') {
			cout << "Enter your input character : ";
			cin >> tempt;
			data[pointer] = int(tempt);
		}
		
		i++;
	}
	cout << "Result > "<< brainfuck_code << "\n\n";
	}
}
