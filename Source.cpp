#include <iostream>
#include <string>
#include <time.h>
#include <vector>;
#include <algorithm>
using namespace std;

class Date1 {
	int year;
	int month;
public:
	Date1()
	{
		this->month = rand() % 12 + 1;
		this->year = rand() % 119 + 1900;
	}
	Date1(int year,int month)
	{
		setYear(year);
		setMonth(month);
	}
	void setYear(int year)
	{
		if (year < 1900)
		{
			this->year = 1900;
		}
		if (year > 2019)
		{
			this->year = 2019;
		}

		this->year = year;
	}
	void setMonth(int month)
	{
		if (month < 0)
		{
			this->month = 1;
		}

		if (month > 12)
		{
			this->month = 12;
		}

		this->month = month;
	}

	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}

	void showDate1()
	{
		cout << "month: " << month << " year: " << year << endl;
	}
	virtual void show()
	{
		cout << "month: " << month << " year: " << year << endl;
	}
};

class Date2{
	int year;
	int month;
	int day;
public:
	Date2()
	{
		this->day = rand() % 31 + 1;
		this->month = rand() % 12 + 1;
		this->year = rand() % 119 + 1900;
	}
	Date2(int day, int month,int year)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}

	void setYear(int year)
	{
		if (year < 1900)
		{
			this->year = 1900;
		}
		if (year > 2019)
		{
			this->year = 2019;
		}
		this->year = year;
	}
	void setMonth(int month)
	{
		if (month < 0)
		{
			this->month = 1;
		}

		if (month > 12)
		{
			this->month = 12;
		}
		this->month = month;
	}
	void setDay(int day)
	{
		if (day < 0)
		{
			this->day = 1;
		}
		if (day > 31)
		{
			this->day = 31;
		}
		this->day = day;
	}

	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}

	void showDate2()
	{
		cout << "day: " << day << " month: " << month << " year: " << year << endl;
	}
	virtual void show() 
	{
		cout << "day: " << day << " month: " << month << " year: " << year << endl;
	}
};

class Studio: public Date1{
	string StudioName;
	Date1 creationDate;
public:
	Studio()
	{
		this->creationDate.setMonth(rand() % 12 + 1);
		this->creationDate.setYear(rand() % 119 + 1900);
		const char randomize[] = "1234567890qwertyuiopasdfghjklzxcvbnm";
		string temp_name;
		for (int i = 0; i < 10; i++)
		{
			temp_name += randomize[rand() % (sizeof(randomize) - 1)];
		}
		StudioName = temp_name;
	}
	Studio(string Studioname, int year, int month):Date1(year,month)
	{
		this->StudioName = Studioname;
	}

	void setName(string StudioName)
	{
		this->StudioName = StudioName;
	}
	string getName()
	{
		return StudioName;
	}
	
	void showStudioInfo()
	{
		cout << "Name of studio is: " << StudioName << endl << "Date of establishing is: "
			<< "month: " << creationDate.getMonth() << " year: " << creationDate.getYear() << endl;
	}

	void show() override
	{
		cout << "Name of studio is: " << StudioName << endl << "Date of establishing is: "
			<< "month: " << creationDate.getMonth() << " year: " << creationDate.getYear() << endl;
	}
};

class CDdisc :public Studio, public Date2 {
	string FilmName;
	float FilmLength;
	Date2 releaseDate;
public:
	static float averageFilmLength;
	
