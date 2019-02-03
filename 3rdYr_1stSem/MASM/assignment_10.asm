.model small
.stack
.code

main proc
	mov bh,01h
	mov bl,64

	l1:mov al,bl
	   add al,bh		;add 1
	   mov bl,al		;store in bl

	   mov ah,02h
	   mov dl,bl		;print bl
	   int 21h
           mov dl,32		;space
           int 21h

	   cmp bl,90		;check if z has been reached
	   jnz l1

	mov ax,4c00h
	int 21h
main endp
end main
