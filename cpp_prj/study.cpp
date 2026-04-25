#include <iostream>
#include <string>

class parent {
	public:
		parent(int a) {
			std::cout << "parent constructor and get a:" << a << std::endl;
		}
};

class child : public parent {
	public:
		child(int x) : parent(x) {
			std::cout << "child constructor" << std::endl;
		}
};

int main() {
	child c(20);
	return 0;
}
