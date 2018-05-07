eosdir=${1:-..}

# Set variables for these machines:
#
#   nodeos - runs the EOS server
#   keos - runs the wallet server

nodeos=$(docker ps --filter label=com.docker.swarm.service.name=eos_nodeosd --format="{{.ID}}")
keos=$(docker ps --filter label=com.docker.swarm.service.name=eos_keosd --format="{{.ID}}")

# store the options we pass to cleos
cleosOptions="--url http://localhost:8870 --wallet-url http://localhost:8899"

# Note that the wallet is available on
# host port 8899, nodeos is on 8870.  Those ports are changed by editing docker-dev-env.yaml.

# create a wallet called default.

wallet=$(cleos $cleosOptions wallet create | tail -1)

# create some keys

cleos create key > keys.txt
private=$(cat keys.txt | grep Priv | cut -d: -f 2 | head)
public=$(cat keys.txt | grep Pub | cut -d: -f 2 | head)

echo

echo wallet key: $wallet
echo private key: $private
echo public key: $public

echo

# Now we need to get those keys into the wallet

cleos $cleosOptions wallet import $private

echo

# Useful wallet commands:
#
# cleos $cleosOptions wallet list 
# cleos $cleosOptions wallet keys 

# now we need an account (or more than one)

cleos $cleosOptions create account eosio eosio.token $public $public
cleos $cleosOptions create account eosio eosio.msig $public $public
cleos $cleosOptions create account eosio james $public $public

echo > settings.sh
for i in public private wallet nodeos cleosOptions; do
  echo $i=\"$(eval echo \$$i)\" >> settings.sh
done

cleos $cleosOptions set contract eosio.msig $eosdir/build/contracts/eosio.msig -p eosio.msig
cleos $cleosOptions set contract eosio $eosdir/build/contracts/eosio.bios -p eosio
cleos $cleosOptions set contract eosio $eosdir/build/contracts/eosio.token -p eosio
cleos $cleosOptions push action eosio.token create '{"issuer":"eosio", "maximum_supply":"1000000000.0000 EOS", "can_freeze":0, "can_recall":0, "can_whitelist":0}' -p eosio.token -d -j

echo
echo consider runnning:
echo "docker container logs $nodeos 2>&1 | grep -v producer_plugin.cpp | less"
