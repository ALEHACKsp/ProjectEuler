#include "stdafx.h"
#include "utils.h"
#include "Problem001to010/problems.h"
#include "Problem011to020/problems.h"
#include "Problem021to030/problems.h"
#include "Problem031to040/problems.h"
#include "Problem041to050/problems.h"
#include "Problem051to060/problems.h"
#include "Problem061to070/problems.h"

void OldProblems();

int wmain(int argc, wchar_t **argv)
{
    enum ExecMode
    {
        All,
        Latest,
    };

    ExecMode mode = ExecMode::All;

    if (argc >= 2)
    {
        if (::_wcsicmp(argv[1], L"latest") == 0)
            mode = ExecMode::Latest;
    }

    std::cout << Utils::GetCPUName() << std::endl;
    std::cout << std::endl;

    std::cout << "Preparing prime numbers <= " << Utils::PrimeMax << ": ";
    const auto &table = Utils::GetPrimeTable();

    std::cout << table.size() << " prime numbers." << std::endl;
    std::cout << std::endl;

    Utils::Solve(63, Problem63);
    std::cout << std::endl;

    if (mode == Latest)
        return 0;

    OldProblems();

    Utils::Solve(41, Problem41);
    Utils::Solve(42, Problem42);
    Utils::Solve(43, Problem43);
    Utils::Solve(44, Problem44);
    Utils::Solve(45, Problem45);
    Utils::Solve(46, Problem46);
    Utils::Solve(47, Problem47);
    Utils::Solve(48, Problem48);
    Utils::Solve(49, Problem49);
    Utils::Solve(50, Problem50);

    Utils::Solve(51, Problem51);
    Utils::Solve(52, Problem52);
    Utils::Solve(53, Problem53);
    Utils::Solve(54, Problem54);
    Utils::Solve(55, Problem55);
    Utils::Solve(56, Problem56);
    Utils::Solve(57, Problem57);
    Utils::Solve(58, Problem58);
    Utils::Solve(59, Problem59);
    Utils::Solve(60, Problem60);

    Utils::Solve(61, Problem61);
    Utils::Solve(62, Problem62);
    Utils::Solve(67, Problem67);

    return 0;
}

void OldProblems()
{
    Utils::Solve(1, Problem1);
    Utils::Solve(2, Problem2);
    Utils::Solve(3, Problem3);
    Utils::Solve(4, Problem4);
    Utils::Solve(5, Problem5);
    Utils::Solve(6, Problem6);
    Utils::Solve(7, Problem7);
    Utils::Solve(8, Problem8);
    Utils::Solve(9, Problem9);
    Utils::Solve(10, Problem10);

    Utils::Solve(11, Problem11);
    Utils::Solve(12, Problem12);
    Utils::Solve(13, Problem13);
    Utils::Solve(14, Problem14);
    Utils::Solve(15, Problem15);
    Utils::Solve(16, Problem16);
    Utils::Solve(17, Problem17);
    Utils::Solve(18, Problem18);
    Utils::Solve(19, Problem19);
    Utils::Solve(20, Problem20);

    Utils::Solve(21, Problem21);
    Utils::Solve(22, Problem22);
    Utils::Solve(23, Problem23);
    Utils::Solve(24, Problem24);
    Utils::Solve(25, Problem25);
    Utils::Solve(26, Problem26);
    Utils::Solve(27, Problem27);
    Utils::Solve(28, Problem28);
    Utils::Solve(29, Problem29);
    Utils::Solve(30, Problem30);

    Utils::Solve(31, Problem31);
    Utils::Solve(32, Problem32);
    Utils::Solve(33, Problem33);
    Utils::Solve(34, Problem34);
    Utils::Solve(35, Problem35);
    Utils::Solve(36, Problem36);
    Utils::Solve(37, Problem37);
    Utils::Solve(38, Problem38);
    Utils::Solve(39, Problem39);
    Utils::Solve(40, Problem40);
}
