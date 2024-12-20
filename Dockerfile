FROM gcc:latest

WORKDIR /app

COPY login.cpp .
COPY users.txt .

RUN g++ -o login login.cpp

CMD ["./login"]
