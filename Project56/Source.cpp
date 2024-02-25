#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string name;
    int weight;
    int value;
};

int knapsack(int W, std::vector<Item>& items) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else {
                dp[i][w] = std::max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::vector<Item> items = {
        {"Pen", 2, 5},
        {"Key", 3, 8},
        {"Laptop", 4, 10}
    };

    int maxWeight = 8;

    std::cout << "Items:\n";
    for (const auto& item : items) {
        std::cout << item.name << " (weight: " << item.weight << ", ценность: " << item.value << ")\n";
    }

    int maxValue = knapsack(maxWeight, items);
    std::cout << "MaxValue: " << maxValue << "\n";

    return 0;
}
