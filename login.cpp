#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// Kullanıcı bilgilerini yükleme
std::unordered_map<std::string, std::string> loadUsers() {
    std::unordered_map<std::string, std::string> users;
    std::ifstream file("users.txt");
    if (!file) {
        std::cerr << "Kullanıcı dosyası açılamadı!" << std::endl;
        return users;
    }

    std::string username, password;
    while (file >> username >> password) {
        users[username] = password;
    }
    file.close();
    return users;
}

int main() {
    std::unordered_map<std::string, std::string> users = loadUsers();

    if (users.empty()) {
        std::cerr << "Kullanıcı bilgileri bulunamadı!" << std::endl;
        return 1;
    }

    std::string username, password;
    std::cout << "Kullanıcı Adı: ";
    std::cin >> username;
    std::cout << "Şifre: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        std::cout << "Giriş başarılı! Hoş geldiniz, " << username << "!" << std::endl;
    } else {
        std::cout << "Hatalı kullanıcı adı veya şifre!" << std::endl;
    }

    return 0;
}
