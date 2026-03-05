#include <iostream>

int main(void) {
	int request = 0;
	std::cout << "Give your Diamond Num : ";
	std::cin >> request;

	if (request <= 0) {
		std::cout << "잘못된 입력입니다. 양의 정수를 입력하세요." << std::endl;
		return 1;
	}


	for (int i = 1; i <= request; ++i) {
		//(request-1)개 공백
		//(2*i-1)개 별
		for (int j = 0; j < (request - i); ++j) {
			std::cout << " ";
		}
		for (int j = 0; j < (2 * i - 1); ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	//위에 과정을 반대로 하면 되는데, i == request 인 행 하나만 제외
	for (int i = request - 1; i >= 1; --i) {
		//(request-1)개 공백
		//(2*i-1)개 별
		for (int j = 0; j < (request - i); ++j) {
			std::cout << " ";
		}
		for (int j = 0; j < (2 * i - 1); ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return 0;
}