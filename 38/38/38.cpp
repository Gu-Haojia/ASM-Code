#include <iostream>
using namespace std;
int main()
{
	char str[100];
	int numcount;
	int wordcount;
	cin >> str;
	_asm {
		LEA EBX, str
		XOR ECX, ECX
		XOR EDX, EDX
		NEXT:
		MOV AL, [EBX]
		CMP AL,0
		JZ END
		CMP AL,48
		JB NEXT1
		CMP AL,58
		JB NUM
		CMP AL,65
		JB NEXT1
		CMP AL,91
		JB WORDP
		CMP AL,97
		JB NEXT1
		CMP AL,123
		JB WORDP
		JMP NEXT1

		NUM:
		INC ECX
		JMP NEXT1

		WORDP:
		INC EDX
		JMP NEXT1

		NEXT1:
		INC EBX
		JMP NEXT
		
		END:
		MOV numcount,ECX
		MOV wordcount,EDX
	}
	cout << numcount << endl;
	cout << wordcount << endl;

	return 0;
}

