#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int offer_petr, step_petr, offer_driver, step_driver;
    std::cin >> offer_petr >> step_petr >> offer_driver >> step_driver;

//    while(offer_petr < offer_driver) {
//        offer_petr = std::min(offer_petr + step_petr, offer_driver);
//        offer_driver -= step_driver;
//    }
//    std::cout << offer_petr;


//    offer_petr + n_steps * step_petr >= offer_driver - n_steps * step_driver
//    n_steps (step_petr + step_driver) >= offer_driver - offer_petr
    int n_steps = (offer_driver - offer_petr + step_petr + step_driver - 1) / (step_petr + step_driver);
    int result;
    if (n_steps <= 0) {
        result = offer_petr;
    } else {
        result = std::min(offer_petr + n_steps * step_petr, offer_driver - (n_steps - 1) * step_driver);
    }
    std::cout << result;

    return 0;
}
