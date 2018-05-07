. settings.sh
cleos $cleosOptions set contract james ~/git/eos/cmake-build-debug/contracts/jamestransfer
cleos $cleosOptions push action james hi '["user"]' -p james
