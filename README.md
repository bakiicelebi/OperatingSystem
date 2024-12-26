# Shell Projesi

Bu proje, basit bir kabuk (shell) uygulamasıdır. Proje, grup çalışması olarak gerçekleştirilmiştir ve toplamda 5 kişi katkıda bulunmuştur. İsimler aşağıdaki gibi belirtilmiştir:

1. Abdulbaki Çelebi - _*B211210009*_
2. Akif Emre Sula - _*B211210030*_
3. Hümeyra Öztürk - _*B211210014*_
4. Sena Erden - _*B211210041*_
5. Mert Can Yeter - _*B211210092*_

## Dosya Yapısı

Proje dizini şu şekilde organize edilmiştir:

```
project-root
├── include
│   └── shell.h
├── src
│   ├── background.c
│   ├── execute.c
│   ├── pipe.c
│   ├── redirection.c
│   ├── shell.c
│   └── signal_handler.c
└── makefile
```

### Dosyaların Açıklamaları

- **include/shell.h**: Projenin genel başlık dosyasıdır. Fonksiyon bildirimleri ve gerekli makrolar burada tanımlanmıştır.
- **src/background.c**: Arka planda çalışan işlemleri yönetir.
- **src/execute.c**: Komutların yürütülmesini sağlar.
- **src/pipe.c**: Boru (pipe) mekanizmasını yönetir.
- **src/redirection.c**: Girdi ve çıktının yönlendirilmesi ile ilgilenir.
- **src/shell.c**: Ana kabuk programını içerir.
- **src/signal_handler.c**: Sinyal işleme ile ilgili kodları içerir.
- **makefile**: Projeyi derlemek ve temizlemek için gerekli make komutlarını içerir.
- **Readme.md**: Proje ile ilgili genel bilgileri içeren bu dosyadır.

## Derleme ve Çalıştırma

Projeyi çalıştırmak için aşağıdaki adımları takip edin:

1. **Derleme**:
   ```bash
   make
   ```
   Bu komut, `src` dizinindeki tüm kaynak dosyaları derleyerek `shell` adlı bir çalıştırılabilir dosya oluşturur.

2. **Çalıştırma**:
   ```bash
   ./shell
   ```
   Bu komut, kabuk programını başlatır.

3. **Temizleme**:
   ```bash
   make clean
   ```
   Bu komut, derleme sırasında oluşturulan tüm geçici ve çalıştırılabilir dosyaları siler.

## Özellikler

1. **Prompt**:
   Her komutun tamamlanmasından sonra veya arka plan komutunun hemen ardından `>` karakteri yazdırılır. Örneğin:
   ```
   > ls -l
   ```

2. **Quit Komutu**:
   `quit` komutu ile kabuk sonlandırılabilir. Ancak, arka planda çalışan işlemler varsa, bu işlemlerin tamamlanması beklenir.
   ```
   > quit
   ```

3. **Tekli Komutlar**:
   Tekli komutlar bağımsız veya bağımsız değişkenlerle çalıştırılabilir:
   ```
   > ls -l
   ```

4. **Giriş Yönlendirme**:
   Komut girişlerini bir dosyadan okur:
   ```
   > cat < file.txt
   ```
   Eğer giriş dosyası bulunamazsa:
   ```
   > cat < nofile.txt
   Giriş dosyası bulunamadı.
   ```

5. **Çıkış Yönlendirme**:
   Komut çıkışlarını bir dosyaya yönlendirebilir:
   ```
   > cat file1 > file2
   ```

6. **Arkaplan Çalıştırma**:
   `&` sembolü ile bir komut arka planda çalıştırılabilir. Örneğin:
   ```
   > sleep 5 &
   > [24617] retval: 0
   ```

7. **Pipelining (Boru)**:
   Komutların çıktısını bir sonraki komutun girişine yönlendirebilir:
   ```
   > find /etc | grep ssh | grep conf
   ```

## Test Örnekleri

- **Tekli Komut**:
  ```bash
  > ls -l
  ```
- **Giriş Yönlendirme**:
  ```bash
  > cat < file.txt
  ```
- **Çıkış Yönlendirme**:
  ```bash
  > echo "Hello, World!" > output.txt
  ```
- **Arkaplan Çalıştırma**:
  ```bash
  > sleep 5 &
  ```
- **Pipe**:
  ```bash
  > ls | grep .c | wc -l
  ```


## Notlar

- `make` komutunun doğru çalışabilmesi için `make` aracının sisteminizde kurulu olduğundan emin olun.
- Test sırasında giriş ve çıkış yönlendirmeleri için uygun dosyalar oluşturulmalıdır.
- Arka plan işlemlerini test etmek için `&` sembolü ile çalışan komutları kullanabilirsiniz.

