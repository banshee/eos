# set env variables for some machines
dev=$(docker ps --filter label=com.docker.swarm.service.name=eos_dev --format="{{.ID}}")
node=$(docker ps --filter label=com.docker.swarm.service.name=eos_nodeosd --format="{{.ID}}")
keos=$(docker ps --filter label=com.docker.swarm.service.name=eos_keosd --format="{{.ID}}")
