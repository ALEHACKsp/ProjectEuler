#include "stdafx.h"
#include "utils.h"

std::string Problem24()
{
    int64_t num = 999999;

    std::vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::string answer;

    for (int i = 9; i >= 0; --i)
    {
        const int64_t f = Utils::GetFactorial<int64_t>(i);
        const int64_t d = num / f;

        answer.push_back(digits[d]);
        digits.erase(digits.begin() + d);

        num -= (f * d);
    }

    return answer;
}