	CDdisc():Studio()
	{
		this->releaseDate.setDay(rand() % 31 + 1);
		this->releaseDate.setMonth(rand() % 12 + 1);
		this->releaseDate.setYear(rand() % 119 + 1900);
		const char randomize[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM[];',./\"";
		string temp_name;
		for (int i = 0; i < 10; i++)
		{
			temp_name += randomize[rand() % (sizeof(randomize) - 1)];
		}
		FilmName = temp_name;
		FilmLength = (rand() % 1810 )/10.;
		averageFilmLength += FilmLength;
	}
	CDdisc(string FilmName, float FilmLength,string StudioName,int day,int year,int month):
		Studio(StudioName, year, month),Date2(day,month,year)
	{
		releaseDate.setDay(day);
		releaseDate.setMonth(month);
		releaseDate.setYear(year);
		this->FilmName = FilmName;
		this->FilmLength = FilmLength;
		averageFilmLength += FilmLength;
	}

	void setFilmName(float FilmName)
	{
		this->FilmName = FilmName;
		averageFilmLength += FilmLength;
	}
	void setFilmLength(float Filmlength)
	{
		this->FilmLength = Filmlength;
	}

	string getFilmName()
	{
		return FilmName;
	}
	float getFilmLength()
	{
		return FilmLength;
	}
	float getAverageFilmLength()
	{
		return averageFilmLength;
	}

	void showCDdiscInfo()
	{
		cout << "Name of film is: " << FilmName << endl << "Length of film is: " << FilmLength << " minutes" << endl;
		this->showStudioInfo();
		cout << "Release date of film is: day: " << releaseDate.getDay() << " month: " << releaseDate.getMonth() << " year: " << releaseDate.getYear() << endl;
	}

	void show() override
	{
		cout << "Name of film is: " << FilmName << endl << "Length of film is: " << FilmLength << " minutes" << endl;
		this->showStudioInfo();
		cout << "Release date of film is: day: " << releaseDate.getDay() << " month: " << releaseDate.getMonth() << " year: " << releaseDate.getYear() << endl;

	}
};
float CDdisc::averageFilmLength = 0.0;

class Abonent:public Date2 {
	string name;
	char* otherName;
	string surname; 
	Date2 joinDate;
	int donate;
public:
	Abonent()
	{
		this->joinDate.setDay(rand() % 31 + 1);
		this->joinDate.setMonth(rand() % 12 + 1);
		this->joinDate.setYear(rand() % 119 + 1900);
		this->setDonate(rand() % 20000);
		const char randomize[] = "qwertyuiopasdfghjklzxcvbnm";
		string temp_name,temp_surname;

		for (int i = 0; i < 10; i++)
		{
			temp_name += randomize[rand() % (sizeof(randomize) - 1)];
			temp_surname += randomize[rand() % (sizeof(randomize) - 1)];
		}
		
		name = temp_name;
		surname = temp_surname;

		otherName = new char[name.size() + 1];
		copy(name.begin(), name.end(), otherName);
		otherName[name.size()] = '\0';
	}
	Abonent(string name, string surname,int day,int month,int year,int donate):Date2(day,month,year)
	{
		this->joinDate.setDay(day);
		this->joinDate.setMonth(month);
		this->joinDate.setYear(year);
		this->name = name;
		this->surname = surname;
		this->donate = donate;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setDonate(int donate)
	{
		this->donate = donate;
	}
	string getAbonName()
	{
		return name;
	}
	string getAbonSurame()
	{
		return surname;
	}
	char* getOtherName_ch()
	{
		return otherName;
	}
	int GetDonate()
	{
		return donate;
	}

	void showAbonentInfo()
	{
		cout << "Abonent's name is: " << name <<" Abonent's surname is: " << surname << endl;
		cout << "Abonent's char name is: " << otherName << endl;
		cout << "Date of abonent's registration is: day: " << joinDate.getDay() << " month: " << joinDate.getMonth() << " year: " << joinDate.getYear() << endl;
	}
	
	void show() override
	{
		cout << "Abonent's name is: " << name << " Abonent's surname is: " << surname << endl;
		cout << "Abonent's char name is: " << otherName << endl;
		cout << "Date of abonent's registration is: day: " << joinDate.getDay() << " month: " << joinDate.getMonth() << " year: " << joinDate.getYear() << endl;

	}
};

class operation :public CDdisc,public Abonent,public Date2 {
	bool type;
	Date2 operationDate;
public:
	operation():CDdisc(),Abonent()
	{
		this->operationDate.setDay(rand() % 31 + 1);
		this->operationDate.setMonth(rand() % 12 + 1);
		this->operationDate.setYear(rand() % 119 + 1900);
		type = rand() % 2;
	}
	operation(bool type, int day, int month, int year,int donate,string name,string surname, string FilmName, float FilmLength, string StudioName) :Date2(day, month, year)
		,CDdisc(FilmName, FilmLength,StudioName,day,year,month),Abonent(name,surname,day,month,year,donate)
	{
		operationDate.setDay(day);
		operationDate.setMonth(month);
		operationDate.setYear(year);
		this->type = type;
	}

