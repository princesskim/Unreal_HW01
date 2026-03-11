#include <iostream>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void AddPotion(int* p_HPPotion, int* p_MPPotion);

int main() {
	
	const int SIZE = 4;
	int status[SIZE] = { 0, };
	

	int status_HP = 0;
	int status_MP = 0;

	int status_ATK = 0; //attack
	int status_DEF = 0; //defense

	bool notFirst = false;

	while (status_HP<=50 || status_MP <= 50) {
		if (notFirst) { 
			std::cout << "HP나 MP의 값이 너무 작습니다. 50보다 큰 수를 입력해 주세요." << std::endl;
		}
		std::cout << "HP와 MP를 입력해주세요 : ";
		std::cin >> status_HP >> status_MP;
		notFirst = true;
	}

	notFirst = false;

	while (status_ATK <= 0 || status_DEF <= 0) {
		if (notFirst) {
			std::cout << "공격력이나 방어력의 값이 너무 작습니다. 0보다 큰 수를 입력해 주세요." << std::endl;
		}
		std::cout << "공격력과 방어력을 입력해주세요 : ";
		std::cin >> status_ATK >> status_DEF;
		notFirst = true;
	}

	status[0] = status_HP;
	status[1] = status_MP;
	status[2] = status_ATK;
	status[3] = status_DEF;

	std::cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << std::endl;
	std::cout << "=============================================" << std::endl;

	int HPPotion, MPPotion;
	setPotion(5, &HPPotion, &MPPotion);

	int level=1;

	std::cout	<< "<스탯 관리 시스템>"
				<< "1.HP UP" << std::endl
				<< "2.MP UP" << std::endl
				<< "3.공격력 UP" << std::endl
				<< "4.방어력 UP" << std::endl
				<< "5.현재 능력치" << std::endl
				<< "6.Level Up" << std::endl
				<< "0.나가기" << std::endl;
	
	int buttonNum = -1;

	while (buttonNum != 0) {
		
		
		std::cout << "번호를 선택해주세요: ";
		
		
		std::cin >> buttonNum;
		
		switch (buttonNum) {
		case 1:
			if (HPPotion) {
			
				status[0] += 20;
				--HPPotion;
				std::cout	<< "* HP가 20 증가되었습니다.포션이 1개 차감됩니다." << std::endl
							<< "현재 HP : " << status[0] << std::endl
							<< "남은 포션 수 : " << HPPotion << std::endl;
			}
			else {
				std::cout << "HP 포션이 부족합니다." << std::endl;
			}
			
			break;
		case 2:

			if (MPPotion) {
				status[1] += 20;
				--MPPotion;
				std::cout	<< "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << std::endl
							<< "현재 MP : " << status[1] << std::endl
							<< "남은 포션 수 : " << MPPotion << std::endl;
			
			}
			else {
				std::cout << "MP 포션이 부족합니다." << std::endl;
			}
			break;
		case 3:
			status[2] *= 2;
			std::cout	<< "* 공격력이 2배로 증가되었습니다." << std::endl
						<< "현재 공격력 : " << status[2] << std::endl;
			break;
		case 4:
			status[3] *= 2;
			std::cout	<< "* 방어력이 2배로 증가되었습니다." << std::endl
						<< "현재 방어력 : " << status[3] << std::endl;
			break;
		case 5:
			std::cout	<< "* 현재 레벨 : " << level << std::endl
						<< "* HP: " << status[0] << "\tMP:" << status[1] << std::endl
						<< "* 공격력: " << status[2] << "\t방어력:" << status[3] << std::endl
						<< "* HP 포션: " << HPPotion << "\tMP 포션: " << MPPotion << std::endl;
			break;
		case 6:
			AddPotion(&HPPotion, &MPPotion);
			++level;
			std::cout	<< "* 레벨업! HP/MP 포션이 지급됩니다." << std::endl
						<< "현재 레벨 : " << level << std::endl
						<< "남은 HP/MP 포션 수 : " << HPPotion << "/" << MPPotion << std::endl;
			break;
		case 0:
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		default:
			std::cout << "다시 입력해주세요." << std::endl;
		}

	}
	//프로그램 종료




	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void AddPotion(int* p_HPPotion, int* p_MPPotion) {
	++(*p_HPPotion);
	++(*p_MPPotion);
}