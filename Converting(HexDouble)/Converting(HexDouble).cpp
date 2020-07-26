//============================================================================
// Name        : PZ.cpp
// Author      : I am
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "pch.h"
#include <locale.h>
#include <stdlib.h>
#include <iostream> // ���������� ����� ������ ������ ��� hex

using namespace std;

template <typename FROM, typename TO>

inline TO pntr_Translate(FROM x);

template <typename FROM, typename TO>

inline TO memcpy_Translate(FROM x);

template <typename FROM, typename TO>

inline TO union_Translate(FROM x);

template <typename FROM, typename TO>

inline TO cast(FROM x);

enum OPERATIONS
{
	FLOAT_TO_HEX = 1, DOUBLE_TO_HEX, HEX_TO_FLOAT, HEX_TO_DOUBLE, EXIT
};

enum WAY
{
	POINTER = 1, MEMCPY, UNION, CAST
};

int GetOperation()
{
	cout << "������� ����� ��������: " << endl;
	cout << FLOAT_TO_HEX << "- float � hex" << endl;
	cout << DOUBLE_TO_HEX << " - double � hex" << endl;
	cout << HEX_TO_FLOAT << " - hex � float" << endl;
	cout << HEX_TO_DOUBLE << " - hex � double" << endl;
	cout << EXIT << " - �����" << endl;
	int number;
	cin >> number;
	return number;
}

int GetWay()
{
	cout << "������� ������ ��������: " << endl;;
	cout << POINTER << " - � ������� ����������" << endl;
	cout << MEMCPY << " - � ������� ����������� ������;" << endl;
	cout << UNION << " - � ������� �����������;" << endl;
	cout << CAST << " - c ������� reinterpret_cast;" << endl;;
	int w;
	cin >> w;
	return w;
}

int main()
{
	using namespace std;
	int FLAG = 1;
	setlocale(LC_ALL, "Russian");
	do {
		switch (GetOperation())
		{
		case FLOAT_TO_HEX:
		{
			float x;
			switch (GetWay())
			{
			case POINTER:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << pntr_Translate<float, unsigned>(x) << endl;
				break;
			case MEMCPY:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << memcpy_Translate<float, unsigned>(x) << endl;
				break;
			case UNION:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << union_Translate<float, unsigned>(x) << endl;
				break;
			case CAST:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << cast<float, unsigned>(x) << endl;
				break;
			default:
				cout << "�������� ������!" << endl;
				break;
			}
			break;
		}
		case DOUBLE_TO_HEX:
		{
			double x;
			switch (GetWay())
			{
			case POINTER:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << pntr_Translate<double, unsigned long long>(x) << endl;
				break;
			case MEMCPY:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << memcpy_Translate<double, unsigned long long>(x) << endl;
				break;
			case UNION:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << union_Translate<double, unsigned long long>(x) << endl;
				break;
			case CAST:
				cout << "������� ������������ �����: " << endl;;
				cin >> x;
				cout << x << " � ����������������� ������� = ";
				cout << uppercase << hex << cast<double, unsigned long long>(x) << endl;
				break;
			default:
				cout << "�������� ������!" << endl;
				break;
			}
			break;
		}
		case HEX_TO_FLOAT:
		{
			unsigned x;
			switch (GetWay())
			{
			case POINTER:
				cout << "������� 4-�������� ����������������� �����: " << endl;;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(10);
				cout << pntr_Translate<unsigned, float>(x) << endl;
				break;
			case MEMCPY:
				cout << "������� 4-�������� ����������������� �����: " << endl;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(10);
				cout << memcpy_Translate<unsigned, float>(x) << endl;
				break;
			case UNION:
				cout << "������� 4-�������� ����������������� �����: " << endl;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(10);
				cout << union_Translate<unsigned, float>(x) << endl;
				break;
			case CAST:
				cout << "������� 4-�������� ����������������� �����: " << endl;;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(10);
				cout << cast<unsigned, float>(x) << endl;
				break;

			default:
				cout << "�������� ������!" << endl;
				break;
			}
			break;
		}
		case HEX_TO_DOUBLE:
		{
			unsigned long long x;
			switch (GetWay())
			{
			case POINTER:
				cout << "������� 8-��������� ����������������� �����: " << endl;;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(18);
				cout << pntr_Translate<unsigned long long, double>(x) << endl;
				break;
			case MEMCPY:
				cout << "������� 8-��������� ����������������� �����: " << endl;;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(18);
				cout << memcpy_Translate<unsigned long long, double>(x) << endl;
				break;
			case UNION:
				cout << "������� 8-��������� ����������������� �����: " << endl;;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(18);
				cout << union_Translate<unsigned long long, double>(x) << endl;
				break;
			case CAST:
				cout << "������� 8-��������� ����������������� �����: " << endl;
				cin >> hex >> x;
				cout << uppercase << hex << x << " � ������� ����� � ��������� ������� = ";
				cout.precision(18);
				cout << cast<unsigned long long, double>(x) << endl;
				break;
			default:
				cout << "�������� ������!" << endl;
				break;
			}
			cout << endl;
			break;
		case EXIT:
			FLAG = 0;
		}
		}
	} while (FLAG);

}

template <typename FROM, typename TO>

inline TO pntr_Translate(FROM x)
{
	static_assert(sizeof(FROM) == sizeof(TO), "Types must be the equal size\n");
	return *(TO*)&x; // �������������� � ������� ����������
}

template <typename FROM, typename TO>

inline TO memcpy_Translate(FROM x)
{
	static_assert(sizeof(FROM) == sizeof(TO), "Types must be the equal size\n");
	TO r;
	memcpy(&r, &x, sizeof(TO)); // ����������� ������
	return r;
}

template <typename FROM, typename TO>

inline TO union_Translate(FROM x)
{
	static_assert(sizeof(FROM) == sizeof(TO), "Types must be the equal size\n");
	union // ����������� (������, ����������� ���������� ���������� �������� ���� ������� ������)
	{
		FROM f;
		TO t;
	};
	f = x;
	return t;
}

template <typename FROM, typename TO>

inline TO cast(FROM x)
{
	static_assert(sizeof(FROM) == sizeof(TO), "Types must be the equal size\n");
	TO y = *reinterpret_cast<TO*>(&x); // ���������� ����� ��� ��������, ���������������� �������� �����������
	return y;
}
