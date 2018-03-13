.code

	; 1.Param (RCX)	=	localClientNum
	; 2.Param (RDX)	=	proxyAddr
	; 3.Param (R8)	=	cgtAddr
	GetCGTProxy proc
		PUSH RBX
		PUSH RCX
		PUSH RDX
		PUSH RBP

		SUB RSP, 20h
		MOV RBP, ReturnHere	;Called by the proxyAddr (JMP RBP)
		PUSH RDX
		JMP R8
	ReturnHere:
		ADD RSP, 20h
		POP RBP
		POP RDX
		POP RCX
		POP RBX	

		RET
	GetCGTProxy endp

	; 1.Param (RCX)	=	localClientNum
	; 2.Param (RDX)	=	id
	; 3.Param (R8)	=	proxyaddr
	; 4.Param (R9)  =	entityAddr
	GetEntityProxy proc
		PUSH RBX
		PUSH RCX
		PUSH RDX
		PUSH RBP

		SUB RSP, 20h
		MOV RBP, ReturnHere ;Called by the proxyAddr (JMP RBP)
		PUSH R8
		JMP R9
	ReturnHere:
		ADD RSP, 20h
		POP RBP
		POP RDX
		POP RCX
		POP RBX

		RET
	GetEntityProxy endp
end