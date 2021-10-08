#include <iostream>
using namespace std;
int main()
{
	char str[100];

	cin >> str;

	_asm {
		LEA EAX,str
		CALL PROCESS
	}

	cout << str << endl;

	return 0;


	_asm {
	PROCESS:	
		PUSH EBP
		MOV EBP,EAX
		NEXT :
		MOV AL, [EBP]
		CMP AL, 0
		JZ END

		CMP AL, 97
		JB NEXT1
		CMP AL, 123
		JB NEXT2
		JMP NEXT1

		NEXT1:
		INC EBP
		JMP NEXT


		NEXT2:
		SUB AL,32
		MOV [EBP],AL
		JMP NEXT1

		END :    
		POP EBP
		RET
	}

}

