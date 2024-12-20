# 1. C++ geliştirme ortamı içeren bir temel imaj seçiyoruz
FROM gcc:latest

# 2. Çalışma dizinini ayarla
WORKDIR /app

# 3. Kod dosyalarını konteynere kopyala
COPY login.cpp .
COPY users.txt .

# 4. C++ kodunu derle
RUN g++ -o login login.cpp

# 5. Çalıştırılabilir dosyayı başlat
CMD ["./login"]
