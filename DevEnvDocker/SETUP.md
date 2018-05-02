# Setup

1. Turn on swarm

    docker swarm init 

2.  Build the images.  Or don't; you can use eosio/eos from docker hub, but it's been 
unreliable occassionally.
    ( cd devBuilder ; docker build . -t eosio/localdev ; )
    ( docker build . -t eosio/eos ; )

3.  Now read README.md
