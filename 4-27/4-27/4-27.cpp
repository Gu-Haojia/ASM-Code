#include <iostream>
using namespace std;
int main() {
	char str[100];
	int out;
	cin.get(str,100);
	_asm {
		LEA ESI,str
		XOR ECX,ECX

		START:
		MOV AL,[ESI]
		CMP AL,0
		JZ OUTP

		CMP AL,' '
		JZ PRO
		CMP AL,'0'
		JB PRO
		CMP AL,'9'
		JBE NEXT
		CMP AL,'A'
		JB PRO
		CMP AL,'Z'
		JBE NEXT
		CMP AL,'a'
		JB PRO
		CMP AL,'z'
		JBE NEXT
		JMP PRO

		NEXT:
		INC ESI
		JMP START


		PRO:
		INC ECX
		JMP NEXT

		OUTP:
		MOV out,ECX

	}

	cout << out << endl;



	return 0;
}