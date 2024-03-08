#include <iostream>
#include <cstring>
#include <vector>

std::vector<int> SieveOfEratosthenes(int n, int &size)
{
    std::vector<bool>prime = std::vector<bool>(n, true);
    std::vector<int> a;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    size = 0;
    for (int i = 2; i <= n; ++i) {

        if (prime[i]){
            size++;
            a.push_back(i);
        }
    }
    return a;
}

int main() {
    int n, k, c=0;
    std::cin>>n>>k;
    int size;
    std::vector<int> prime= SieveOfEratosthenes(n, size);
    bool flag =false;
    for (int i = 0; i < size; ++i) {
        if (flag or c==k){
            flag =true;
            break;
        }
        for (int j = 0; j < i; ++j) {
            if (c==k){
                flag =true;
                break;
            }
            if ((prime[j]+prime[j+1]+1)==prime[i]){
                c++;
            }
        }
    }
    if (!flag){
        std::cout<<"NO";
    } else{
        std::cout<<"YES";
    }
    return 0;
}