DATAS SEGMENT
    ;�˴��������ݶδ���
    A1 DB 2
    B1 DB 2
    C1 DB 3
    D1 DB 4
    E1 DB 1
    F1 DB 4
    X1 DB ?  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    MOV AL,A1
    MUL BL
    ADD AL,C1
    SUB AL,D1
    MOV BL,E1
    ADD BL,F1
    DIV BL
    MOV X1,AL
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
