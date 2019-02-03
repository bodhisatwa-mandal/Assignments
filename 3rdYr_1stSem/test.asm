.model small
.stack
.data
message db "Hello World","$"

.code
main proc
	mov ax,@data
	mov ds,ax
	
	mov ah,09h
	lea dx,message
	int 21h
	
	mov ax,4c00h
	int 21h
main endp
end main