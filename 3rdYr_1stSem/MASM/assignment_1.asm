.model small
.stack
.data
message1 db "Bodhisatwa Mandal","$"
message2 db "assignment_1.asm","$"

.code
main proc
	mov ax,@data
	mov ds,ax
	
	mov ah,09h		;code to print dx
	lea dx,message1		;lew=load effective address
	int 21h
	
	mov ah,02h		;code to print dl
	mov dl,10		;new line
	int 21h
	mov dl,13		;carriage return
	int 21h
	
	mov ah,09h
	lea dx,message2
	int 21h
	
	mov ax,4c00h
	int 21h
main endp
end main
