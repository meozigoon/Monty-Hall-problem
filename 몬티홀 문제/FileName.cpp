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
	cout << "�ùķ��̼� ���� Ƚ��: ";
	cin >> rep;
	int car, choice, open, past_choice; // �ڵ��� ��ġ, �����ϴ� ��ġ, ���� ���� ��ġ, ������ �� ��
	int cnt_3doors_change = 0, cnt_3doors_doNotChange = 0, cnt_4doors_change = 0, cnt_4doors_doNotChange = 0;

	for (long long i = 0; i < rep; i++)
	{
		//���� 3���� ���
		car = rand() % 3;
		choice = rand() % 3;
		if (car == choice) //�� �ٲ� ���
		{
			cnt_3doors_doNotChange++;
		}
		do //�ٲ� ���
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

		//���� 4���� ���
		car = rand() % 4;
		choice = rand() % 4;
		if (car == choice) //�� �ٲ� ���
		{
			cnt_4doors_doNotChange++;
		}
		do //�ٲ� ���
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

	cout << "3���� ��\n�õ�: " << rep << '\n';
	cout << "�ٲ� ���   : " << cnt_3doors_change << '(' << ((long double)cnt_3doors_change / rep) * 100 << "%)\n\n";
	cout << "�� �ٲ� ���: " << cnt_3doors_doNotChange << '(' << ((long double)cnt_3doors_doNotChange / rep) * 100 << "%)\n\n\n";
	cout << "4���� ��\n�õ�: " << rep << '\n';
	cout << "�ٲ� ���   : " << cnt_4doors_change << '(' << ((long double)cnt_4doors_change / rep) * 100 << "%)\n\n";
	cout << "�� �ٲ� ���: " << cnt_4doors_doNotChange << '(' << ((long double)cnt_4doors_doNotChange / rep) * 100 << "%)\n";
	return 0;
}