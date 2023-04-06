#include <iostream>

int main() {
	int A;
	std::cin >> A;

	int B = ((A%10) * 10) + (A/10 + A%10) % 10;
	int count = 1;

	while(A!=B){
		count++;
		B = ((B%10) * 10) + (B/10 + B%10) % 10;
	}
	std::cout << count << std::endl;
	return 0;
}