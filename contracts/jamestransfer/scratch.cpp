//    enum PurchaseOrderState {
//        SUBMITTED, ACCEPTED, PAID, SHIPPED, REFUNDED, PAUSED
//    };
//
//    class Customer {
//        CustomerId customerId;
//        std::string emailAddress;
//    };
//
//    class SingleItemOrder {
//        CustomerId customerId;
//        ProductId productId;
//        double price;
//        double
//    };
//
//    class PurchaseOrder {
//        CustomerId customerId;
//        PurchaseOrderId purchaseOrderId;
//        std::string timestamp;
//    };
//
//    // Things that are recorded on the blockchain are named
//    // SomethingLedgerEntry
//
//    struct PurchaseOrderItem {
//        PurchaseOrderItemId purchaseOrderItemId;
//        ProductId productId;
//        double quantity;
//        double price;
//        std::string timestamp;
//    };
//
//    struct PurchaseConfirmation {
//        bool paid;
//        PurchaseOrderId purchaseOrderId;
//    };
//
