.model small
.stack
.data
num1 db 1
num2 db 2
end_message db 10,13,"Program Executed Successfully $"

.code
main proc
	mov ax,@data
	mov ds,ax

	mov al,num1
	mov bl,num2
	add al,bl
	mov dl,al

	mov al,02h
	int 21h

	mov al,09h
	lea dx, end_message
	int 21h

	mov ax,4c00h
	int 21h
main endp
end main
