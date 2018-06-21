#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

struct student
{
	std::string name;
	bool ismale;
	float score;
};
template <typename T>
void swap(const T& temp1,const T& temp2)
{
	T temp=temp1;
	temp1=temp2;
	temp2=temp;
}

int main()
{
	using namespace std;
	const int max = 50;
	student students[max];

	const char* fileName = "score.csv";
	ifstream fin(fileName);
	if(!fin)
	{
		cout<<"Can not open the file."<<endl;
		exit(1);
	}

	string temp;
	int count=0;
	getline(fin,temp,' ');
	getline(fin,temp,' ');
	getline(fin,temp);
	while(getline(fin,students[count].name,' '))
	{
		getline(fin,temp,' ');
		if(temp=="Male,")
			students[count].ismale=true;
		else
			students[count].ismale=false;
		
		getline(fin,temp);
		students[count].score=stof(temp);

		count++;
	}

	/*cout<<"for test"<<endl;
	cout<<count<<endl;	
	for(int i=0;i<count;i++)
	{
		cout<<students[i].name<<" ";
		if(students[i].ismale)
			cout<<"male, ";
		else
			cout<<"female, ";
		cout<<students[i].score<<endl;
	}
	cout<<"for test"<<endl;*/

	float sum=0;
	float mSum=0;
	float fSum=0;
	int m=0;
	int f=0;
	for(int i=0;i<count;i++)
	{
		sum+=students[i].score;
		if(students[i].ismale)
		{
			mSum+=students[i].score;
			m++;
		}
		else
		{
			fSum+=students[i].score;
			f++;
		}
	}
	cout<<"Average: "<<sum/count<<endl;
	cout<<"Male Average: "<<mSum/m<<endl;
	cout<<"Female Average: "<<fSum/f<<endl;

	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count-i-1;j++)
		{
			if(students[j].score>students[j+1].score)
			{
				swap(students[j].name,students[j+1].name);
				swap(students[j].ismale,students[j+1].ismale);
				swap(students[j].score,students[j+1].score);
			}
		}
	}
	cout<<"Sorted: "<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<students[i].name<<" ";
		if(students[i].ismale)
			cout<<"male, ";
		else
			cout<<"female, ";
		cout<<students[i].score<<endl;
	}

	return 0;
}
