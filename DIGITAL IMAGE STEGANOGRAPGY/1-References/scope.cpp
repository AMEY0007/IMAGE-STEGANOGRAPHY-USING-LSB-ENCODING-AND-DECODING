#include <iostream>
using namespace std;
class employee
{
    private:
	int x;
    public:
	void display()
	{
	    cout << "enter x:";
	    cin >> x;
	    cout << "x=" << x << endl;
	}
};
int main()
{
    employee e;
    e.display();
    return 0;
}

