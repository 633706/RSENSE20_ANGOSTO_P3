# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "main.c" "UART.c" "GPIO.c" "I2C.c" "MPU9250.c")
#set(COMPONENT_SRCS "main.c")
set(COMPONENT_ADD_INCLUDEDIRS "include")

register_component()
