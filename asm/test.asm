.386
DATA SEGMENT USE16
NUM1 DD 20H
NUM2 DD 22H
SUM DD ?
DATA ENDS
CODE SEGMENT USE16
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,NUM1
    ADD AX,NUM2
    MOV SUM,AX
    OUT SUM
    MOV AH,4CH
    INT 21H;back to dos
CODE ENDS
END START