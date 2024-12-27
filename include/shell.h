//				GRUP ÜYELERİ
//		İsim Soyisim 		Numara
//-------------------------------------------
//	    Abdulbaki Çelebi 	B211210009 
//	    Akif Emre Sula 		B211210030
//	    Hümeyra Öztürk 		B211210014
//	    Sena Erden 			B211210041
//	    Mert Can Yeter 		B211210092


#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>     // Standart giriş/çıkış fonksiyonları
#include <stdlib.h>    // Standart kütüphane fonksiyonları
#include <string.h>    // String fonksiyonları
#include <unistd.h>    // POSIX fonksiyonları
#include <sys/types.h> // Sistem türleri
#include <sys/wait.h>  // wait fonksiyonları
#include <fcntl.h>     // Dosya işlemleri
#include <signal.h>    // Sinyal işlemleri

// Constants
#define MAX_COMMAND_LENGTH 1024 // Maksimum komut uzunluğu
#define MAX_ARG_COUNT 128       // Maksimum argüman sayısı
#define MAX_BACKGROUND_JOBS 64  // Maksimum arka planda çalışan iş sayısı

// Function Prototypes
void print_prompt();                        // Prompt yazdırma fonksiyonu
void execute_command(char *command);        // Komutu işleme fonksiyonu
void execute_single_command(char *command); // Tek bir komutu işleme fonksiyonu
void handle_redirection(char *command);     // Yönlendirme işlemlerini yapma fonksiyonu
void execute_pipe(char *command);           // Pipe işlemlerini yapma fonksiyonu
void execute_background(char *command);     // Arka planda işlem yapma fonksiyonu
void wait_for_background_processes();       // Arka planda çalışan işlemleri bekleyen fonksiyon
void handle_signal(int sig);                // Sinyal işleme fonksiyonu

#endif
