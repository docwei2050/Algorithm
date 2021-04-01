#include <iostream>
#include <vector>

//斐波那契函数来看动态规划三要素：
//重叠子问题  最优子结构  状态转移方程
using namespace std;

//最垃圾的递归
long fib(long n) {
    if (n == 0) return 0;
    if (n == 1 | n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}


//含有memo备忘录的数组保存，防止重复计算
long fibWithmemo(long n) {
    if (n == 0) return 0;
    vector<long> memo(n + 1, 0);
    long helper(long n, vector<long> &memo);
    return helper(n, memo);
}

long helper(long n, vector<long> &memo) {
    if (n == 0) return 0;
    if (n == 1 | n == 2) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    return memo[n];
}

long helperDpTable(long n) {
    if (n == 0) return 0;
    if (n == 1 | n == 2) {
        return 1;
    }
    vector<long> dp(n + 0, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}


//其实斐波那契不需要保存那么多值，只需要保存前后两个值即可
long fibBest(long n) {
    if (n == 0) return 0;
    if (n == 1 | n == 2) {
        return 1;
    }
    long pre = 1;
    long next = 1;
    long sum = 0;
    for (long i = 3; i <= n; i++) {
        sum = pre + next;
        pre = next;
        next = sum;
    }
    return sum;
}


int main() {
//    cout << fib(20) << endl;
//    cout << fibWithmemo(100) << endl;
    cout << helperDpTable(100) << endl;
    cout << fibBest(100) << endl;
    return 0;
}
