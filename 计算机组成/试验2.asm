DATAS SEGMENT
	AS DW 10H,20H,30H
	MAX DW 0
    MIN DW 0;
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV CX,0
    MOV SI,OFFSET AS
    MOV AX,[SI]
    ADD SI,2
    LI:MOV BX,[SI]
    MOV [SI],AX
    MOV AX,BX
    ADD SI,2
    ADD CX,1
    CMP CX,2
    JNZ LI
    SUB SI,6
    MOV [SI],AX
    MOV AX,[SI]
    MOV MIN,AX
    MOV MAX,AX
    ADD SI,2
    MOV BX,[SI]
    CMP BX,AX
    JL L1
    MOV MAX,BX
    ADD SI,2
    MOV DX,[SI]
    CMP BX,DX
    JG L4
    MOV MAX,DX
    L1:ADD SI,2
    	MOV BX,[SI]
    	CMP BX,AX
    	JL L2
    	MOV MAX,BX
    L4:CMP AX,DX
    	JG L5
    L5:MOV MIN,DX
    L2:mov bx,[si]
    	SUB SI,2
    	MOV AX,[SI]
    	CMP BX,AX
    	JG L3
    	MOV MIN,BX
    L3:MOV MIN,AX
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
