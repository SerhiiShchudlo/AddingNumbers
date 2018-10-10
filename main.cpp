#include "CAddingNumbers.h"

using namespace std;

int main()
{
	CAddingNumbers obj;

	obj.readNumbers();
	obj.addNumbers();

	std::cout << "Sum = " << obj.getSum() << endl;

	return 0;
}

