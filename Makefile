CC = gcc
SRC = main.c \
src/ack/ack.c \
src/hash_object.c \
src/utils.c \
src/commit.c \
src/tree.c


OUT = ctp

$(OUT):$(SRC)
	$(CC) $(SRC) -o $(OUT) \
	-I$(OPENSSL_PREFIX)/include \
	-L$(OPENSSL_PREFIX)/lib -lssl -lcrypto

run:
	./$(OUT)

clean:
	rm -f $(OUT)
	rm -r .gegit