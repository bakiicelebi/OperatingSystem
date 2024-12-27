#				GRUP ÜYELERİ
#		İsim Soyisim 		Numara
#-------------------------------------------
#	    Abdulbaki Çelebi 	B211210009 
#	    Akif Emre Sula 		B211210030
#	    Hümeyra Öztürk 		B211210014
#	    Sena Erden 			B211210041
#	    Mert Can Yeter 		B211210092

CC = gcc
CFLAGS = -Wall -I./include

# Tüm .c dosyalarını derleyip çalıştırılabilir dosyayı oluşturuyoruz
all: shell

# shell.o dosyasını önce oluşturuyoruz
src/shell.o: src/shell.c include/shell.h
	$(CC) $(CFLAGS) -c src/shell.c -o src/shell.o

# execute.c dosyasını derliyoruz
src/execute.o: src/execute.c include/shell.h
	$(CC) $(CFLAGS) -c src/execute.c -o src/execute.o

# redirection.c dosyasını derliyoruz
src/redirection.o: src/redirection.c include/shell.h
	$(CC) $(CFLAGS) -c src/redirection.c -o src/redirection.o

# pipe.c dosyasını derliyoruz
src/pipe.o: src/pipe.c include/shell.h
	$(CC) $(CFLAGS) -c src/pipe.c -o src/pipe.o

# background.c dosyasını derliyoruz
src/background.o: src/background.c include/shell.h
	$(CC) $(CFLAGS) -c src/background.c -o src/background.o

# signal_handler.c dosyasını derliyoruz
src/signal_handler.o: src/signal_handler.c include/shell.h
	$(CC) $(CFLAGS) -c src/signal_handler.c -o src/signal_handler.o

# shell çalıştırılabilirini oluşturuyoruz
shell: src/shell.o src/execute.o src/redirection.o src/pipe.o src/background.o src/signal_handler.o
	$(CC) $(CFLAGS) -o shell src/shell.o src/execute.o src/redirection.o src/pipe.o src/background.o src/signal_handler.o

# Temizleme işlemi
clean:
	rm -f src/*.o shell
