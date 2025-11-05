#include <iostream>
#include <string>
#include "stack.h"

int main() {
	std::string s = "(()()(((()";
	int sz = s.size();
	TStack<int> stk(sz);
	
	std::cout << "Error: ";
	for (int i = 0; i < sz; i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			if (stk.empty())
				std::cout << i << " ";
			else
				stk.pop();
		}
	}
	while (!stk.empty()) {
		std::cout << stk.last() << " ";
		stk.pop();
	}
}