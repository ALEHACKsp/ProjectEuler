#include "stdafx.h"
#include "utils.h"

namespace
{
    // -------------------------------------------------------------------------
    // Helper function for initializing the prime number table.

    std::vector<int64_t> InitializePrimeTable(int64_t n)
    {
        std::vector<int64_t> numbers;
        numbers.resize(n);

        // We never use [0] and [1], but they can make the code a bit clearer.

        numbers[2] = 2;

        for (size_t i = 3; i < numbers.size(); i += 2)
            numbers[i] = static_cast<int>(i);

        const size_t loopMax = static_cast<size_t>(std::sqrt(numbers.size()));
        for (size_t i = 3; i <= loopMax; ++i)
        {
            if (numbers[i] == 0)
                continue;

            for (size_t j = i * 2; j < numbers.size(); j += i)
                numbers[j] = 0;
        }

        std::vector<int64_t> primes;
        primes.reserve(numbers.size());

        std::copy_if(
            numbers.begin() + 2,
            numbers.end(),
            std::back_inserter(primes),
            [](int x) { return x > 0; });

        primes.shrink_to_fit();

        return primes;
    }
}

namespace Utils
{
    const std::vector<int64_t> & GetPrimeTable()
    {
        static const std::vector<int64_t> table = InitializePrimeTable(PrimeMax);

        return table;
    }

    std::string GetCPUName()
    {
        std::array<int, 4> info;
        ::__cpuid(info.data(), 0x80000000);

        if (static_cast<uint32_t>(info[0]) < 0x80000004U)
            return "Unknown CPU";

        std::vector<char> buf;
        buf.resize(49);

        ::__cpuid(info.data(), 0x80000002);
        ::memcpy(&buf[0], &info, sizeof(info));

        ::__cpuid(info.data(), 0x80000003);
        ::memcpy(&buf[16], &info, sizeof(info));

        ::__cpuid(info.data(), 0x80000004);
        ::memcpy(&buf[32], &info, sizeof(info));

        std::string name(buf.data());

        const size_t pos = name.find_first_not_of(" \r\n\t\v");
        if (pos != std::string::npos)
            name = name.substr(pos);

        return name;
    }

    template <typename T>
    T GetAverage(std::vector<T> &v)
    {
        assert(v.size() >= 3);

        v.erase(std::max_element(v.begin(), v.end()));
        v.erase(std::min_element(v.begin(), v.end()));

        auto sum = std::accumulate(v.begin(), v.end(), static_cast<T>(0));
        return sum / v.size();
    }

    void Solve(int number, const std::function<int64_t()> &solver)
    {
        using namespace std;

        cout << "Answer " << setw(2) << number << ": ";

        LARGE_INTEGER s1;
        ::QueryPerformanceCounter(&s1);

        unsigned int ui;
        const auto s2 = ::__rdtscp(&ui);

        const int64_t answer = solver();

        const uint64_t cycle = ::__rdtscp(&ui) - s2;

        LARGE_INTEGER e1;
        ::QueryPerformanceCounter(&e1);

        LARGE_INTEGER freq;
        ::QueryPerformanceFrequency(&freq);

        const double duration = (e1.QuadPart - s1.QuadPart) * 1000.0 / freq.QuadPart;

        cout << setw(12) << answer;
        cout << " (" << setw(10) << fixed << setprecision(4) << duration << " ms, ";
        cout << setw(12) << cycle << " cycles)";
        cout << endl;
    }
}
