.model small
.stack
.data
first_input db 10,13,"Enter First Number : $"
second_input db 10,13,"Enter Second Number : $"
sum_output db 10,13,"Sum : $"
difference_output db 10,13,"Difference : $"

.code
main proc
	mov ax,@data
	mov ds,ax

	mov ah,09h
	lea dx,first_input
	int 21h			;Display Prompt for First Input
	mov ah,01h
	int 21h			;Input Higher Part
	mov bh,al
	mov ah,01h
	int 21h			;Input Lower Part
	mov bl,al
	
	mov ah,09h
	lea dx,second_input
	int 21h			;Display Prompt for Second Input
	mov ah,01h
	int 21h			;Input Higher Part
	mov ch,al
	mov ah,01h
	int 21h			;Input Lower Part
	mov cl,al

	add al,bl
	mov ah,00h
	aaa
	mov dl,al	
	add ah,bh
	add ah,ch
	mov al,ah
	mov ah,00h
	aaa
	mov 
	

	mov al,02h
	int 21h

	mov al,09h
	lea dx, end_message
	int 21h

	mov ax,4c00h
	int 21h
main endp
end main

