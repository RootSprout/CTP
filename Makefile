CC = gcc
SRC_COMMON = src/src/ack.c \
src/src/comm.c \
src/src/crc.c \
src/src/termios.c 


SRC_SENDER = src/datalink/dsender.c main_dsender.c
SRC_RECEIVER = src/datalink/dreceiver.c main_dreceiver.c


SENDER_OUT = sender
RECEIVER_OUT = receiver

all: $(SENDER_OUT) $(RECEIVER_OUT)

$(SENDER_OUT):$(SRC_SENDER) $(SRC_COMMON)
	$(CC) $(SRC_SENDER) $(SRC_COMMON) -o $(SENDER_OUT) 

$(RECEIVER_OUT):$(SRC_RECEIVER) $(SRC_COMMON)
	$(CC) $(SRC_RECEIVER) $(SRC_COMMON) -o $(RECEIVER_OUT) 


run-sender:
	./$(SENDER_OUT)

run-receiver:
	./$(RECEIVER_OUT)

clean:
	rm -f $(RECEIVER_OUT) $(SENDER_OUT)