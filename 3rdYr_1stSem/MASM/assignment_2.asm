.model small
.stack
.data
message1 db "Enter Uppercase : $"
message2 db 10,13,"Enter LowerCase : $"

.code
main proc
	mov ax,@data
	mov ds,ax

	mov ah,09h
	lea dx,message1
	int 21h

	mov ah,01h
	int 21h
	mov bl,al

	mov al,32
	add al,bl
	mov bl,al

	mov ah,09h
	lea dx,message2
	int 21h

	mov ah,02h
	mov dl,bl
	int 21h

	mov ax,4c00h
	int 21h
main endp
end main
