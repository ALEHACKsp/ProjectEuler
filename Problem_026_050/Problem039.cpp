#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

namespace
{
    int64_t gcd(int64_t a, int64_t b)
    {
        while (a % b != 0)
        {
            a = a % b;
            swap(a, b);
        }

        return b;
    }
}

int64_t Problem39()
{
    const int32_t Limit = 1000;
    const int32_t MaxI  = static_cast<int32_t>(sqrt(Limit / 2.0 - 0.25) - 0.5);

    vector<int32_t> counts(Limit + 1);

    for (int32_t i = 1; i <= MaxI; ++i)
    {
        const int32_t maxJ = min(i - 1, Limit / (2 * i) - i);

        for (int32_t j = 1 + (i & 1); j <= maxJ; j += 2)
        {
            if (gcd(i, j) != 1)
                continue;

            const int32_t p = 2 * (i * i + i * j);

            for (int32_t k = p; k <= Limit; k += p)
                counts[k]++;
        }
    }

    return (max_element(counts.begin(), counts.end()) - counts.begin());
}
