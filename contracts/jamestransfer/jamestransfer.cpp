#include <boost/preprocessor/seq/for_each.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/serialize.hpp>
#include <eosiolib/dispatcher.hpp>
#include <set>
#include <iostream>
#include <tuple>
#include <map>
#include <string>

using namespace eosio;

class jamestransfer : public eosio::contract {
public:
    using contract::contract;

    ///@abi action
    void hi(account_name user) {
        print("Hello ", name{user});
    }

    ///@abi action
    void gimmie(account_name user) {
        print("Hellox ", name{user});
    }

    int fnord() {
        auto t = std::make_tuple(1, "x");
        auto x = std::get<0>(t);
        return x;
    }

    int *init();

    int test2() {
        int *x = init();
        int *y = init();
        (y = x, x) = nullptr; // <-- here

        return 0;
    }
};

EOSIO_ABI(jamestransfer, (hi)(gimmie))
