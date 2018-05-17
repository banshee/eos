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

    // We want to sell gift cards.
    // Amazon
    // Alaska Airlines

    double currentDollarsAvailable;
    double maxIndividualPurchase;
    double eosExchangeRate; // EOS to dollars
    double ethExchangeRate; // ETH to dollars

    typedef std::string PurchaseOrderId;
    typedef std::string ProductId;
    typedef std::string PurchaseOrderItemId;
    typedef std::string CustomerId;
    typedef std::string SingleOrderId;

    /*
     * Customer goes to website.
     * Sees:
     *   Exchange rate for EOS -> Amazon gift certificate
     *   Maximum order size
     *
     *   S3 storage: Just to match a purchase ID with an email, don't need anything else
     *     purchaseId - GUID
     *     destinationEmailAddress
     *
     *   Product IDS:
     *     eosForAmazonGiftCertificates
     *     eosForAmericanExpressGiftCertificates
     *
     *   All data for purchase:
     *     purchaseId - GUID - transaction ID.  Generated on website, saved to S3
     *     destinationEmailAddress Saved to S3
     *     eosExchangeRate
     *     eosQuantity
     *     productQuantity
     *     purchaseAccepted
     *     purchaseDelivered
     *     purchaseRefunded
     *     purchaseRejected
     *
     *  EOS commands
     *    newExchangeRate currency dollarsPerUnit
     *    purchase purchaseId productId exchangeRate quantity
     *      - transfers money from their wallet to our wallet
     *      - the exchange rate has to be either the current or the previous exchange rate
     *    newStockLevel productId quantity - lets you set $10,000 worth of
     *    setMaximumSinglePurchaseSize currency quantity
     *    purchaseAccepted purchaseId
     *    purchaseCompleted purchaseId
     *    purchaseRejected purchaseId reasonCode
     */

    // Want to display:
    // Maximum purchase amount: (max of $5k or currentDollarsAvailable)

    //@abi action
    void newExchangeRate(
            account_name account,
            int currency,
            double dollarsPerUnit
    ) {
        print("newExchangeRate %d %d", currency, dollarsPerUnit);
    }

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
