#include <iostream>
using namespace std;
int main()
{
	int x;
	int count;
	cin >> x;
	_asm {
		LEA EBX,x
		XOR EDX,EDX
		MOV EAX,[EBX]
		MOV ECX,32
		NEXT:
		TEST EAX,1
		JNZ NEXT1
		INC EDX
		NEXT1:
		ROR EAX,1
		LOOP NEXT
		MOV count,EDX
	}
	cout << count << endl;

	return 0;
}

