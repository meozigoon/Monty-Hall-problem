#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	srand((unsigned)time(NULL));
	cout << fixed << setprecision(10);

	unsigned long long rep;
	cout << "시뮬레이션 실행 횟수: ";
	cin >> rep;
	int car, choice, open, past_choice; // 자동차 위치, 선택하는 위치, 문을 여는 위치, 이전에 고른 문
	int cnt_3doors_change = 0, cnt_3doors_doNotChange = 0, cnt_4doors_change = 0, cnt_4doors_doNotChange = 0;

	for (long long i = 0; i < rep; i++)
	{
		//문이 3개인 경우
		car = rand() % 3;
		choice = rand() % 3;
		if (car == choice) //안 바꿀 경우
		{
			cnt_3doors_doNotChange++;
		}
		do //바꿀 경우
		{
			open = rand() % 3;
		} while (open == car || open == choice);
		past_choice = choice;
		do
		{
			choice = rand() % 3;
		} while (choice == open || choice == past_choice);
		if (car == choice)
		{
			cnt_3doors_change++;
		}

		//문이 4개인 경우
		car = rand() % 4;
		choice = rand() % 4;
		if (car == choice) //안 바꿀 경우
		{
			cnt_4doors_doNotChange++;
		}
		do //바꿀 경우
		{
			open = rand() % 4;
		} while (open == car || open == choice);
		past_choice = choice;
		do
		{
			choice = rand() % 4;
		} while (choice == open || choice == past_choice);
		if (car == choice)
		{
			cnt_4doors_change++;
		}
	}

	cout << "3개의 문\n시도: " << rep << '\n';
	cout << "바꿀 경우   : " << cnt_3doors_change << '(' << ((long double)cnt_3doors_change / rep) * 100 << "%)\n\n";
	cout << "안 바꿀 경우: " << cnt_3doors_doNotChange << '(' << ((long double)cnt_3doors_doNotChange / rep) * 100 << "%)\n\n\n";
	cout << "4개의 문\n시도: " << rep << '\n';
	cout << "바꿀 경우   : " << cnt_4doors_change << '(' << ((long double)cnt_4doors_change / rep) * 100 << "%)\n\n";
	cout << "안 바꿀 경우: " << cnt_4doors_doNotChange << '(' << ((long double)cnt_4doors_doNotChange / rep) * 100 << "%)\n";
	return 0;
}