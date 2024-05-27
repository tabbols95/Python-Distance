#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Функция для вычисления расстояния Дамерау-Левенштейна
int damerau_levenshtein(const std::string &s1, const std::string &s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    
    // Матрица для хранения расстояний
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));
    
    // Инициализация первой строки и первого столбца
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        dp[0][j] = j;
    }
    
    // Заполнение матрицы
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            
            dp[i][j] = std::min({
                dp[i - 1][j] + 1,        // Удаление
                dp[i][j - 1] + 1,        // Вставка
                dp[i - 1][j - 1] + cost  // Замена
            });
            
            // Проверка транспозиции
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                dp[i][j] = std::min(dp[i][j], dp[i - 2][j - 2] + 1); // Транспозиция
            }
        }
    }
    
    // Возвращаем расстояние Дамерау-Левенштейна
    return dp[len1][len2];
}

int main() {
    std::string s1 = "Александр";
    std::string s2 = "Александр";
    
    std::cout << "Расстояние Дамерау-Левенштейна между \"" << s1 << "\" и \"" << s2 << "\" равно " 
              << damerau_levenshtein_distance(s1, s2) << std::endl;

    return 0;
}
