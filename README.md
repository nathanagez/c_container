# What is it ?

![docker_logo](https://avatars0.githubusercontent.com/u/5429470?s=200&v=4)

Hi! I'm a big fan of Docker and I always wanted to know how it worked under the box. So the best way to understand is by practice, this is why I decided to create my own little linux container.
You will see that we can create a simple isolated process with his own root filesystem and his own namespaces with only some lines of code :D 

![demo](https://raw.githubusercontent.com/NastyZ98/c_container/master/demo.gif)

# How it work ?
I started by create a child process using clone() with new namespaces, next I changed the root directory by giving a new rootfs (e.g: '/home/rootfs' in my case) and changed the actual directory by the root directory (e.g: '/').

# How to use ?
Because I work on macOS I use Docker to test my "container". Yes containerception.

BEFORE ALL DOWNLOAD THE ROOT FILESYSTEM:

`cd ./container && wget https://github.com/ericchiang/containers-from-scratch/releases/download/v0.1.0/rootfs.tar.gz`

Just run `./build.sh` and continue with `./run.sh`
It will create a container based on my Dockerfile and will copy the "container" folder containing sources and a compressed rootfs, next the archive will be decompressed into the container allowing you make and execute my program, thanks to `make`.

- ./build.sh
- ./run.sh
- make
- ./container
