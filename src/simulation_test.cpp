# include <bits/stdc++.h> // for M_PI
# include "Eigen/Dense"
# include "simulation.hpp"

using namespace simulation;
namespace eg = Eigen;

int main(int argc, char const *argv[])
{
    /* 波長以外すべてmm単位 */
    constexpr float wavelength_nm = 632.8; // nm
    constexpr float k = 2 * M_PI / (wavelength_nm * 1e-6);
    constexpr float r = 400; // スクリーンとの距離
    constexpr float r0 = 10; // 円の半径
    constexpr float screen_range = 0.5; // スクリーンの幅/2
    const eg::VectorXf range_flt = eg::VectorXf::LinSpaced(100, -r0, r0);
    const eg::VectorXf range_sc = eg::VectorXf::LinSpaced(100, -screen_range, screen_range);

    // std::cout << range_flt.size() << std::endl;
    // std::cout << range_sc << std::endl;
    std::cout << "wavelength: " << wavelength_nm << " R: " << r << " r0: " << r0 << " LinSpaced num: " 
        << "100 100" << std::endl;

    eg::MatrixXf grr;
    simulate(grr, circle, range_flt, range_sc, r, k, r0);
    std::cout << grr << std::endl;
    

    return 0;
}
