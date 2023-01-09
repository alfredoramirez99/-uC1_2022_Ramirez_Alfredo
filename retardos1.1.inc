;AUTOR:ramirez ipanaque alfredo aldair
;FECHA:9 DE ENERO 2023
;MPLAB XIDE V 6.00
;el programa presentado acontinuacion trabajamos con un oscilador de frecuencia de 4Mhz
;plasmando lo aprendido en clase.
PSECT udata_acs
contador1: DS 1 ;RESERVA UN BYTE EN ACCESS RAM
contador2: DS 1 ;RESERVA UN BYTE EN ACCESS RAM
PSECT  CODE
     ;delay 10us
    ;t=6+4k
delay_ms:    ;2tcy-call
    
MOVLW 1 ;1 TCY
MOVWF contador1,0   ;1tcy
    
delay_loop:
NOP       ;K*cty
DECFSZ contador1,1,0   ;(k-1)+3tcy
GOTO delay_loop ;(k-1)*2tcy
RETURN  ;2tcy
    
    ;.........................................................
    ;delay 50us
    ;t=6+4k
Delay_50us:               ; 2Tcy -- Call
    MOVLW   11             ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access
Delay_Loop:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop    ; (k1-1)*2Tcy
    RETURN                ; 2Tcy

;.........................................................
    ;delay 25us
    ;t=6+4k
    
 Delay_25us:               ; 2Tcy -- Call
    MOVLW   5             ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access
Delay_Loop_25us:
    NOP                        ; (k1*Tcy)
    DECFSZ  contador1,1,0      ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_25us    ; (k1-1)*2Tcy
    RETURN                     ; 2Tcy  
;.........................................................
 ;delay 100us
    ;t=6+4k
    
Delay_100us:               ; 2Tcy -- Call
    MOVLW   24             ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access
Delay_Loop_100us:
    NOP                         ; (k1*Tcy)
    DECFSZ  contador1,1,0       ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_100us    ; (k1-1)*2Tcy
    RETURN                      ; 2Tcy
    
;...................................................................................    
;....................................................................................    
 ;delay 200us
    ;t=6+4k
 
    
Delay_200us:               ; 2Tcy -- Call
    MOVLW   49             ; 1Tcy -- k1
    MOVWF   contador1,0    ; 1Tcy, contador1 en access
Delay_Loop_200us:
    NOP                         ; (k1*Tcy)
    DECFSZ  contador1,1,0       ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_200us    ; (k1-1)*2Tcy
    RETURN                      ; 2Tcy  
    
;...................................................................................
;...................................................................................
     ;delay 250us
    ;t=6+4k
   
    
Delay_250us:               ; 2Tcy -- Call
    MOVLW   61             ; 1Tcy -- k1
    MOVWF   contador1,0    ; 1Tcy, contador1 en access
Delay_Loop_250us:
    NOP                         ; (k1*Tcy)
    DECFSZ  contador1,1,0       ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_250us    ; (k1-1)*2Tcy
    RETURN                      ; 2Tcy  
    
;...................................................................................    
;...................................................................................   
      ;delay 500us
    ;t=6+4k
   
    
Delay_5000us:               ; 2Tcy -- Call
    MOVLW   124             ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access
Delay_Loop_5000us:
    NOP                          ; (k1*Tcy)
    DECFSZ  contador1,1,0        ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_5000us    ; (k1-1)*2Tcy
    RETURN                       ; 2Tcy
    
;...................................................................................    
;...................................................................................   
      ;delay 1ms
    ;t=6+4k

    
Delay_1ms:                ; 2Tcy -- Call
    MOVLW   255           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access
Delay_Loop_1ms:
    NOP                       ; (k1*Tcy)
    DECFSZ  contador1,1,0     ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Delay_Loop_1ms    ; (k1-1)*2Tcy
    RETURN                    ; 2Tcy 
    
;...................................................................................    
;...................................................................................   
     ;delay 5ms
    ;t=6+4k


Delay_5ms:                ; 2Tcy -- Call
    MOVLW   5             ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop
    RETURN                ; 2Tcy
    
;...................................................................................    
;...................................................................................   
     ;delay 2ms
    ;t=6+4k


Delay_2ms:                    ; 2Tcy -- Call
    MOVLW   2                 ; 1Tcy -- k2
    MOVWF contador2,0         ; 1Tcy
;T = (6+4k)us                 1Tcy = 1us
Ext_Loop_2ms:                 ; 2Tcy -- Call
    MOVLW   249               ; 1Tcy -- k1
    MOVWF   contador1,0       ; 1Tcy, contador1 en access

Int_Loop_2ms:
    NOP                       ; (k1*Tcy)
    DECFSZ  contador1,1,0     ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop_2ms      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop_2ms
    RETURN                    ; 2Tcy
                                
;....................................................................................
;...................................................................................   
     ;delay 10ms
    ;t=6+4k

Delay_10ms:                  ; 2Tcy -- Call
    MOVLW   10               ; 1Tcy -- k2
    MOVWF contador2,0        ; 1Tcy
;T = (6+4k)us                 1Tcy = 1us
Ext_Loop_10ms:                 ; 2Tcy -- Call
    MOVLW   249               ; 1Tcy -- k1
    MOVWF   contador1,0       ; 1Tcy, contador1 en access

Int_Loop_10ms:
    NOP                        ; (k1*Tcy)
    DECFSZ  contador1,1,0      ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop_10ms      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop_10ms
    RETURN                     ; 2Tcy
    
;...................................................................................    
;...................................................................................   
     ;delay 25ms
    ;t=6+4k


Delay_25ms:                ; 2Tcy -- Call
    MOVLW   25             ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop_25ms:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop_25ms:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop_25ms      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop_25ms
    RETURN                ; 2Tcy
    
;...................................................................................
;...................................................................................   
     ;delay 50ms
    ;t=6+4k

Delay_50ms:                ; 2Tcy -- Call
    MOVLW   50             ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop_50ms:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop_50ms:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop
    RETURN                ; 2Tcy
    
;...................................................................................   
;...................................................................................
     ;delay 100ms
    ;t=6+4k


Delay_100ms:              ; 2Tcy -- Call
    MOVLW   100           ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop_100ms:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop_100ms:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop
    RETURN                ; 2Tcy
    
;...................................................................................   
;...................................................................................   
     ;delay 200ms
    ;t=6+4k


Delay_200ms:                ; 2Tcy -- Call
    MOVLW   200             ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop_200ms:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop_200ms:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop
    RETURN                ; 2Tcy

;...................................................................................
;...................................................................................
     ;delay 250ms
    ;t=6+4k


Delay_250ms:             ; 2Tcy -- Call
    MOVLW 250             ; 1Tcy -- k2
    MOVWF contador2,0     ; 1Tcy
;T = (6+4k)us             1Tcy = 1us
Ext_Loop_250ms:                 ; 2Tcy -- Call
    MOVLW   249           ; 1Tcy -- k1
    MOVWF   contador1,0   ; 1Tcy, contador1 en access

Int_Loop_250ms:
    NOP                   ; (k1*Tcy)
    DECFSZ  contador1,1,0 ; (k1-1)+ 3Tcy, Decrementa el registro y salta si es cero
    GOTO    Int_Loop      ; (k1-1)*2Tcy
    DECFSZ  contador2,1,0
    GOTO    Ext_Loop
    RETURN                ; 2Tcy
    
;...................................................................................    
;...................................................................................


