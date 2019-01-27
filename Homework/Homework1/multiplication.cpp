#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(long n, long m)
{
    long product = 0;
    long result = 0;

    vector<long> results;

    while (m != 0)
    {
        long tmp = n;
        long carry = 0;
        while (tmp != 0)
        {
            long tmp1 = tmp % 10000;
            long tmp2 = m % 10000;
            product = tmp1 * tmp2 + carry;
            carry = product / 10000 % 10000;
            result = product % 10000;
            results.push_back(result);
            tmp /= 10000;
        }
        results.push_back(carry);
        results.push_back(0);
        m /= 10000;
    }

    vector<int> nextRow;

    for (int i = 0; i < results.size(); i++)
    {
        if (results[i] == 0)
        {
            for (int j = i; j < results.size() - 1; j++)
            {
                nextRow.push_back(results[j]);
            }
        }
    }

    vector<int> finalResult;
    vector<int> carries;

    for (int i = nextRow.size() - 1; i >= 0; i--)
    {
        int sum = (results[i] + nextRow[i]) % 10000;
        int carry = (results[i] + nextRow[i]) / 10000;
        carries.push_back(carry);
        finalResult.push_back(sum);
    }

    carries.erase(carries.begin());

    for (size_t i = 0; i < carries.size(); i++)
    {
        cout << carries[i] << ' ';
        finalResult[i] += carries[i];
    }

    cout << '\n';

    return finalResult;
}

int main()
{
    // vector<int> result = multiply(31415975, 8182818);
    vector<int> result = multiply(1234567, 9876543);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}

// 257 0712 0571 7550
