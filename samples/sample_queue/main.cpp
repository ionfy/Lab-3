#include <iostream>
#include <string>
#include "queue.h"

int main() {
	std::string s = "(()()(((()";
	int sz = s.size();
	TQueue<int> stk(sz);
	
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
		std::cout << stk.first() << " ";
		stk.pop();
	}
}