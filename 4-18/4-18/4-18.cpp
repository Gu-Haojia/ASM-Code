#include <iostream>
using namespace std;
int main() {
	char st1[100];
	char st2[100];
	char out[200];

	cin >> st1;
	cin >> st2;

	_asm {
		LEA ESI,st1
		LEA EDI,out
		COPY1:
		MOV AL,[ESI]
		CMP AL,0
		JZ NEXT
		MOV [EDI],AL
		INC EDI
		INC ESI
		JMP COPY1

		NEXT:
		LEA ESI,st2
		COPY2:
		MOV AL, [ESI]
		CMP AL, 0
		JZ END
		MOV [EDI], AL
		INC EDI
		INC ESI
		JMP COPY2

		END:
		MOV [EDI],0

	}

	cout << out << endl;



	return 0;
}