#include"Set.h"
int main()
{

	int  num;

	Set<int> s(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> num;
		s.insert(num);
	}
	s.print();
	system("pause");
	return 0;
}