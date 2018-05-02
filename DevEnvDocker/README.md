# How to run a complete EOS dev environment in docker

## Read SETUP.md first

# Create the docker stack
    docker stack deploy -c docker-dev-env.yml eos

### you can use anything you want in place of "eos" - the name isn't important

# After the stack deploy, you'll have all the containers for the EOS service running.
# If you want a clean restart,
# stop all containers in the eos service.  The docker stack will restart new ones for you

    docker container stop $(docker ps -f label=com.docker.stack.namespace=eos --format="{{.ID}}")

# To take down the stack completely: 
    docker stack rm eos

# Now run the init.sh shell script to create some accounts.  init.sh will also
# create a settings.sh file containing some shell environment variables matching
# the current service.o

    ./init.sh
