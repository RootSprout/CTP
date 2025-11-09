CC = gcc
SRC = datalink/sender.c \
datalink/receiver.c \
src/ack.c \
src/comm.c \
src/crc.c \
src/termios.c 


OUT = sender

$(OUT):$(SRC)
	$(CC) $(SRC) -o $(OUT) 

run:
	./$(OUT)

clean:
	rm -f $(OUT)