	void setType(int type)
	{
		this->type = type;
	}
	string getType()
	{
		if (type)
			return "Disc borrow";
		else return "Disc return";
	}

	void showType()
	{
		if (type)
			cout << "Disc borrow" << endl;
		else cout << "Disc return" << endl;
	}
	void showinfo()
	{
		this->showCDdiscInfo();
		cout << endl;
		this->showAbonentInfo();
		cout << endl;
		this->showType();
		cout << "Date of operation is: day: " << operationDate.getDay() << " month: " << operationDate.getMonth() << " year: " << operationDate.getYear() << endl;
	}

	void show() override
	{
		this->showCDdiscInfo();
		cout << endl;
		this->showAbonentInfo();
		cout << endl;
		this->showType();
		cout << "Date of operation is: day: " << operationDate.getDay() << " month: " << operationDate.getMonth() << " year: " << operationDate.getYear() << endl;

	}
};

bool comp_int(operation t1, operation t2)
{
	return t1.GetDonate() > t2.GetDonate();
}
bool comp_str(operation t1, operation t2)
{
	if (t1.getName().compare(t2.getName()) < 0)
	{
		return true;
	}

	if (t1.getName().compare(t2.getName()) > 0)
	{
		return false;
	}
}

template<typename T>
void func(T &averageFilmLength, int size)
{
	averageFilmLength /= size;
}

class OperationList :public Date2 {
	operation *list;
	vector <operation> veclist;
	int size;
	Date2 operationListDate;
	//vector <operation> vec;
public:
	OperationList()
	{
		this->operationListDate.setDay(rand() % 31 + 1);
		this->operationListDate.setMonth(rand() % 12 + 1);
		this->operationListDate.setYear(rand() % 119 + 1900);
		size = rand() % 100;
		list = new operation[size];
	}
	OperationList(int size, int day, int month, int year) :Date2(day, month, year)
	{
		this->size = size;
		operationListDate.setDay(day);
		operationListDate.setMonth(month);
		operationListDate.setYear(year);
		list = new operation[size];
	}

	~OperationList()
	{
		delete[] list;
	}

	void SetSize(int size)
	{
		if (list != nullptr)
		{
			delete[] list;
			operation* temp_list = new operation[size];

			this->size = size;

			list = temp_list;
		}

		else
		{
			this->size = size;
		}
	}
	int GetSize()
	{
		return size;
	}
	void showOperationsArray()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "---------------------" << endl;
			list[i].showinfo();
			cout << "Date of list creation: day: " << operationListDate.getDay() << " month: " << operationListDate.getMonth() << " year: " << operationListDate.getYear() << endl;
			cout << "---------------------" << endl;
		}
	}

	void countAverageFilmLength(int size)
	{
		func(CDdisc::averageFilmLength, size);
	}
	operation& operator[](int value)
	{
		if (value < 0 || value >= size)
		{
			cout << "Error. Invalid index";
			value = 0;
		}
		return list[value];
	}

	void Sortchar()
	{
		unsigned int charStart_time = clock();
		operation* temp = new operation();
		for (int i = 0; i < this->GetSize() - 1; i++)
		{
			for (int j = i + 1; j < this->GetSize(); j++)
			{
				if (strcmp(this->list[i].getOtherName_ch(), this->list[j].getOtherName_ch()) > 0)
				{
					*temp = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = *temp;
				}
			}
		}
		unsigned int charEnd_time = clock();
		unsigned int charSearch_time = charEnd_time - charStart_time;
		for (int i = 0; i < 30; i++)
		{
			cout << "# " << i + 1 << " " << list[i].getOtherName_ch() << endl;
		}
		cout << "the time of char sorting is : " << charSearch_time << " millisec" << endl;
	}
	void Sortstr()
	{
		unsigned int stringStart_time = clock();
		operation* temp = new operation();
		for (int i = 0; i < this->GetSize() - 1; i++)
		{
			for (int j = i + 1; j < this->GetSize(); j++)
			{
				if (this->list[i].getAbonName().compare(this->list[j].getAbonName()) > 0)
				{
					*temp = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = *temp;
				}
			}
		}
		unsigned int stringEnd_time = clock();
		unsigned int stringSearch_time = stringEnd_time - stringStart_time;
		for (int i = 0; i < 30; i++)
		{
			cout << "#" << i + 1 << " " << list[i].getAbonName() << endl;
		}
		cout << "the time of string sorting is : " << stringSearch_time <<" millisec"<< endl;
	}

