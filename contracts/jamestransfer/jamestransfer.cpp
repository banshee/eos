#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/serialize.hpp>
#include <eosiolib/dispatcher.hpp>

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
};

EOSIO_ABI(jamestransfer, (hi)(gimmie))
