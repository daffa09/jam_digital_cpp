#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

struct jam
{
	int hh, mm, ss, ms;
};

class Jam_Digital
{

public:
	Jam_Digital()
	{
		cout << "\t\t----->>>   PROGRAM JAM DIGITAL DAFFA FATHAN   <<<-----" << endl
				 << endl;
	}
	void input_auto();
	void running();

private:
	jam hour;
	int z;
};

void Jam_Digital::input_auto()
{
	struct tm *Sys_T;
	time_t Tval;

	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	hour.hh = Sys_T->tm_hour;
	hour.mm = Sys_T->tm_min;
	hour.ss = Sys_T->tm_sec;
}

void Jam_Digital::running()
{
	while (hour.hh <= 24)
	{
		while (hour.mm <= 59)
		{
			while (hour.ss <= 59)
			{
				while (hour.ms < 10)
				{
					hour.ms++;
					Sleep(71);
					system("cls");
					Jam_Digital();
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t %02d %02d %02d %02d\n", hour.hh, hour.mm, hour.ss, hour.ms);
				}
				hour.ms = 0;
				hour.ss++;
			}
			hour.ss = 0;
			hour.mm++;
		}
		hour.mm = 0;
		hour.hh++;
		if (hour.hh == 24)
			hour.hh = 0;
	}
}

int main()
{

	Jam_Digital run;

	run.input_auto();
	run.running();

	system("pause");
	cin.get();
	return 0;
}