	void show() override
	{
		for (int i = 0; i < size; i++)
		{
			cout << "---------------------" << endl;
			list[i].showinfo();
			cout << "Date of list creation: day: " << operationListDate.getDay() << " month: " << operationListDate.getMonth() << " year: " << operationListDate.getYear() << endl;
			cout << "---------------------" << endl;
		}
	}

	void sort_int()
	{
		int temp;

		vector <operation> a(size);
		copy(veclist.begin(), veclist.end(), a.begin());

		unsigned int intStart_time = clock();

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (a[j].GetDonate() < a[j + 1].GetDonate())
				{
					temp = a[j].GetDonate();
					a[j].setDonate(a[j + 1].GetDonate());
					a[j + 1].setDonate(temp);
				}
			}
		}

		unsigned int intEnd_time = clock();
		unsigned int intSearch_time = intEnd_time - intStart_time;

		cout << "\n\n Sorted int\n";
		for (int i = 0; i < 30; i++)
		{
			cout << "#" << i + 1 << "  " << a[i].GetDonate() << endl;
		}

		cout << "the time of int bubble sorting is : " << intSearch_time << " millisec" << endl;
	}

	void sort_string()
	{
		unsigned int stringStart_time = clock();
		vector <operation> temp(1);
		for (int i = 0; i < this->GetSize() - 1; i++)
		{
			for (int j = i + 1; j < this->GetSize(); j++)
			{
				if (this->list[i].getAbonName().compare(this->list[j].getAbonName()) > 0)
				{
					temp[0] = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = temp[0];
				}
			}
		}
		unsigned int stringEnd_time = clock();
		unsigned int stringSearch_time = stringEnd_time - stringStart_time;
		for (int i = 0; i < 30; i++)
		{
			cout << "#" << i + 1 << " " << list[i].getAbonName() << endl;
		}
		cout << "the time of string bubble sorting is : " << stringSearch_time << " millisec" << endl;
	}

	void comparing_int()
	{
		vector <operation> a(size);
		copy(veclist.begin(), veclist.end(), a.begin());
		this->sort_int();

		unsigned int intStart_time = clock();

		sort(a.begin(), a.end(), comp_int);

		unsigned int intEnd_time = clock();
		unsigned int intSearch_time = intEnd_time - intStart_time;

		cout << "\n\n";

		for (int i = 0; i < 30; i++)
		{
			cout << "#" << i + 1 << "  " << a[i].GetDonate() << endl;
		}
		cout << "the time of int sorting is : " << intSearch_time << " millisec" << endl;

	}
	void comparing_string()
	{
		vector <operation> a(size);
		copy(veclist.begin(), veclist.end(), a.begin());

		sort_string();

		unsigned int strStart_time = clock();
		sort(a.begin(), a.end(), comp_str);

		unsigned int strEnd_time = clock();
		unsigned int strSearch_time = strEnd_time - strStart_time;

		cout << "\n\n Sorted string\n";

		for (int i = 0; i < 30; i++)
		{
			cout << "#" << i + 1 << "  " << a[i].getAbonName() << endl;
		}

		cout << "the time of string sorting is : " << strSearch_time << " millisec" << endl;
	}
};

template<typename TT>
class TEMP {
private:
	TT Temp;
public:
	TEMP() : Temp()
	{

	}

	TT getTemp()
	{
		return Temp;
	}

	void ShowTemp()
	{
		Temp.show();
	}
};

int main() {

	OperationList a;
	a.SetSize(1000);
	cout << endl << endl;
	a.comparing_string();
	cout << endl << endl;
	a.comparing_int();	

	system("pause");
	return 0;
}