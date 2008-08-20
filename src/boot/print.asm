; ToriX - TORres Interactive eXecution
; Copyright (c) 2008 Devin Torres
; Licensed under the MIT license.

%macro print 1
	mov	si, %1
	call	print_msg
%endmacro
