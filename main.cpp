#include "stdafx.h"
#include "utils.h"
#include "Problem001to010/problems.h"
#include "Problem011to020/problems.h"

int main()
{
    std::cout << Utils::GetCPUName() << std::endl;
    std::cout << std::endl;

    std::cout << "Preparing prime numbers <= " << Utils::PrimeMax << ": ";
    const auto &table = Utils::GetPrimeTable();

    std::cout << table.size() << " prime numbers." << std::endl;
    std::cout << std::endl;

    Utils::Solve<int64_t>(20, [] { return Problem20(); });

    Utils::Solve<int64_t>( 1, [] { return Problem1(); });
    Utils::Solve<int64_t>( 2, [] { return Problem2(); });
    Utils::Solve<int64_t>( 3, [] { return Problem3(); });
    Utils::Solve<int64_t>( 4, [] { return Problem4(); });
    Utils::Solve<int64_t>( 5, [] { return Problem5(); });
    Utils::Solve<int64_t>( 6, [] { return Problem6(); });
    Utils::Solve<int64_t>( 7, [] { return Problem7(); });
    Utils::Solve<int64_t>( 8, [] { return Problem8(); });
    Utils::Solve<int64_t>( 9, [] { return Problem9(); });
    Utils::Solve<int64_t>(10, [] { return Problem10(); });

    Utils::Solve<int64_t>(11, [] { return Problem11(); });
    Utils::Solve<int64_t>(12, [] { return Problem12(); });
    Utils::Solve<std::string>(13, [] { return Problem13(); });
    Utils::Solve<int64_t>(14, [] { return Problem14(); });
    Utils::Solve<int64_t>(15, [] { return Problem15(); });
    Utils::Solve<int64_t>(16, [] { return Problem16(); });
    Utils::Solve<int64_t>(17, [] { return Problem17(); });
    Utils::Solve<int64_t>(19, [] { return Problem19(); });

    return 0;
}
